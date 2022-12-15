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

int n, par[200005], anc[200005][19], lvl[200005], u, v, val;

int lca(int a, int b)
{
    if (lvl[a] > lvl[b]) swap(a, b);
    FORD (i, 18, 0) if (lvl[anc[b][i]] >= lvl[a]) b = anc[b][i];
    if (b == a) return a;
    FORD (i, 18, 0) if (anc[a][i] != anc[b][i])
    {
        a = anc[a][i];
        b = anc[b][i];
    }
    return par[a];
}

int dis(int a, int b)
{
    int c = lca(a, b);
    return lvl[a] + lvl[b] - 2 * lvl[c];
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n;
    lvl[1] = 0;
    par[1] = 1;
    REP (i, 19) anc[1][i] = 1;
    u = v = 1;
    FOR (i, 2, n)
    {
        cin >> val;
        lvl[i] = lvl[val] + 1;
        par[i] = anc[i][0] = val;
        FOR (j, 1, 18) anc[i][j] = anc[anc[i][j - 1]][j - 1];
        if (dis(u, i) > dis(u, v) && dis(u, i) >= dis(v, i)) v = i;
        else if (dis(v, i) > dis(u, v)) u = i;
        //BUG(u);
        //BUG(v);
        cout << dis(u, v) << ' ';
    }
}