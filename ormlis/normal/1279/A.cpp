#include <bits/stdc++.h>
#include <unordered_set>

#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

void solve() {
    ll r, g, b; cin >> r >> g >> b;
    ll a = r + g + b;
    if (max(r, max(g, b)) > a - max(r, max(g, b)) + 1) {
        cout << "No\n";
    }
    else {
        cout << "Yes\n";
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int tests;
    cin >> tests;
    //tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}