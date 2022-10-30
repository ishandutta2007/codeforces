
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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

const int LOG = 20;

int foo(int up, int idx) {
    if (!up)return 0;
    int len = (1 << idx), len2 = (len << 1);
    int tot = (up / len2) * len;
    int rem = up % len2;
    tot += max(0, rem - len);
    return tot;
}

void solve() {
    int l, r;
    cin >> l >> r;
    vector<int> cnt(LOG);
    int len = r - l + 1, mxc=0;
    foru(i, 0, LOG) {
        cnt[i] = foo(r + 1, i) - foo(l, i);
        mxc = max(mxc, cnt[i]);
    }
    cout << len - mxc << '\n';
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}