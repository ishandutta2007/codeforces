#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define L first
#define R second
#define W L.L
#define U L.R
#define V R
#define MYP(u, v, w) MP(MP(w, u), v)

typedef pair<pair<int, int>, int> myp;

const int maxn = 3e5 + 10;
int dp[maxn], dp2[maxn], ene[maxn];
myp e[maxn];
int n, m;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 0; i < m; i++)
		cin >> e[i].U >> e[i].V >> e[i].W;
	sort(e, e + m);
	for(int i = 0; i < m; i++){
		int v = e[i].V,
			u = e[i].U,
			w = e[i].W;
		if(dp[u] + 1 > dp[v] and ene[u] < w){
			if(ene[v] != w) dp2[v] = dp[v];
			dp[v] = dp[u] + 1;
			ene[v] = w;
		}
		if(ene[u] == w){
			if(dp2[u] + 1 > dp[v]){
				if(ene[v] != w) dp2[v] = dp[v];
				dp[v] = dp2[u] + 1;
				ene[v] = w;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
		ans = max(ans, dp[i]);
	cout << ans << endl;
	return 0;
}