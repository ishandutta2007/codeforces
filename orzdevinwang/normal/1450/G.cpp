#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db long double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 5007;
const int M = 1048576;
const int inf = 1e9 + 7;
int n, a, b, tot, ptot, L[N], R[N], CNT[N];
int bh[26], lef[M], rig[M], cnt[M];
bool dp[M];
char s[N], ans[26], dy[26];
int main() {
	scanf("%d%d%d", &n, &a, &b);
	scanf("%s", s + 1);
	L(i, 1, n) {
		if(!bh[s[i] - 'a']) bh[s[i] - 'a'] = ++tot, dy[tot] = s[i], L[tot] = i; 
		R[bh[s[i] - 'a']] = i, CNT[bh[s[i] - 'a']] ++;
	}
	dp[0] = 1;
	L(i, 1, (1 << tot) - 1) {
		int now = 0;
		lef[i] = inf;
		L(j, 1, tot) if((1 << (j - 1)) & i) {
			lef[i] = min(lef[i], L[j]), rig[i] = max(rig[i], R[j]), cnt[i] += CNT[j], now ^= 1 << (j - 1);
			if(dp[now] && dp[i ^ now]) dp[i] = 1;
		}
		// cout << i << " : " << lef[i] << " " << rig[i] << " " << cnt[i] << "\n";
		if(cnt[i] * b >= (rig[i] - lef[i] + 1) * a) L(j, 1, tot) if((1 << (j - 1)) & i) if(dp[(1 << (j - 1)) ^ i]) dp[i] = 1;
		// cout << "dp[" << i << "] = " << dp[i] << endl; 
	}
	L(j, 1, tot) if(dp[((1 << tot) - 1) ^ (1 << (j - 1))]) ans[++ptot] = dy[j];
	sort(ans + 1, ans + ptot + 1);
	printf("%d ", ptot);
	L(i, 1, ptot) printf("%c ", ans[i]);
	puts("");
	return 0;
}