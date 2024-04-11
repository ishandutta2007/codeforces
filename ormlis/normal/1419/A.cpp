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

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 1e6 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    string s1, s2;
    range(i, n) {
        if (i & 1) {
            s2 += s[i];
        } else {
            s1 += s[i];
        }
    }
    if (n % 2) {
        for(auto &x: s1) {
            if ((x - '0') % 2) {
                cout << "1\n";
                return;
            }
        }
        cout << "2\n";
    } else {
        for(auto &x: s2) {
            if ((x - '0') % 2 == 0) {
                cout << "2\n";
                return;
            }
        }
        cout << "1\n";
    }
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