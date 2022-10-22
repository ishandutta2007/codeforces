#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

const int N = 2e5 + 5;

int n, q, a[N], L[N], R[N], t[N], st[18][N], mi[18][N], ma[18][N];

int ch(int a, int b) {
    return L[a] > L[b] ? a : b;
}
int cmi(int x, int y) {
    return a[x] < a[y] ? x : y;
}
int cma(int x, int y) {
    return a[x] > a[y] ? x : y;
}
int main() {
#ifdef local
	freopen(".in", "r", stdin);
#endif
    cin >> n >> q;
    rep(i, 1, n) scanf("%d", &a[i]);
    rep(i, 1, n) for(int& j = L[i] = i - 1; j && a[j] >= a[i]; j = L[j]);
    rep(i, 1, n) t[i] = L[i];
    rep(i, 1, n) for(int& j = L[i] = i - 1; j && a[j] <= a[i]; j = L[j]);
    rep(i, 1, n) L[i] = min(L[i], t[i]) - 1;
    per(i, n, 1) for(int& j = R[i] = i + 1; j <= n && a[j] >= a[i]; j = R[j]);
    rep(i, 1, n) t[i] = R[i];
    per(i, n, 1) for(int& j = R[i] = i + 1; j <= n && a[j] <= a[i]; j = R[j]);
    rep(i, 1, n) st[0][i] = max(R[i], t[i]) + 1;
    rep(i, 1, 17) rep(j, 1 << i, n) st[i][j] = min(st[i - 1][j], st[i - 1][j - (1 << i - 1)]);
    rep(i, 1, n) {
        int& j = L[i];
        per(k, 17, 0) if(j - (1 << k) >= 0 && st[k][j] > i) j -= 1 << k;
    }
    R[n] = n;
    per(i, n - 1, 1) R[i] = a[i + 1] >= a[i] ? R[i + 1] : i;
    rep(i, 1, n) t[i] = R[i];
    per(i, n - 1, 1) R[i] = a[i + 1] <= a[i] ? R[i + 1] : i;
    rep(i, 1, n) R[i] = max(R[i], t[i]);
    rep(i, 1, n) t[i] = ch(t[i - 1], i);
    rep(i, 1, n) mi[0][i] = ma[0][i] = i;
    rep(i, 1, 17) rep(j, 1, n - (1 << i) + 1) {
        mi[i][j] = cmi(mi[i - 1][j], mi[i - 1][j + (1 << i - 1)]);
        ma[i][j] = cma(ma[i - 1][j], ma[i - 1][j + (1 << i - 1)]);
    }
    int l, r;
    rep(kase, 1, q) {
        scanf("%d%d", &l, &r);
        if(R[l] >= r) puts("0");
        else if(L[t[r]] >= l) {
            r = t[r], l = L[r];
            int b = 31 - __builtin_clz(r - l - 1);
            int x = cmi(mi[b][l + 1], mi[b][r - (1 << b)]);
            int y = cma(ma[b][l + 1], ma[b][r - (1 << b)]);
            if(x > y) swap(x, y);
            printf("4\n%d %d %d %d\n", l, x, y, r);
        } else printf("3\n%d %d %d\n", l, R[l], R[l] + 1);
    }
    return 0;
}