#include<bits/stdc++.h>
#define N 511
#define xx 1919810
#define mod 1000000007
#define ll long long
using namespace std;
int gans(int x) {
	return x <= 0 ? 0 : (x - 1) / 2 + 1;
}
int manacher(int *f, int len) {
    int qans[N], maxr = 0, mid = 0, Ans = 1;
	int q[N];
	for(int i = 0; i < len; i++) {
		q[i << 1] = f[i];
		q[i << 1 | 1] = 114514;
	}
    len <<= 1, qans[0] = 1;
	q[len] = 114514;
	for(int i = 1; i < len; i++) {
		if(maxr > i) if(qans[mid * 2 - i] + i < maxr) {
				qans[i] = qans[mid * 2 - i];
				int t = qans[i] + (q[qans[i] + i] != 114514);
				if(t > 0) Ans = Ans + gans(t);
				continue;
			}
		maxr = max(maxr, i);
		while(i * 2 - maxr != 0 && maxr != len) {
			if(q[2 * i - maxr] != q[maxr]) break;
			++maxr;
		}
		if(q[2 * i - maxr] != q[maxr]) --maxr;
		qans[i] = maxr - i, mid = i;
		int t = qans[i] + (q[maxr] != 114514);
		Ans = Ans + gans(t);
	}
    return Ans;
}
int n, m, s[N][N], has[N], cn[N], flag[N], dd[N], p[N][27];
char a[N][N];
int cnt[N];
ll ans;
int main() {
    scanf("%d%d", &n, &m);
    dd[1] = 1;
    for(int i = 2; i <= 26; i++) dd[i] = 1ll * dd[i - 1] * xx % mod;
    for(int i = 1; i <= n; i++) scanf("%s", a[i] + 1);
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) s[i][j] = a[i][j] - 'a' + 1;
    for(int i = 1; i <= m; i++) {
        for(int k = 1; k <= n; k++) has[k] = cn[k] = 0;
        for(int k = 1; k <= n; k++) for(int j = 1; j <= 26; j++) p[k][j] = 0;
        for(int j = i; j <= m; j++) {
            for(int k = 1; k <= n; k++) 
                (has[k] += dd[s[k][j]]) %= mod, (p[k][s[k][j]] += 1) &= 1, 
                cn[k] += (p[k][s[k][j]] == 1 ? 1 : -1), flag[k] = (cn[k] <= 1);
            int now = -1;
            for(int k = 1; k <= n + 1; k++) {
                if(!flag[k]) {
                    if(now == -1) continue;
                    else ans += manacher(has + now, k - now), now = -1;
                }
                else now = (now == -1 ? k : now);
            }
            if(now != -1) ans += manacher(has + now, n - now + 1);
        }
    }
    printf("%lld\n", ans);
    return 0;
}