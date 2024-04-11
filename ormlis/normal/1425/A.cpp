#include <iostream>
#include <vector>
#include <algorithm>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define range(i, n) for(int i = 0; i < n; ++i)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

void solve() {
    ll n; cin >> n;
    ll ans = 0;
    int i = 0;
    while(n != 0) {
        ll cur = 0;
        if (n % 2 == 1) {
            cur++;
            n--;
        } else {
            if (n % 4 == 0) {
                if (n == 4) {
                    cur++;
                    n--;
                }
                cur++;
                n--;
            } else {
                cur += n / 2;
                n /= 2;
            }
        }
        if (!i) ans += cur;
        i ^= 1;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
     cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}