//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 500 + 10;
int dp[maxn][maxn], a[maxn];
bool filled[maxn][maxn];
int n;

int DP(int st, int en){
	if(filled[st][en])
		return dp[st][en];
	filled[st][en] = true;
	if(en - st == -1)
		return dp[st][en] = 0;
	if(en - st == 0)
		return dp[st][en] = 1;
	if(en - st == 1)
		return dp[st][en] = 1 + (a[st] != a[en]);
	dp[st][en] = 1 + DP(st + 1, en);
	if(a[st] == a[st + 1])
		smin(dp[st][en], 1 + DP(st + 2, en));
	for(int i = st + 2; i <= en; i++)
		if(a[i] == a[st])
			smin(dp[st][en], DP(st + 1, i - 1) + DP(i + 1, en));
	return DP(st, en);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	cout << DP(0, n - 1) << endl;
	return 0;
}