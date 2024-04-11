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
const int maxN = 2e5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    range(i, n) a[i]--;
    vector<vector<int>> reqs;

    auto Do = [&] (vector<int> &dd) {
        if (dd.size() == 1) return;
        reqs.push_back(dd);
        vector<vector<int>> to(dd.size());
        int i = 0;
        range(e, (int)dd.size()) {
            range(j, dd[e]) {
                to[e].push_back(a[i]);
                i++;
            }
        }
        reverse(all(to));
        reverse(all(dd));
        i = 0;
        range(e, (int)dd.size()) {
            range(j, dd[e]) {
                a[i] = to[e][j];
                i++;
            }
        }
    };

    range(i, n - 1) {
        int pos = 0;
        range(j, n) {
            if (a[j] == i) pos = j;
        }
        vector<int> cur;
        if (i % 2) {
            range(e, i) cur.push_back(1);
            cur.push_back(pos-i+1);
            if (n-pos-1 != 0)cur.push_back(n-pos-1);
        } else {
            if (pos != 0) cur.push_back(pos);
            cur.push_back(n-pos-i);
            range(e, i) cur.push_back(1);
        }
        Do(cur);
    }
    if (a[0] == n-1) {
        vector<int> cur;
        range(i, n) cur.push_back(1);
        Do(cur);
    }
    cout << reqs.size() << "\n";
    for(auto &req: reqs) {
        cout << req.size() << " ";
        for(auto &x: req) cout << x << " ";
        cout << "\n";
    }
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