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
const int maxN = 1e7 + 1;
const int md2 = 998244353;
const int md3 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

int minp[maxN];
vector<int> primes;

void solve() {
    for (int i = 2; i < maxN; ++i) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        for (auto &p: primes) {
            if (1ll * p * i >= maxN || p > minp[i]) break;
            minp[p * i] = p;
        }
    }
    int n;
    cin >> n;
    vector<int> ans1(n, -1), ans2(n, -1);
    range(i, n) {
        int a;
        cin >> a;
        if (a % 2 == 0) {
            int kek = 2;
            while (a % 2 == 0) a /= 2;
            if (a == 1) continue;
            ans1[i] = kek;
            ans2[i] = a;
            continue;
        }
        int kek = minp[a];
        while (a != 1 && minp[a] == kek) a /= minp[a];
        if (a == 1) continue;
        ans1[i] = kek;
        ans2[i] = minp[a];
    }
    range(i, n) cout << ans1[i] << " ";
    cout << "\n";
    range(i, n) cout << ans2[i] << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}