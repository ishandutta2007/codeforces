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
// #include <ext/pb_ds/assoc_container.hpp>

// using namespace __gnu_pbds;

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
const int maxN = 1e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n;
    cin >> n;
    set<int> events;
    vector<pair<char, int>> queries(n * 2);
    vector<int> position(n);
    range(i, n * 2) {
        char x;
        cin >> x;
        if (x == '+') {
            events.insert(i);
            queries[i] = {x, -1};
        } else {
            int tt;
            cin >> tt;
            tt--;
            position[tt] = i;
            queries[i] = {x, tt};
        }
    }
    range(i, n) {
        auto it = events.lower_bound(position[i]);
        if (it == events.begin()) {
            cout << "NO\n";
            return;
        }
        --it;
        queries[*it].second = i;
        events.erase(it);
    }
    set<int> s;
    vector<int> order;
    for(auto &[ty, x] : queries) {
        if (ty == '+') {
            s.insert(x);
            order.push_back(x+1);
        } else {
            if (s.empty()) {
                cout << "NO\n";
                return;
            }
            auto kek = *s.begin();
            s.erase(s.begin());
            if (kek != x) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
    range(i, n) cout << order[i] << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}