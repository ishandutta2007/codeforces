#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1000;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    range(i, n) cin >> a[i];

    vector<int> good1(n), good2(n);

    set<int> s;
    for (int i = 1; i <= n; ++i) s.insert(i);
    range(i, n) {
        if (*s.begin() == i + 1) good1[i] = 1;
        if (!s.count(a[i])) break;
        s.erase(a[i]);
    }

    for(int i = 1; i <= n; ++i) s.insert(i);
    for(int i = n - 1; i >= 0; --i) {
        if (*s.begin() == n - i) good2[i] = 1;
        if (!s.count(a[i])) break;
        s.erase(a[i]);
    }

    int cnt = 0;
    range(i, n - 1) if (good2[i] && good1[i+1]) cnt++;
    cout << cnt << '\n';
    range(i, n - 1) if (good2[i] && good1[i+1]) cout << i + 1 << " " << n - i - 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tests;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}