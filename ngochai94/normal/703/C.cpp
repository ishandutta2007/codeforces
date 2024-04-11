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

int n;
long double w, vx, vy, x, y;
pair<long double , long double> p[10004];

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n >> w >> vx >> vy;
    bool flag = false;
    REP (i, n)
    {
        cin >> x >> y;
        p[i] = {y, -x};
        if (vx * y > vy * x) flag = true;
    }
    if (!flag)
    {
        cout << setprecision(11) << w / vy;
        return 0;
    }
    sort(p, p + n);
    long double lx = 0, ly = 0;
    long double ans = 0;
    REP (i, n)
    {
        y = p[i]._1;
        x = -p[i]._2;
        //cout << x << ' ' << y << ' ' << lx << ' ' << ly << endl;
        if (x < lx) continue;
        if (vx * (y - ly) >= vy * (x - lx))
        {
            ans += (y - ly) / vy;
            lx = lx + vx * (y - ly) / vy;
            ly = y;
        }
        else
        {
            ans += 1.0 * (x - lx) / vx;
            lx = x;
            ly = y;
        }
        //BUG(ans);
    }
    ans += (w - ly) / vy;
    cout << setprecision(11) << ans;
}