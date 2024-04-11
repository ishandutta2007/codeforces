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
const int maxN = 1e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    set<int> xs;
    int n, q; cin >> n >> q;
    range(i, n) {
        int x; cin >> x;
        xs.insert(x);
    }
    int s = (*xs.rbegin()) - *xs.begin();
    multiset<int> ans;
    int prev = *xs.begin();
    for(auto &x: xs) {
        ans.insert(- x + prev);
        prev = x;
    }
    cout << s + *ans.begin() << "\n";
    range(i, q) {
        int t,x; cin >> t >> x;
        if (t) {
            auto it = xs.lower_bound(x);
            if (it != xs.end()) {
                ans.insert(- *it + x);
            }
            auto it2 = xs.lower_bound(x);
            if (it2 != xs.begin()) {
                --it2;
                ans.insert(- (x - *it2));
                if (it != xs.end()) {
                    ans.erase(ans.find(-(*it - *it2)));
                }
            }
            xs.insert(x);
        } else {
            auto it = xs.upper_bound(x);
            if (it != xs.end()) {
                ans.erase(ans.find(- (*it - x)));
            }
            auto it2 = xs.lower_bound(x);
            if (it2 != xs.begin()) {
                --it2;
                ans.erase(ans.find( - (x - *it2)));
                if (it != xs.end()) {
                    ans.insert(-(*it - *it2));
                }
            }
            xs.erase(x);
        }
        if (xs.size() <= 2) {
            cout << "0\n";
            continue;
        }
        s = (*xs.rbegin()) - *xs.begin();
        int w = *ans.begin();
        w += s;
        cout << w << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}