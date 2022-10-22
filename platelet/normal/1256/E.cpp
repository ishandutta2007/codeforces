#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

const int N = 2e5 + 5;

int n, f[N], g[N], t[N];
pair<int, int> a[N];

int val(int i) { return f[i] - a[i + 1].first; }
int main() {
    cin >> n;
    rep(i, 1, n) scanf("%d", &a[i].first), a[i].second = i;
    sort(a + 1, a + n + 1);
    rep(i, 3, n) {
        f[i] = val(g[i - 3]) + a[i].first;
        g[i] = val(i) < val(g[i - 1]) ? i : g[i - 1];
    }
    int idx = 0;
    for(int i = n; i; i = g[i - 3]) {
        idx++;
        rep(j, g[i - 3] + 1, i) t[a[j].second] = idx;
    }
    printf("%d %d\n", f[n], idx);
    rep(i, 1, n) printf("%d ", t[i]);
}