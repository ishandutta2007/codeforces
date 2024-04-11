#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cmath>
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
#include <random>

#ifdef ONPC
    #define deb(a) cerr << "       " << #a << " = " << a << endl;
#else
    #define deb(a)
#endif

using namespace std;

mt19937 rnd(time(0));

typedef long long ll;
typedef long double ld;

vector<ll> x, y;

bool cmpx(int a, int b)
{
    return x[a] < x[b];
}

bool cmpy(int a, int b)
{
    return y[a] < y[b];
}

bool cmpp(int a, int b)
{
    return x[a] + y[a] < x[b] + y[b];
}

bool cmpm(int a, int b)
{
    return x[a] - y[a] < x[b] - y[b];
}

ll f(int i, int j)
{
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    x.assign(n, 0);
    y.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    vector<int> xx(n), yy, xym, xyp;
    for (int i = 0; i < n; i++)
        xx[i] = i;
    yy = xym = xyp = xx;
    sort(xx.begin(), xx.end(), cmpx);
    sort(yy.begin(), yy.end(), cmpy);
    sort(xym.begin(), xym.end(), cmpm);
    sort(xyp.begin(), xyp.end(), cmpp);
    set<int> q, p;
    vector<int> kek = xx;
    for (int i = 0; i < min(3, (int)xx.size()); i++)
    {
        q.insert(xx[i]);
        q.insert(xx[(int)xx.size() - i - 1]);
    }
    xx = yy;
    for (int i = 0; i < min(3, (int)xx.size()); i++)
    {
        q.insert(xx[i]);
        q.insert(xx[(int)xx.size() - i - 1]);
    }
    p = q;
    xx = xym;
    for (int i = 0; i < min(3, (int)xx.size()); i++)
    {
        q.insert(xx[i]);
        q.insert(xx[(int)xx.size() - i - 1]);
    }
    xx = xyp;
    for (int i = 0; i < min(3, (int)xx.size()); i++)
    {
        q.insert(xx[i]);
        q.insert(xx[(int)xx.size() - i - 1]);
    }
    xx = kek;
    vector<int> v;
    for (int i : q)
        v.push_back(i);
    ll ans = 0;
    for (int i = 0; i < v.size(); i++)
        for (int j = i + 1; j < v.size(); j++)
            for (int k = j + 1; k < v.size(); k++)
                ans = max(ans, f(i, j) + f(i, k) + f(j, k));
    vector<int> u;
    for (int i : p)
        u.push_back(i);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < u.size(); j++)
            for (int k = j + 1; k < u.size(); k++)
                ans = max(ans, f(i, u[j]) + f(u[j], u[k]) + f(u[k], i));
    cout << ans << ' ';
    for (int i = 4; i <= n; i++)
        cout << 2LL * (x[xx.back()] - x[xx[0]] + y[yy.back()] - y[yy[0]]) << ' ';
    cout << endl;
    return 0;
}

int32_t main()
{
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int T = 100;
    //cin >> T;
    for (int i = 1; i <= T; i++)
    {
        #ifdef ONPC
            cout << "Test #" << i << ":\n";
        #endif
        if (solve())
            break;
        #ifdef ONPC
            cout << "__________________________\n";
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1000LL / CLOCKS_PER_SEC << " ms" << endl;
    #endif
    return 0;
}