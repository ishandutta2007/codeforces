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
const int maxN = 4e6;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    vector<int> ones, zeros;
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    vector<int> num(n, -1);
    range(i, n) {
        if (s[i] == '1') {
            if (!zeros.empty()) {
                num[i] = num[zeros.back()];
                zeros.pop_back();
            } else {
                ans++;
                num[i] = ans;
            }
            ones.push_back(i);
        } else {
            if (!ones.empty()) {
                num[i] = num[ones.back()];
                ones.pop_back();
            } else {
                ans++;
                num[i] = ans;
            }
            zeros.push_back(i);
        }
    }
    cout << ans << "\n";
    range(i, n) cout << num[i] << " ";
    cout << "\n";
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