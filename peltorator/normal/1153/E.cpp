#ifdef ONPC
    # define _GLIBCXX_DEBUG
    #define deb(a) cerr << "========" << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) (int)(a).size()


#include <bits/stdc++.h>

using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnd(time(0));

typedef long long ll;

bool ok;

int XXX = 1, YYY = 1, XX = 4, YY = 3;

int get(int X, int Y, int x, int y, int xx, int yy)
{
    return int(X >= x && X <= xx && Y >= y  && Y <= yy);
}

bool ask(int x, int y, int xx, int yy)
{
    if (ok)
    {
        swap(x, y);
        swap(xx, yy);
    }
    if (x > xx)
        swap(x, xx);
    if (y > yy)
        swap(y, yy);
#ifdef ONPC
    return (get(XXX - 1, YYY - 1, x, y, xx, yy) + get(XX - 1, YY - 1, x, y, xx, yy)) % 2;
#endif
    cout << "? " << x + 1 << ' ' << y + 1 << ' ' << xx + 1 << ' ' << yy + 1 << endl;
    int cnt;
    cin >> cnt;
    return cnt % 2;
}

int get(int xl, int xr, int yl, int yr)
{
    int L = xl - 1, R = xr;
    while (R - L > 1)
    {
        int mid = (R + L) / 2;
        if (ask(xl, yl, mid, yr))
            R = mid;
        else
            L = mid;
    }
    return R;
}

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    int pos = -1;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        a[i] = i, b[i] = i;
    shuffle(a.begin(), a.end(), rnd);
    shuffle(b.begin(), b.end(), rnd);
    for (int i : a)
        if (ask(0, 0, i, n - 1))
        {
            pos = i;
            break;
        }
    ok = 0;
    if (pos == -1)
    {
        ok = 1;
        for (int i : b)
        if (ask(0, 0, i, n - 1))
        {
            pos = i;
            break;
        }
    }
    int x = get(0, pos, 0, n - 1);
    int xx = get(pos + 1, n - 1, 0, n - 1);
    ok ^= 1;
    int y = get(0, n - 1, 0, pos);
    int yy = get(0, n - 1, pos + 1, n - 1);
    ok ^= 1;
    if (ok)
    {
        swap(x, y);
        swap(xx, yy);
    }
    cout << "! " << x + 1 << ' ' << y + 1 << ' ' << xx + 1 << ' ' << yy + 1 << endl;
    return 1;
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    //cin >> TET;
    while (TET--)
    {
        if (solve())
            break;
        #ifdef ONPC
            cout << "\n__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
    return 0;
}