
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <set>
#include <intrin.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

const int sz = 5e3 + 5;
const ll mod = 998244353;
ll chs[sz][sz];

void init() {
    chs[0][0] = 1;
    foru(i, 1, sz) {
        chs[i][0] = 1;
        foru(j, 1, i + 1) {
            chs[i][j] = (chs[i - 1][j] + chs[i - 1][j - 1]) % mod;
        }
    }
}


void solve() {
    init();
    string s;
    int n, k;
    cin >> n >> k >> s;
    if (k == 0) {
        cout << 1 << '\n';
        return;
    }
    int ones = 0;
    for (char c : s)ones += (c == '1');
    ll ans = (ones < k);
    vector<pii> seg;
    int r = n - 1, l = n - 1, curZeros = 0;
    while (r >= 0 && s[r] != '1') {
        r--;
    }
    int remOnes = k;
    while (l >= 0 && remOnes > 0) {
        if (s[l] == '1') {
            remOnes--;
            if (!remOnes)break;
        }
        else curZeros++;
        l--;
    }
    while (l>=0&&ones >= k) {
        int tor = 0, tol = 0;
        foru(i, r + 1, n) {
            if (s[i] == '1')break;
            tor++;
        }
        ford(i, l - 1, 0) {
            if (s[i] == '1')break;
            tol++;
        }
        curZeros -= tor;
        int len = curZeros + tor + tol + k;
        ans += (mod + chs[len][k] - chs[len - tor - 1][k - 1]);
        ans %= mod;
        if (ones == k) {
            ans += chs[len - tor - 1][k - 1];
            ans %= mod;
        }
        curZeros += tol;
        ford(i, r - 1, 0) {
            if (s[i] == '1') {
                r = i;
                break;
            }
        }
        ford(i, l - 1, 0) {
            if (s[i] == '1') {
                l = i;
                break;
            }
        }
        ones--;
    }
    cout << ans << '\n';
}

int main() {
    fast;
    int t=1;
    //cin >> t;
    while (t--)solve();

    return 0;
}