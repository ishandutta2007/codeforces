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

vector<ll> a;

void gen(ll num, int k, int cur)
{
    if (k == 18)
    {
        a.push_back(num);
        return;
    }
    num *= 10LL;
    gen(num, k + 1, cur);
    if (cur < 3)
        for (int i = 1; i < 10; i++)
            gen(num + i, k + 1, cur + 1);
}

const ll INF = 1000000000000000000LL;

int solve()
{
    a.clear();
    gen(0, 0, 0);
    sort(a.begin(), a.end());
   /* cout << " = {";
    sort(a.begin(), a.end());
    for (ll i : a)
        cout << i << ", ";
    cout << INF << "};";
    return 1;*/
    int t;
    if (!(cin >> t))
        return 1;
    a.push_back(INF);
    for (int _ = 0; _ < t; _++)
    {
        ll l, r;
        cin >> l >> r;
        auto it1 = lower_bound(a.begin(), a.end(), l);
        auto it2 = lower_bound(a.begin(), a.end(), r + 1LL);
        cout << (int)(it2 - it1) << '\n';
    }
    return 0;
}

int32_t main()
{
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
   //     freopen("out.txt", "w", stdout);
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