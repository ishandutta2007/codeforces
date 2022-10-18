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

const ll M = 1e6;
const ll T = 1999;

int solve()
{
    ll n;
    if (!(cin >> n))
        return 1;
    if (n < M - 1)
    {
        cout << "2\n-1 " << n + 2 << endl;
        return 0;
    }
 //   for (ll n = M - 1;;n++)
    {
   // ll kek = (n + n / T) % T;
   // ll B = M - kek;
    
//    ll s = B - (n + B) / T;
    ll kek = (n + M) % T;
    ll B = M - kek;
    ll s = B - (n + B) / T;
    vector<ll> ans;
    ans.push_back(B);
    for (int i = 0; i < T - 1; i++)
    {
        ans.push_back(-min(M, s));
        s -= min(M, s);
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (ll i : ans)
        cout << i << ' ';
    cout << endl;
    return 1;
    ll sum = 0;
    ll answ = 0;
    ll keks = 0;
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        keks++;
        sum += ans[i];
        answ = max(answ, sum * keks);
    }
    cout << "~~~\n" << answ - B - n <<  endl;
    if (answ - B != n)
    {
        cout << n << endl;
        return 1;
    }
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