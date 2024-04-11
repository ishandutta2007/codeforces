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
#include <functional>
#include <random>
#include <chrono>
#include <cassert>
#include <iomanip>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 1e5 + 1;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int l = -1;
    vector<int> cur;
    for(int i = 1; i < n; ++i) {
        if (s[i] == s[i-1]) cur.push_back(i);
    }
    reverse(all(cur));
    int ans = 0;
    for(int i = 0; i < n;) {
        ans++;
        while(!cur.empty() && cur.back() < i) {
            cur.pop_back();
        }
        if (cur.empty()) {
            while(n > 1 && s[n-1] == s[n-2]) n--;
            n--;
        } else {
            cur.pop_back();
        }
        if (i >= n) break;
        i++;
        while(i < n && s[i] == s[i-1]) i++;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}