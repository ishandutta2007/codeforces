#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

int n, a, b, ini;
vector<int> lis[100005], pre[100005];
vector<pair<int, int> > avai;

int f(int x)
{
    int cnt = ini;
    int cost = 0;
    FOR (i, 1, 100000) if (lis[i].size() >= x)
    {
        cnt += lis[i].size() - x + 1;
        cost += pre[i].back() - pre[i][x - 1];
    }
    int pnt = 0;
    while (cnt < x)
    {
        while (avai[pnt]._2 >= x) pnt++;
        cnt++;
        cost += avai[pnt++]._1;
    }
    return cost;
}

void solve()
{
    cin >> n;
    REP (i, n)
    {
        cin >> a >> b;
        if(!b)
        {
            ini++;
            continue;
        }
        lis[a].pb(b);
    }
    FOR (i, 1, 100000) if (!lis[i].empty())
    {
        sort(lis[i].begin(), lis[i].end());
        reverse(lis[i].begin(), lis[i].end());
        pre[i].pb(0);
        for (int j: lis[i]) pre[i].pb(pre[i].back() + j);
        REP (j, lis[i].size()) avai.pb({lis[i][j], j + 1});
    }
    sort(avai.begin(), avai.end());
    int high = n, low = 1;
    while (high - low > 2)
    {
        int mid1 = (high + low) / 2;
        int mid2 = (high + mid1) / 2;
        if (f(mid1) > f(mid2)) low = mid1;
        else high = mid2;
    }
    int ans = mod;
    FOR (i, low, high) ans = min(ans, f(i));
    cout << ans;
}

int main() {
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif LOCAL
    ios::sync_with_stdio(0);
    int ntest = 1;
    //cin >> t;
    while (ntest--)
    {
        solve();
    }
}