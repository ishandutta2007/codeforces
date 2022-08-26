#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <tuple>
#include <queue>
#include <set>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 1e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    ll n, s; cin >> n >> s;
    ll old = n;
    vector<ll> a(19);
    ll curs = 0;
    range(i, 19) {
        a[18-i] = n % 10;
        n /= 10;
        curs += a[18-i];
    }
    if (curs <= s) {
        cout << "0\n";
        return;
    }
    a[18] = 0;
    for(int i = 17; i >= 0; --i) {
        if (a[i] == 9) {
            a[i] = 0;
            continue;
        }
        a[i]++;
        curs = 0;
        range(j, 19) curs += a[j];
        if (curs <= s) {
            ll newn = 0;
            range(j, 19) {
                newn *= 10;
                newn += a[j];
            }
            cout << newn - old << "\n";
            return;
        }
        a[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}