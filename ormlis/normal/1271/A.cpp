#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <unordered_set>
#include <fstream>
#include <cstring>
#include <map>

#define ll long long
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

using namespace std;

void solve() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    ll ans = 0;
    if (e > f) {
        int k = min(a, d);
        d-=k;
        a-=k;
        ans += e * k;
    }
    int l = min(b, min(c, d));
    ans += f * l;
    d -= l;
    ans += e * min(a, d);
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(i, tests) {
        solve();
    }
    return 0;
}