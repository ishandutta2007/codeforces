#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define eps 0.00000001
#define pb push_back

long long n, r, avg, a[100005], b[100005];
pair<long long, long long> p[100005];

int main(){
    ios::sync_with_stdio(0);
    cin >> n >> r >> avg;
    avg *= n;
    long long ans = 0;
    long long tot = 0;
    REP (i, n) {
        cin >> a[i] >> b[i];
        tot += a[i];
        p[i] = {b[i], a[i]};
    }
    avg -= tot;
    if (avg <= 0) {
        cout << 0;
        return 0;
    }
    sort(p, p + n);
    REP (i, n) {
        if (avg <= r - p[i].second) {
            ans += p[i].first * avg;
            cout << ans;
            return 0;
        }
        avg -= r - p[i].second;
        ans += p[i].first * (r - p[i].second);
    }
}