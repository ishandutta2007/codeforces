#include <bits/stdc++.h>
#define f first
#define s second
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fll
using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
const int SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);

//Do not forget to check if there exists an eulerian path/cycle before calling dfs
struct EulerianPath{
	vector<vector<tuple<int, int, bool>>> E;
	vector<int> tour;
	EulerianPath(int n): E(n){}
	void addEdge(int u, int v){
		int p1 = E[u].size(), p2 = E[v].size();
		E[u].emplace_back(v, p2, 0);
		E[v].emplace_back(u, p1, 0);
	}	
	void dfs(int u){
		while(!E[u].empty()){
			auto [v, rev, used] = E[u].back();
			E[u].pop_back();
			if(!used){
				get<2>(E[v][rev]) = 1;
				dfs(v);
			}
		}
		tour.push_back(u);
	}
};

void test_case(){
	int n, ans = 0;
	cin >> n;
	vector<int> a(2*n), p(2*n);
	iota(p.begin(), p.end(), 0);
	for(auto &x: a)cin >> x;
	for(int i = 20; i; i--){
		for(auto &x: a) x &= (1<<i)-1;
		EulerianPath euler(1<<i);
		vector<tuple<int, int, int>> v1, v2;
		for(int j = 0; j < n; j++){
			euler.addEdge(a[j*2], a[j*2+1]);
			v1.emplace_back(min(a[j*2], a[j*2+1]), max(a[j*2], a[j*2+1]), j);
		}
		bool ok = true;
		for(int j = 0; j < (1<<i); j++)
			if(euler.E[j].size()%2)ok = false;
		if(!ok)continue;
		euler.dfs(a[0]);
		vector<int> tour = euler.tour;
		if(tour.size() != n+1)continue;
		ans = i;
		for(int j = 0; j < n; j++)
			v2.emplace_back(min(tour[j], tour[j+1]), max(tour[j], tour[j+1]), j);
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		for(int j = 0; j < n; j++){
			auto [x1, y1, r] = v1[j]; 
			auto [x2, y2, pos] = v2[j];
			if(a[r*2] != tour[pos]){
				p[pos*2] = r*2+1;
				p[pos*2+1] = r*2;
			}
			else{
				p[pos*2] = r*2;
				p[pos*2+1] = r*2+1;
			}
		}
		break;
	}
	cout << ans << endl;
	for(auto x: p)cout << x+1 << " ";
	cout << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	int t = 1;
	//cin >> t;
	for(int i = 1; i <= t; i++){
		//cout << "Case #"<< i << ":" << endl;
		test_case();
	}
	return 0;
}