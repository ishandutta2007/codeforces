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

mt19937 rnd(239);

typedef long long ll;
typedef long double ld;

bool ask(ll l, ll r)
{
    cout << l + 1 << ' ' << r << endl;
    string s;
    cin >> s;
    if (s == "Yes")
    {
        if (l + 1 == r)
        {
            exit(0);
        }
        return 1;
    }
    if (s == "Bad")
    {
        exit(0);
    }
    return 0;
}

int solve()
{
    ll n;
    cin >> n;
    int k;
    cin >> k;
    ll l = 0, r = n;
  /*  while (r - l > 10 * k)
    {
        ll mid = (r + l) / 2LL;
        if (ask(l, mid))
        {
            l = max(l - k, 0LL), r = min(mid + k, n);
        }
        else
        {
            l = max(mid - k, 0LL), r = min(r + k, n);
        }
    }*/
    while (true)
    {
     //   cout << "------ " << l << ' ' << r << endl;
        ll x = rnd() % (r - l) + l;
        ask(x, x + 1);
        l = max(l - k, 0LL);
        r = min(r + k, n);
        ll mid = (r + l) / 2LL;
        if (ask(l, mid))
        {
            l = max(l - k, 0LL), r = min(mid + k, n);
        }
        else
        {
            l = max(mid - k, 0LL), r = min(r + k, n);
        }
    }
    return 1;
}

int32_t main()
{
    #ifdef ONPC
    //    freopen("in.txt", "r", stdin);
      //  freopen("out.txt", "w", stdout);
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