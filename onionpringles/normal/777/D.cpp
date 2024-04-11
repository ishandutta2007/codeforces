#pragma warning(disable:4996)

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <complex>
#include <iterator>
#include <random>
#include <time.h>
#include <tuple>
#include <functional>
#include <list>
#include <limits.h>
#define mp make_pair
#define ni(x) scanf("%d", &(x))
#define nii(x,y) scanf("%d%d",&(x),&(y))
#define mul(x,y) ((ll)(x)*(y)%mod)
#define mtp make_tuple
#define F(i,n) for(int i = 0; i < (n); i++)
#define FF(i,n) for(int i = 1; i <= (n); i++)
#define FE(i,n) for(int i = 0; i <= (n); i++)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const ll infl = 9012345678901234567;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

pair<int, int> tp[500000];
string s[500000];
char b[500002];
vector<int> dp[500000];
vector<int> pre[500000];
vector<int> par[500000];
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n; ni(n);
	F(i, n) {
		scanf("%s", b);
		s[i] = string(b + 1);
	}
	F(i, n - 1) {
		int sz = min(s[i].size(), s[i + 1].size());
		FE(j, sz) {
			if (s[i][j] < s[i + 1][j]) {
				tp[i] = { 1,j }; break;
			}
			else if (s[i][j] >s[i + 1][j]) {
				tp[i] = { -1,j }; break;
			}
		}
		//printf("%d %d\n", tp[i].first, tp[i].second);
	}
	{
		int sz = s[0].size();
		FE(i, sz) {
			dp[0].push_back(sz - i);
		}
		pre[0].resize(sz + 1);
		pre[0][0] = 0;
		par[0].resize(sz + 1);
		FF(i, sz)pre[0][i] = (dp[0][pre[0][i - 1]] < dp[0][i]) ? pre[0][i - 1] : i;
	}
	FF(i, n - 1) {
		int psz = s[i - 1].size();
		int sz = s[i].size();
		dp[i].resize(sz + 1);
		par[i].resize(sz + 1);
		if (tp[i - 1].first == -1) {
			int j = tp[i - 1].second;
			for (int t = sz; t > j; t--) {
				dp[i][t] = dp[i-1][pre[i - 1][j]] + sz - t;
				par[i][t] = pre[i - 1][j];
			}
			for (int t = j; t >= 0; t--) {
				dp[i][t] = dp[i - 1][pre[i - 1][t]] + sz - t;
				par[i][t] = pre[i - 1][t];
			}
		}
		else if (tp[i - 1].first == 1) {
			int j = tp[i - 1].second;
			for (int t = sz; t > j; t--) {
				dp[i][t] = dp[i-1][pre[i - 1][psz]] + sz - t;
				par[i][t] = pre[i - 1][psz];
			}
			for (int t = j; t >= 0; t--) {
				dp[i][t] = dp[i-1][pre[i - 1][t]] + sz - t;
				par[i][t] = pre[i - 1][t];
			}
		}
		else {
			for (int t = 0; t <= sz; t++) {
				dp[i][t] = dp[i-1][pre[i - 1][t]] + sz - t;
				par[i][t] = pre[i - 1][t];
			}
		}
		pre[i].resize(sz + 1);
		pre[i][0] = 0;
		FF(t, sz)pre[i][t] = (dp[i][pre[i][t - 1]] < dp[i][t]) ? pre[i][t - 1] : t;
		//FE(t, sz)printf("(%d %d %d) ", dp[i][t], pre[i][t], par[i][t]); puts("");
	}
	vector<int> V;
	int j = pre[n - 1][s[n - 1].size()];
	for (int i = n - 1; i >= 0; i--) {
		V.push_back(j);
		j = par[i][j];
	}
	for (int i = n - 1; i >= 0; i--) {
		s[n - 1 - i].resize(V[i]);
		printf("#%s\n", s[n - 1 - i].c_str());
	}
	return 0;
}