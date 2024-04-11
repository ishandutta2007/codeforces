#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 2e5 + 7;
int n, a[N], dp[N][3], arr[N], siz[N], fir[N], las[N], pp[N], tot;
void Main() {
	scanf("%d", &n);
	L(i, 1, n) scanf("%d", &a[i]), arr[++tot] = a[i];
	sort(arr + 1, arr + tot + 1);
	tot = unique(arr + 1, arr + tot + 1) - arr - 1;
	L(i, 1, n) {
		a[i] = lower_bound(arr + 1, arr + tot + 1, a[i]) - arr;
		if(!fir[a[i]]) fir[a[i]] = i;
		las[a[i]] = i, siz[a[i]]++;
	}
	int ans = 0;
	L(i, 1, n) {
		dp[i][0] = dp[pp[a[i]]][0] + 1;
		dp[i][1] = max(max(dp[pp[a[i] - 1]][0], dp[pp[a[i] - 1]][2]), dp[pp[a[i]]][1]) + 1;
		if(i == las[a[i]]) dp[i][2] = max(dp[fir[a[i]]][0], dp[fir[a[i]]][1]) + siz[a[i]] - 1;
		ans = max(ans, dp[i][0]), ans = max(ans, dp[i][1]), ans = max(ans, dp[i][2]);
		pp[a[i]] = i;
	}
	printf("%d\n", n - ans);
	tot = 0;
	L(i, 1, n) las[i] = fir[i] = siz[i] = pp[i] = dp[i][0] = dp[i][1] = dp[i][2] = 0;
}
int main() {
	int T; scanf("%d", &T);
	while(T--) Main();
	return 0;
}