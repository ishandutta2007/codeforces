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
    vector<int> a(maxN);
    int cnt2 = 0, cnt4 = 0;
    auto add = [&] (int x) {
        cnt2 -= a[x] / 2;
        a[x]++;
        cnt2 += a[x] / 2;
        if (a[x] == 4) cnt4++;
    };

    auto rem = [&] (int x) {
        cnt2 -= a[x] / 2;
        a[x]--;
        cnt2 += a[x] / 2;
        if (a[x] == 3) cnt4--;
    };

    range(i, n) {
        int x; cin >> x;
        add(x);
    }
    int q; cin >> q;
    range(_, q) {
        char p; int x; cin >> p >> x;
        if (p == '+') add(x);
        else rem(x);
        if (cnt2 >= 4 && cnt4) cout << "YES\n";
        else cout << "NO\n";
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