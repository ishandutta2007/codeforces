#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

ll n, m;

ll f(ll num) {
    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        ans += min((ll)m, (num - 1) / i);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll k;
    cin >> n >> m >> k;

    ll lo = 1, hi = n * m, mid;

    while (lo < hi) {
        mid = lo + (hi - lo + 1) / 2;
        if (f(mid) < k) lo = mid;
        else hi = mid - 1;
    }

    cout << lo << "\n";
    return 0;
}