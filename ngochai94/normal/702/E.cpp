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

long long n, f[100005], w[100005], dps[100005][44], k, dpm[100005][44], dpf[100005][55];

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n >> k;
    REP (i, n) cin >> f[i];
    REP (i, n) cin >> w[i];
    REP (i, n)
    {
        dps[i][0] = dpm[i][0] = w[i];
        dpf[i][0] = f[i];
    }
    FOR (j, 1, 35)
    {
        REP (i, n)
        {
            dpf[i][j] = dpf[dpf[i][j - 1]][j - 1];
            dps[i][j] = dps[i][j - 1] + dps[dpf[i][j - 1]][j - 1];
            dpm[i][j] = min(dpm[i][j - 1], dpm[dpf[i][j - 1]][j - 1]);
        }
    }
    //BUG(dpf[0][0]);
    REP (i, n)
    {
        long long tmp = i, anss = 0, ansm = (1ll << 55);
        REP (j, 36) if (k & (1ll << j))
        {
            anss += dps[tmp][j];
            ansm = min(ansm, dpm[tmp][j]);
            tmp = dpf[tmp][j];
        }
        cout << anss << ' ' << ansm << endl;
    }
}