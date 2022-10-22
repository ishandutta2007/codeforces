#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

const int N = 2e5 + 5, P = 1e9 + 7;

int n, a[N], f[N];
void inc(int& a, int b) {
    if((a += b) >= P) a -= P;
}
struct {
    int c[N];
    void add(int i, int v) {
        for(; i <= n; i += i & -i) inc(c[i], v);
    }
    int qry(int i, int r = 0) {
        for(; i; i &= i - 1) inc(r, c[i]);
        return r;
    }
} b[2];
void solve() {
    cin >> n;
    vector<int> ord;
    rep(i, 1, n) {
        cin >> a[i], ord.pb(i);
        b[0].c[i] = b[1].c[i] = f[i] = 0;
    }
    sort(ord.begin(), ord.end(), [](int x, int y) {
        return a[x] != a[y] ? a[x] < a[y] : x > y;
    });
    int ma = 0, j = 0, ans = 0, lst = n;
    per(i, n, 1) if(a[i] >= ma) {
        int nj = j, k, t;
        while(ord[nj] != i) nj++;
        rep(l, j, nj) k = ord[l], b[1].add(k, f[k] = b[1].qry(k));
        ans = (0LL + ans + b[1].qry(lst - 1) - b[1].qry(i - 1) + P) % P;
        rep(l, j, nj) b[1].add(ord[l], P - f[ord[l]]);
        rep(l, j, nj) {
            k = ord[l], b[0].add(k, t = 1 + b[0].qry(k));
            b[1].add(k, (t + b[1].qry(k)) % P);
        }
        ma = a[i], lst = i, j = nj + 1;
    }
    ans = (ans + b[1].qry(lst - 1)) % P;
    cout << ans << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T;
    for(cin >> T; T--; solve());
}