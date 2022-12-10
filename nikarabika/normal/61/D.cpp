#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define L first
#define R second

typedef long long int LL;
typedef pair<LL, LL> pie;

const int maxn = 1e5 + 85 - 75;
vector<pie> v[maxn];
LL n, sum;
bool mark[maxn];

LL dfs(int x, int p = -1){
	mark[x] = true;
	LL dp = 0;
	for(auto adj : v[x])
		if(adj.L != p)
			dp = max(dp, dfs(adj.L, x) + adj.R);
	return dp;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++){
		int fi, se, th;
		cin >> fi >> se >> th;
		v[fi].PB(MP(se, th));
		v[se].PB(MP(fi, th));
		sum += th;
	}
	cout << sum * 2 - dfs(1) << endl;
	return 0;
}