#include <bits/stdc++.h>
#define maxn 200010
using namespace std;
typedef long long LL;
int s[maxn], g[maxn], e[maxn], ans[maxn], st[maxn], ed[maxn];
LL res;
int main() {
	//freopen("road.in", "r", stdin);
	//freopen("road.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d%d", &s[i], &g[i]), e[i] = s[i] + g[i];
    st[0] = s[0], ed[0] = e[0];
    for (int i = 1; i < n; ++i) {
        st[i] = max(st[i-1]-1, s[i]);
        ed[i] = min(ed[i-1]+1, e[i]);
        if (st[i] > ed[i]) { puts("-1"); return 0; }
    }

    LL res=ed[n-1]-s[n-1];
    ans[n-1] = ed[n-1];
    for (int i = n-2; i >= 0; --i) {
        if (ans[i+1] + 1 <= ed[i]) ans[i] = ans[i+1] + 1;
        else if (ans[i+1] <= ed[i]) ans[i] = ans[i+1];
        else ans[i] = ans[i+1] - 1;
        res += ans[i]-s[i];
    }
    printf("%I64d\n%d", res, ans[0]);
    for (int i = 1; i < n; ++i) printf(" %d", ans[i]); printf("\n");
    return 0;
}