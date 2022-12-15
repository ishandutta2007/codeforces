#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define eps 0.00000001
#define sqr(x) (x) * (x)
#define pb push_back

long long n, a[100005], b[100005], dp[100005], cur;
set<pair<long long, long long> > s;

long long surpass(int x, int y) {
    return (dp[y] - dp[x] - 1 + b[x] - b[y]) / (b[x] - b[y]);
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    REP (i, n) cin >> a[i];
    REP (i, n) cin >> b[i];
    s.insert({0, 0});
    FOR (i, 1, n - 1) {
        auto it = s.upper_bound({a[i], mod});
        it--;
        dp[i] = dp[it->second] + a[i] * b[it->second];
        // cout << i << ' ' << it->second << ' ' << dp[i] << endl;
        while (s.size() > 1) {
            auto it1 = s.end();
            it1--;
            it1--;
            auto it2 = s.end();
            it2--;
            long long p1 = surpass(it1->second, i);
            long long p2 = surpass(it2->second, i);
            if (p1 < p2) break;
            s.erase(it2);
        }
        it = s.end();
        it--;
        s.insert({surpass(it->second, i), i});
    }
    cout << dp[n - 1];
}