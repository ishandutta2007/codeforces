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
const int maxN = 305;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];

    auto mex = [&] () {
        auto b = a;
        sort(all(b));
        b.resize(unique(all(b)) - b.begin());
        range(i, b.size()) {
            if (b[i] != i) return i;
        }
        return (int)b.size();
    };

    vector<int> ans;
    range(i, n) {
        if (a[i] == i) continue;
        int m = mex();
        while(m != n) {
            ans.push_back(m+1);
            a[m] = m;
            m = mex();
        }
        if (a[i] == i) continue;
        range(j, n) {
            if (a[j] == i) {
                ans.push_back(j+1);
                a[j] = n;
            }
        }
        ans.push_back(i + 1);
        a[i] = i;
    }
    cout << ans.size() << "\n";
    for(auto &x: ans) cout << x << " ";
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