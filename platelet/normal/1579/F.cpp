#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

const int N = 1e6 + 5;
 
int n, k, a[N], fa[N];
 
int find(int x) { return fa[x] < 0 ? x : fa[x] = find(fa[x]); }
 
void solve() {
    cin >> n >> k;
    For(i, 0, n) scanf("%d", &a[i]), fa[i] = -1;
    For(i, 0, n) if(a[i] && a[(i + k) % n]) {
        int u = find(i), v = find((i + k) % n);
        if(u ^ v) {
            if(fa[u] > fa[v]) swap(u, v);
            fa[u] += fa[v], fa[v] = u;
        } else return void(puts("-1"));
    }
    int as = 0;
    For(i, 0, n) if(a[i]) as = max(as, -fa[find(i)]);
    cout << as << '\n';
}
int main() {
    int T;
    for(cin >> T; T--; solve());
}