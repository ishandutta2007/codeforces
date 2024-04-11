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
    ll ans = 0;
    multiset<int> a, b;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.insert(-x);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        b.insert(-x);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
        {
            int besta = -1, bestb = -1;
            if (a.size())
                besta = -*a.begin();
            if (b.size())
                bestb = -*b.begin();
            if (besta > bestb)
            {
                if (!j)
                    ans -= *a.begin();
                a.erase(a.begin());
            }
            else
            {
                if (j)
                    ans += *b.begin();
                b.erase(b.begin());
            }
        }
    cout << ans << endl;
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