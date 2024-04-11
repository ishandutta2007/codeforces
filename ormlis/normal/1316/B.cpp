#include <iostream>
#include <random>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <queue>
#include <cmath>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 1001;
ll md = 1000000007;

//double getTime() { return clock() / (double) CLOCKS_PER_SEC;};


void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int ans = 1;
    string sans = s;
    for(int k = 0; k < n; ++k) {
        string s3 = s.substr(0, k);
        if ((n + k) & 1) reverse(all(s3));
        string s2 = s.substr(k, n) + s3;
        if (sans > s2) ans = k+1;
        sans = min(s2, sans);
    }
    cout << sans << "\n";
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests; cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}