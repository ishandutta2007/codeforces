#include <iostream>
#include <vector>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 200001;
ll md = 1000000007;

void solve() {
    int ns, n;
    cin >> ns;
    vector<ll> a(ns);
    range(i, ns) cin >> a[i];
    cin >> n;
    vector<int> b(ns, n - 1);
    vector<ll> c(n, 0);
    for(int i = n - 1; i >= 0; --i) {
        int t; cin >> t;
        if (--t) {
            ll x; cin >>  x;
            c[i] = x;
        } else {
            int p; ll x; cin >> p >> x; p--;
            b[p] = i;
            a[p] = x;
        }
    }
    for(int i = 1; i < n; ++i) {
        c[i] = max(c[i], c[i - 1]);
    }
    range(i, ns) {
        cout << max(a[i], c[b[i]]) << ' ';
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests; tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}