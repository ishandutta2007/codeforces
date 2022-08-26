#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 4e18;
const int INFi = 2e9;
const int maxN = 2e5 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n0, n1, n2; cin >> n0 >> n1 >> n2;
    vector<int> a;
    if (n1 || n0) range(i, n0 + 1) a.push_back(0);
    if (n1 || n2) range(i, n2 + 1) a.push_back(1);
    range(i, n1 - 1) {
        if (i % 2 == 0) a.push_back(0);
        else a.push_back(1);
    }
    for(auto &x: a) cout << x;
    cout << '\n';
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