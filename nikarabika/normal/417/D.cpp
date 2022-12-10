#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define smin(x, y) (x) = min((x), (y))

const int maxn = 100, maxm = 20;
const LL INF = 2LL * 100000 * 100000 * 100000 * 1000;
int order[maxn], abil[maxn];
LL dp[1 << maxm], k[maxn], x[maxn];
LL n, m, b;

bool cmp(int i, int j){
	return k[i] < k[j];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> b;
	for(int i = 0; i < n; i++){
		int cnt;
		cin >> x[i] >> k[i] >> cnt;
		for(int j = 0; j < cnt; j++){
			int fi;
			cin >> fi;
			abil[i] |= (1 << (fi - 1));
		}
		order[i] = i;
	}
	sort(order, order + n, cmp);
	fill(dp, dp + (1 << m), INF);
	dp[0] = 0;
	LL ans = INF;
	for(int i = 0; i < n; i++){
		int pers = order[i];
		for(int mask = (1 << m) - 1; mask >= 0; mask--)
			smin(dp[mask], dp[mask & (((1 << m) - 1) - abil[pers])] + x[pers]);
		smin(ans, dp[(1 << m) - 1] + b * k[pers]);
	}
	cout << (ans < INF ? ans : -1) << endl;
	return 0;
}