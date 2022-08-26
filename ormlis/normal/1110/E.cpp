#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1e6 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n; cin >> n;
    vector<int> c(n - 1), t(n - 1);
    int start1, start2;
    int prev; cin >> prev;
    start1 = prev;
    range(i, n - 1) {
        int a; cin >> a;
        c[i] = a - prev;
        prev = a;
    }
    cin >> prev;
    start2=prev;
    range(i, n - 1) {
        int a; cin >> a;
        t[i] = a - prev;
        prev = a;
    }
    sort(all(c));
    sort(all(t));
    cout << (c == t && start1 == start2 ? "Yes" : "No");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests=1;
    range(_, tests) {
        solve();
    }
    return 0;
}