#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()


typedef long long ll;
typedef long double ld;
using namespace std;

//using namespace __gnu_pbds;

const ll INF = 1e18 + 5;
const int INFi = 1e9;
const int maxN = 20;
const int md2 = 998244353;
const int md = 1e9 + 7;


void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b;
    range(i, n) {
        cin >> a[i];
        range(j, i) b.push_back(a[i] - a[j]);
    }
    sort(all(b));
    b.resize(unique(all(b)) - b.begin());
    cout << (int)b.size() << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}