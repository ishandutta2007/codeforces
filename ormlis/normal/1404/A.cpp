#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <set>
#include <cstring>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 2e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int cnt0 = 0, cnt1 = 0;
    for(int i = k; i < n; ++i) {
        if (s[i] == '?') continue;
        if (s[i%k] == '?') s[i%k] = s[i];
        if (s[i%k] != s[i]) {
            cout << "NO\n";
            return;
        }
    }
    range(i, k) {
        if (s[i] == '0') cnt0++;
        if (s[i] == '1') cnt1++;
    }
    if (cnt1 > k / 2 || cnt0 > k / 2) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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