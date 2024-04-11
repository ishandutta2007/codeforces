#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <unordered_set>
#include <complex>
#include <unordered_map>
#include <bitset>
#include <ctime>
#include <cassert>
   
using namespace std;

typedef long long ll;

const int LG = 61, N = 500;
const ll INF = 1e18;

typedef long double ld;
typedef vector<vector<bool> > mtr;

vector<bitset<500> > x, y, z;
int n;

mtr prod(mtr a, mtr b)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            x[i][j] = a[i][j], y[j][i] = b[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if ((x[i] & y[j]).count())
                a[i][j] = 1;
            else
                a[i][j] = 0;
    return a;
}

vector<mtr> a, b;

mtr cur, newcur;

int solve()
{
    int m;
    if (scanf("%d", &n) != 1)
        return 1;
   // cin >> m;
    scanf("%d", &m);
    x.resize(n);
    y.resize(n);
    a.resize(LG);
    b.resize(LG);
    for (int i = 0; i < LG; i++)
    {
        a[i].assign(n, vector<bool>(n, 0));
        b[i].assign(n, vector<bool>(n, 0));
    }
    for (int i = 0; i < m; i++)
    {
        int x, y, t;
        //cin >> x >> y >> t;
        scanf("%d %d %d", &x, &y, &t);
        x--;
        y--;
        if (t == 0)
            a[0][x][y] = 1;
        else
            b[0][x][y] = 1;
    }
    for (int i = 1; i < LG; i++)
        a[i] = prod(a[i - 1], b[i - 1]), b[i] = prod(b[i - 1], a[i - 1]);
    cur.assign(n, vector<bool>(n, 0));
    for (int i = 0; i < n; i++)
        cur[i][i] = 1;
    ll ans = 0;
    ll t = 1;
    for (int i = 1; i < LG; i++)
        t *= 2LL;
    int q = 0;
    for (int i = LG - 1; i >= 0; i--)
    {
        newcur = prod(cur, (q % 2 ? b[i] : a[i]));
        bool ok = false;
        for (int i = 0; i < n; i++)
            if (newcur[0][i])
                ok = true;
        if (ok)
        {
            q++;
            ans += t;
            cur = newcur;
        }
        t /= 2;
    }
    if (ans > INF)
        ans = -1;
    cout << ans << "\n";
    return 0;
}

int main()
{
    int T = 1;
#ifdef ONPC
    freopen("in.txt", "r", stdin);
#endif
    while (!solve()) {
  //  cin >> T; for (int i = 0; i < T; i++) { solve();
        #ifdef ONPC
            cerr << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
        #endif
    }
#ifdef ONPC
    cerr << endl << "finished in " << clock() * 1000LL / CLOCKS_PER_SEC << " ms" << endl;
#endif
    return 0;
}