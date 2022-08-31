#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long
const int N = 1e5 + 7;
int n, m, c[N], v[N], a, b;
ll ans[N];
int maxn, cmaxn;
int main() {
    scanf("%d%d", &n, &m);
    L(i, 1, n) scanf("%d", &v[i]);
    L(i, 1, n) scanf("%d", &c[i]);
    while(m--) {
        ll Ans = 0;
        maxn = cmaxn = 0;
        L(i, 0, n) ans[i] = -1e16;
        scanf("%d%d", &a, &b);
        L(i, 1, n) {
            ll now = 1ll * v[i] * b;
            now = max(now, ans[c[i]] + 1ll * v[i] * a);
            if(maxn == c[i]) now = max(now, ans[cmaxn] + 1ll * v[i] * b);
            else now = max(now, ans[maxn] + 1ll * v[i] * b);
            Ans = max(Ans, now);
            ans[c[i]] = max(ans[c[i]], now);
            if(maxn == c[i]) continue;
            if(ans[c[i]] > ans[maxn]) cmaxn = maxn, maxn = c[i];
            else if(ans[c[i]] > ans[cmaxn]) cmaxn = c[i];
        }
        printf("%lld\n", Ans);
    }
	return 0;
}