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
#include <ctime>
#include <cassert>
   
using namespace std;
   
typedef long long ll;
typedef long double ld;

int solve()
{
    ll n, m, k;
    if (!(cin >> n))
        return 1;
    cin >> m >> k;
    ll l = 0, r = n * m + 1;
    while (r - l > 1)
    {
        ll mid = (r + l) / 2;
        ll cur = 0;
        for (ll i = 1; i <= n; i++)
            cur += min(mid / i, m);
        if (cur >= k)
            r = mid;
        else
            l = mid;
    }
    cout << r << endl;
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