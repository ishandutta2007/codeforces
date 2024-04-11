#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define vL1(x) ((x) - L1[x] + 1)
#define vR1(x) (R1[x] - (x) + 1)
#define vL2(x) ((x) - L2[x] + 1)
#define vR2(x) (R2[x] - (x) + 1)

using namespace std;
const int N = 1e5 + 5;
int n, p[N], L1[N], R1[N], L2[N], R2[N];
int pre[N], suf[N];
int chk(int x) {
	if(L1[x] == x || R1[x] == x) return 1;
	if(max(pre[L1[x] - 1], suf[R1[x] + 1]) >= max(vL1(x), vR1(x))) return 1;
	if(L1[x] < x) {
		if((L1[x] - x) & 1) {
			if(max(vL2(L1[x]), vR2(L1[x])) >= vR1(x)) return 1;
		} else {
			if(vL2(L1[x]) >= max(vL1(x), vR1(x))) return 1;
			if(L1[x] + 1 < x && vR2(L1[x] + 1) >= vR1(x)) return 1;
		}
	}
	if(R1[x] > x) {
		if((R1[x] - x) & 1) {
			if(max(vL2(L1[x]), vR2(L1[x])) >= vL1(x)) return 1;
		} else {
			if(vR2(R1[x]) >= max(vL1(x), vR1(x))) return 1;
			if(R1[x] - 1 > x && vL2(R1[x] - 1) >= vL1(x)) return 1;
		}
	}
	return 0;
}
int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	cin >> n;
	rep(i, 1, n) scanf("%d", &p[i]);
	L1[1] = L2[1] = 1, R1[n] = R2[n] = n;
	rep(i, 2, n) if(p[i - 1] < p[i]) L1[i] = L1[i - 1], L2[i] = i;
	else L2[i] = L2[i - 1], L1[i] = i;
	per(i, n - 1, 1) if(p[i + 1] < p[i]) R1[i] = R1[i + 1], R2[i] = i;
	else R2[i] = R2[i + 1], R1[i] = i;
	rep(i, 1, n) pre[i] = max(pre[i - 1], max(vL2(i), vR2(i)));
	per(i, n, 1) suf[i] = max(suf[i + 1], max(vL2(i), vR2(i)));
	int ans = 0;
	rep(i, 1, n) ans += !chk(i);
	cout << ans;
	return 0;
}