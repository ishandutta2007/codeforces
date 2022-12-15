#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second
#define offset 1100

long long n, m, k, x, s;
long long a[200005], b[200005], c[200005], d[200005];
pair<long long, long long> p[200005];
set<pair<long long, long long> > ss;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n >> m >> k >> x >> s;
    REP (i, m) cin >> a[i];
    REP (i, m) cin >> b[i];
    long long ans = n * x;
    REP (i, m)
    {
        p[i] = {b[i], a[i]};
        if (b[i] <= s)
        {
            ans = min(ans, n * a[i]);
        }
    }
    sort(p, p + m);
    REP (i, k) cin >> c[i];
    REP (i, k) cin >> d[i];
    long long cur = x;
    REP (i, m) if (p[i]._2 < cur)
    {
        ss.insert({p[i]._1, p[i]._2});
        cur = p[i]._2;
    }

    REP (i, k) if (d[i] <= s)
    {
        auto it = ss.upper_bound({s - d[i], x});
        if (it != ss.begin())
        {
            it--;
            ans = min(ans, max(0ll, n - c[i]) * (it -> second));
        } else {
            ans = min(ans, max(0ll, n - c[i]) * x);
        }
    }
    cout << ans;
}