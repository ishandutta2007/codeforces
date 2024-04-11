#include <bits/stdc++.h>
#include <cstdlib>
#include <string>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1e6 + 1;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n, k; cin >> n >> k;
    vector<int> can1(k * 2 + 50), can2(k * 2 + 50);
    vector<int> a(n);
    range(i, n) cin >> a[i];
    range(i, n / 2) {
        int a1 = a[i];
        int a2 = a[n-1-i];
        can1[a1 + a2 + 1]++;
        can1[max(a1, a2) + k + 1]++;
        can2[a1 + a2 - 1]++;
        can2[min(a1, a2)]++;
    }
    for(int i = 1; i <= k * 2; ++i) can1[i] += can1[i-1];
    for(int i = k * 2 + 5; i >= 0; --i) can2[i] += can2[i+1];
    int ans = INFi;
    for(int i = 2; i <= k * 2; ++i) {
        ans = min(ans, can1[i] + can2[i]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}