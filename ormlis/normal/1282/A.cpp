#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_map>
#include <fstream>
#include <cstring>
#include <map>
#include <bitset>
#include <iomanip>

#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

const int Nm=100001;

void solve() {
    ll a, b, c, r; cin >> a >> b >> c >> r;
    if (a > b) swap(a, b);
    ll l = max(a, c - r);
    ll r2 = min(b, c + r);
    ll o = 0;
    cout << abs(a - b) - max((r2 - l), o) << '\n';
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int tests; cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}