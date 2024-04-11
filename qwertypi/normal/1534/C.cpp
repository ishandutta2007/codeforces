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
int A[400002][2];
int M[400002];
vector<vector<int>> G(400002);
bool visited[400002];

void dfs(int v, int p = -1){
	visited[v] = true;
	for(auto i : G[v]){
		if(!visited[i]){
			dfs(i, v);
		}
	}
}

void solve(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		G[i].clear();
	}
	for(int i = 0; i < n; i++){
		cin >> A[i][0];
	}
	for(int i = 0; i < n; i++){
		cin >> A[i][1];
	}
	
	for(int i = 0; i < n; i++){
		G[A[i][1]].push_back(A[i][0]);
		G[A[i][0]].push_back(A[i][1]);
	}
	fill(visited, visited + n + 1, 0);
	
	int ans = 1;
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			ans = (ans * 2) % mod;
			dfs(i);
		}
	}
	cout << ans << endl;
	
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}