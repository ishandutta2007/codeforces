//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < n; ++i)
#define all(arr) arr.begin(), arr.end()
#define rall(arr) arr.rbegin(), arr.rend()


using namespace std;

typedef long long ll;
const int INFi = 2e9;
const ll INF = 2e18;
const int maxN = 2e5;
const int md = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> b(n);
    range(i, n) cin >> b[i];
    map<int, ll> mp;
    range(i, n) {
        mp[b[i]-i] += b[i];
    }
    ll f = 0;
    for(auto x: mp) f = max(f, x.second);
    cout << f;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //auto sad = mt19937(2231337);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}