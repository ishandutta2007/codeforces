#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define cmin(a, b) (a = min(a, b))

using namespace std;

const int N = 5e5 + 5;

int n, m, d, g[N], a[N], b[N], f[N], mi[N];
vector<int> L[N], R[N];

int get(int x) { return lower_bound(g + 1, g + m + 1, x) - g; }
int main() {
    cin >> n >> d, mem(mi, 63);
    rep(i, 1, n) scanf("%d%d", &a[i], &b[i]), g[i] = a[i];
    sort(g + 1, g + n + 1);
    m = unique(g + 1, g + n + 1) - g - 1;
    d = get(d), f[m + 2] = -n;
    rep(i, 1, n) {
        int x = get(a[i]), y = get(b[i]);
        if(y <= x) L[y].pb(x), R[x].pb(y);
        else cmin(mi[x], y);
    }
    int j = m + 1, ct = 0;
    per(i, m, d) {
        for(int r : L[i + 1]) ct -= r <= j;
        ct += R[i].size();
        while(j >= mi[i]) for(int l : R[j--]) ct -= l <= i;
        f[i] = max(f[i + 1] + (int)R[i].size(), f[j + 1] + 1 + ct);
    }
    cout << f[d];
}