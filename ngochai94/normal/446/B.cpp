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

long long n, m, k, p, row[1111], col[1111], val;
long long dpr[1000006], dpc[1000006];
multiset<long long> s;

int main(){
    ios::sync_with_stdio(0);
    cin >> n >> m >> k >> p;
    REP (i, n) REP (j, m) {
        cin >> val;
        row[i] += val;
        col[j] += val;
    }
    REP (i, n) s.insert(row[i]);
    FOR (i, 1, k) {
        auto it = s.end();
        it--;
        long long tmp = *it;
        dpr[i] = dpr[i - 1] + tmp;
        s.erase(it);
        s.insert(tmp - p * m);
        // cout << i << ' ' << dpr[i] << endl;
    }
    s.clear();
    REP (i, m) s.insert(col[i]);
    FOR (i, 1, k) {
        auto it = s.end();
        it--;
        long long tmp = *it;
        dpc[i] = dpc[i - 1] + tmp;
        s.erase(it);
        s.insert(tmp - p * n);
        // cout << i << ' ' << dpc[i] << endl;
    }
    long long ans = - (1ll << 55);
    REP (i, k + 1) {
        // cout << i << ' ' << dpr[k - i] + dpc[i] - (k - i) * p * i << endl;
        ans = max(ans, dpr[k - i] + dpc[i] - (k - i) * p * i);
    }
    cout << ans;
}