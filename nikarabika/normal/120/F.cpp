//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

//man am A _____ & a pair of Izzz wayTn' 230u :)

typedef pair<int, int> pii;

#undef cin
#undef cout
#define cin fin
#define cout fout

#define smax(x, y) (x) = max((x), (y))
#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = 110;
vector<int> adj[maxn];
int n;

ifstream cin("input.txt");
ofstream cout("output.txt");

pii find_farest(int v, int p = -1, int len = 0){
	pii ret = {len, v};
	for(auto u : adj[v])
		if(u != p)
			smax(ret, find_farest(u, v, len + 1));
	return ret;
}

int solve(){
	cin >> n;
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	int ret = find_farest(find_farest(1).R).L;
	for(int i = 1; i <= n; i++)
		adj[i].clear();
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t, ans = 0;
	cin >> t;
	while(t--)
		ans += solve();
	cout << ans << endl;
	return 0;
}