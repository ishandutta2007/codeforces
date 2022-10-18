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
#include <iomanip>

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
    vector<ll> a(n, 0);
    for (ll &i : a)
        cin >> i;
    int m;
    cin >> m;
    sort(a.rbegin(), a.rend());
    ll sum = 0;
    for (ll i : a)
        sum += i;
    while (m--)
    {
        int q;
        cin >> q;
        cout << sum - a[q - 1] << '\n';
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