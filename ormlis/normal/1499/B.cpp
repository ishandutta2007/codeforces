#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

typedef long long ll;

using namespace std;
//using namespace __gnu_pbds;

const int INFi = 2e9 + 5;
const int maxN = 1e7 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;

void solve() {
    string s; cin >> s;
    int n = s.size();
    vector<bool> can(n);
    can[0] = can[1] = true;
    for(int i = 2; i < n; ++i) {
        if (can[i - 1] && s[i] >= s[i - 1]) can[i] = true;
        if (can[i - 2] && s[i] >= s[i - 2]) can[i] = true;
    }
    if (can[n - 1] || can[n - 2]) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}