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
#include <chrono>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 3e5 + 100;
ll md = 1000000007;

//double getTime() { return clock() / (double) CLOCKS_PER_SEC;};

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int b = 0;
    int prev = 0;
    bool flag = false;
    int ans = 0;
    range(i, n) {
        if (s[i] == '(') b++;
        else b--;
        if (b < 0 && !flag) {
            prev = i;
            flag = true;
        }
        if (b == 0 && flag) {
            ans += i - prev + 1;
            flag = false;
        }
    }
    if (b) {
        cout << -1;
    } else {
        cout << ans;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}