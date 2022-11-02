#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
#define inf (1LL << 60)

#define dbg(a) (cout << #a << ": " << (a) << endl);
#define dbg2(a, b) (cout << #a << ": " << (a) << ", " << #b << ": " << (b) << endl);
#define dbg3(a, b, c) (cout << #a << ": " << (a) << ", " << #b << ": " << (b) << ", " << #c << ": " << (c) << endl);
#define dbg4(a, b, c, d) (cout << #a << ": " << (a) << ", " << #b << ": " << (b) << ", " << #c << ": " << (c) << ", " << #d << ": " << (d) << endl);
#define dbg5(a, b, c, d, e) (cout << #a << ": " << (a) << ", " << #b << ": " << (b) << ", " << #c << ": " << (c) << ", " << #d << ": " << (d) << ", " << #e << ": " << (e) << endl);

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int randint(int a, int b){return a + rng() % (b - a);}

using namespace std;

template<class T>
void print(vector<T> v){
	for(auto i : v){
		cout << i << ' ';
	}
	cout << endl;
}

const int mod = 1e9 + 7;

int dp[2001];
int p[2001];
vector<pair<int, int>> vi;

bool called[2001];
int r[2001];

int li[2001];

set<pair<int, int>> E;
void add(int u, int v){
	if(u > v) swap(u, v);
	E.insert({u + 1, v + 1});
}

void solve(){
	int n;
	cin >> n;
	if(n == 2){
		cout << "!" << '\n';
		cout << "1 2" << endl;
		return;
	}
	
	cout << "? 1" << endl;
	for(int i = 0; i < n; i++){
		cin >> dp[i];
	}
	for(int i = 0; i < n; i++){
		vi.push_back({dp[i], i});
	}
	sort(vi.begin(), vi.end(), [](pair<int, int> a, pair<int, int> b){
		return a.first > b.first;
	});
	
	called[0] = true;
	for(auto i : vi){
		int v = i.se, dep = i.fi;
		if(dep <= 1){
			if(dep == 1){
				add(v, 0);
			}
			continue;
		}
		if(called[v]) continue;
		cout << "? " << v + 1 << endl;
		vector<pair<int, int>> due;
		for(int i = 0; i < n; i++){
			cin >> r[i]; 
			if(dp[i] + r[i] == dp[v]){
				li[dp[i]] = i;
			}else{
				int dep_ = dp[i] - (dp[i] + dp[v] - r[i]) / 2;
				int dis = (dp[i] + dp[v] - r[i]) / 2;
				if(dep_ == 1){
					due.push_back({dis, i});
					called[i] = true;
				}
			}
		}
		for(int i = 0; i < dp[v]; i++){
			called[li[i + 1]] = true;
			add(li[i], li[i + 1]);
		}
		for(auto i : due){
			add(li[i.fi], i.se);
		}
	}
	cout << "!" << endl;
	for(auto i : E){
		cout << i.fi << ' ' << i.se << '\n';
	}
	cout << endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	int t = 1;
	while(t--){
		solve();
	}
}