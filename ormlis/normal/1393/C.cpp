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
typedef unsigned long long ull;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 1e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    range(i, n) {
        int x; cin >> x;
        a[x-1]++;
    }
    auto check = [&] (int x) {
        auto cnt = a;
        set<pair<int, int>> s;
        range(i, n) {
            if (a[i]) s.insert({-a[i], i});
        }
        vector<vector<int>> need_to_add(n+1);
        range(i, n) {
            for(auto &w: need_to_add[i]) if (cnt[w]) s.insert({-cnt[w], w});
            if (s.empty()) return false;
            auto p = *s.begin();
            s.erase(s.begin());
            cnt[p.second]--;
            need_to_add[min(n, i + x + 1)].push_back(p.second);
        }
        return true;
    };
    int l = 0, r = n;
    while(r - l > 1) {
        int mid = (r + l) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << "\n";
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