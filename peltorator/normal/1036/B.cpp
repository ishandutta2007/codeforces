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

#define sz(a) (int)((a).size())
#ifdef ONPC
    #define deb(a) cerr << "       " << #a << " = " << a << endl;
#else
    #define deb(a)
#endif

using namespace std;

mt19937 rnd(time(0));

typedef long long ll;
typedef long double ld;

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    for (int i = 0; i < n; i++)
    {
        ll x, y, k;
        cin >> x >> y >> k;
        x = abs(x);
        y = abs(y);
        if (x < y)
            swap(x, y);
        if (x + y == 0)
        {
            if (k == 1)
                cout << -1;
            else if (k % 2)
                cout << k - 2;
            else
                cout << k;
            cout << '\n';
            continue;
        }
        if (x > k)
        {
            cout << "-1\n";
            continue;
        }
        if (x % 2 == y % 2)
        {
            if (x % 2 == k % 2)
                cout << k;
            else
                cout << k - 2;
            cout << '\n';
            continue;
        }
/*        if (x % 2 != k % 2)
            cout << k - 1;
        else
            cout << k - */
      //  if (x == k)
        //    cout <<         
        //else
            cout << k - 1 << '\n';
    }
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