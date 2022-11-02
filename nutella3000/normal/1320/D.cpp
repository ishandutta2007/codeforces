#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
typedef long double ld;

const int inf = 1e15;
const int max_n = 2e5 + 3;
const int mod = 1e9 + 9;
const int p = 4;

int n;
string s;
vector<int> ind, h;

int binpow(int a, int b) {
    int res = 1;
    for(;b > 0; b /= 2, a = a * a % mod)
        if (b & 1) res = res * a % mod;
    return res;
}

void scan() {
    cin >> n >> s;
    int last = 0;
    for(int i = 0;i < n;i++) {
        if (s[i] == '0') {
            ind.emplace_back(i);
            h.emplace_back(last = (last * p + i % 2 + 1) % mod);
        }
    }
}

int get_conv(int l, int r, bool rev) {
    if (r < l) return 0;
    int res = h[r];
    if (l != 0) res -= h[l - 1] * binpow(p, r - l + 1);

    if (rev) res = binpow(p, r - l + 1) - 1 - res;

    res = (res % mod + mod) % mod;

    return res;
}

int get(int left, int right) {
    int l = lower_bound(all(ind), left) - ind.begin();
    int r = (int)(upper_bound(all(ind), right) - ind.begin()) - 1;
    return get_conv(l, r, left % 2);
}

void solve() {
    scan();

    int m;
    cin >> m;
    for(int i = 0;i < m;i++) {
        int l1, l2, l;
        cin >> l1 >> l2 >> l;
        l1--; l2--;

        int h1 = get(l1, l1 + l - 1);
        int h2 = get(l2, l2 + l - 1);

        if (h1 == h2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}