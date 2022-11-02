#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <queue>
#include <bitset>
#include <set>
#include <deque>
#include <stack>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll calcDisjoint(ll to, ll until) {
    ll lsb = 1, tot=0, onSoFar=0;
    for (int i = 0; i < 30; i++) {
        if (until & lsb) {
            ll rem = until ^ lsb;
            if (!(to & rem)) {
                tot += (1 << (i - onSoFar));
            }
            until = rem;
        }
        lsb <<= 1;
        onSoFar += ((to >> i) & 1);
    }
    return tot;
}

ll calc(ll l, ll r) {
    if (l >= r)return 0;
    else if (l == 0)return calc(l + 1, r) + 2 * r - 1;
    else if (l % 2 == 0 && r % 2 == 0)return 3 * calc(l / 2, r / 2);
    else if (l & 1) return calc(l + 1, r) + 2 * (calcDisjoint(l, r) - calcDisjoint(l, l));
    else return calc(l, r - 1) + 2 * (calcDisjoint(r - 1, r) - calcDisjoint(r - 1, l));
}


int main() {
    fast;
    int t;
    cin >> t;
    while (t--) {
        ll l, r;
        cin >> l >> r;
        cout << calc(l, r + 1) << '\n';
    }
    return 0;
}