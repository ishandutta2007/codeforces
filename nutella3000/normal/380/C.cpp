#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define mp make_pair
#define all(_v) _v.begin(), _v.end()
#define sz(a) ((int)a.size())
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;
 
const ll inf = 1e17 + 7;
const int max_n = (1 << 20);

struct node {
    int l, r, Min;

    node() {}
    node(int l, int r, int Min) : l(l), r(r), Min(Min) {}
};

node s[2 * max_n];
int b[max_n];

void scan() {
    string s1;
    cin >> s1;
    int n = s1.size();
    for(int i = 0;i < n;i++) {
        b[i] = (s1[i] == '(' ? 1 : -1);
        if (i != 0) b[i] += b[i - 1];
    }

    for(int i = 2 * max_n - 1;i >= 1;i--) {
        if (i >= max_n) {
            int num = 0;
            if (i - max_n < n) num = b[i - max_n];
            s[i] = {i - max_n, i - max_n, num};
        }else {
            s[i] = {s[i * 2].l, s[i * 2 + 1].r, min(s[i * 2].Min, s[i * 2 + 1].Min)};
        }
    }
}

int get(int v, int l, int r) {
    if (s[v].l > r || s[v].r < l) return inf;
    if (s[v].l >= l && s[v].r <= r) return s[v].Min;
    return min(get(v * 2, l, r), get(v * 2 + 1, l, r));
}

void solve() {
    scan();
    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        int le = (l == 0 ? 0 : b[l - 1]);
        int re = b[r] - le;
        int Min = min(0ll, get(1, l, r) - le);

        //cout << le << " " << re << " " << Min << endl;

        int res = r - l + 1 + Min - max(0ll, re - Min);

        cout << res << endl;
    }
}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}