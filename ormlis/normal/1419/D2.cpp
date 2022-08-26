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
const int maxN = 1e6 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    sort(rall(a));
    vector<int> b;
    vector<int> c;
    range(i, (n+1)/2) {
        b.push_back(a[i]);
    }
    reverse(all(a));
    range(i, n/2) c.push_back(a[i]);
    vector<int> ans;
    reverse(all(b));
    range(i, n) {
        if (i & 1) {
            ans.push_back(c.back());
            c.pop_back();
        } else {
            ans.push_back(b.back());
            b.pop_back();
        }
    }
    if (n % 2 == 0) {
        for (int i = 1; i < n - 1; i += 2) {
            if (ans[i] < ans[i - 1] && ans[i] < ans[i + 1]) continue;
            swap(ans[i], ans[n - 1]);
        }
    }
    int answ = 0;
    for(int i = 1; i < n - 1; ++i) {
        if (ans[i] < ans[i-1] && ans[i] < ans[i+1]) answ++;
    }
    cout << answ << "\n";
    for(auto &x: ans) cout << x << " ";
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