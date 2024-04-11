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

const ll INF = 2e18 + 5;
const int INFi = 1e8;
const int maxN = 1e5 + 100;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    int n = a + b;
    range(i, n) {
        if (s[i] != '?' && s[n - 1 - i] != '?' && s[i] != s[n - 1 - i]) {
            cout << "-1\n";
            return;
        }
        if (s[i] != '?') {
            s[n - 1 - i] = s[i];
        } else if (s[n - 1 - i] != '?') {
            s[i] = s[n - 1 - i];
        } else if (i == n - 1 - i) {
            if (a % 2) s[i] = '0';
            else s[i] = '1';
        }
    }
    range(i, n) {
        if (s[i] == '0') a--;
        else if (s[i] == '1') b--;
    }
    if (a < 0 || b < 0 || a % 2 || b % 2) {
        cout << "-1\n";
        return;
    }
    range(i, n) {
        if (s[i] == '?') {
            if (a) {
                s[i] = s[n - 1 - i] = '0';
                a -= 2;
            } else {
                s[i] = s[n - 1 - i] = '1';
                b -= 2;
            }
        }
    }
    cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}