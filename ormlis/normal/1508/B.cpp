#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

const ll INF = 2e18 + 5;
const int INFi = 1e9;
const int maxN = 3e5 + 100;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    int n;
    ll k; cin >> n >> k;
    vector<ll> cnt(n + 1);
    cnt[1] = cnt[0] = 1;
    ll res = 2;
    for(int i = 2; i <= n; ++i) {
        cnt[i] = res;
        if (res != INF) {
            res += cnt[i];
        }
        if (res > INF) res = INF;
    }
    if (cnt[n] < k) {
        cout << "-1\n";
        return;
    }
    vector<int> cur;
    int mx = 0;
    while(cur.size() < n) {
        int d = 1;
        int t = (int)n - (int)cur.size();
        t--;
        while(t >= 0 && cnt[t] < k) {
            k -= cnt[t];
            t--;
            d++;
        }
        for(int i = mx + d; i >= mx + 1; --i) cur.push_back(i);
        mx += d;
    }
    assert(k == 1);
    for(auto &x : cur) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(2) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}