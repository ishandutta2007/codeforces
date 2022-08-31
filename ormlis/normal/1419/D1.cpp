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
    int j = 2;
    vector<int> u(n);
    u[0] = 1;
    vector<int> ans = {a[0]};
    int answer = 0;
    for(int i = 1; i < n; ++i) {
        while(j < n && a[j] == a[i]) j++;
        if (u[i]) continue;
        if (j == n) break;
        ans.push_back(a[j]);
        u[j] = 1;
        j++;
        ans.push_back(a[i]);
        u[i] = 1;
        answer++;
    }
    range(i, n) if (!u[i]) ans.push_back(a[i]);
    cout << answer << "\n";
    range(i, n) cout << ans[i] << " ";
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