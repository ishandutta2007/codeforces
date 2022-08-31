#include <iostream>
#include <random>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <queue>
#include <cmath>
#include <chrono>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 1e6 + 1;
ll md = 1000000007;

//double getTime() { return clock() / (double) CLOCKS_PER_SEC;};

void solve() {
    int n; ll k;
    cin >> n >> k;
    vector<ll> a(n);
    range(i, n) cin >> a[i];
    vector<vector<int>> sa(n);
    vector<int> used(70, 0);
    range(i, n) {
        ll c = a[i];
        int j = 0;
        while(c) {
            sa[i].push_back(c % k);
            used[j] += c % k;
            c /= k;
            j++;
        }
    }
    range(i, 70) {
        if (used[i] > 1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests; cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}