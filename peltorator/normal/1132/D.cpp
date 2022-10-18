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

struct kek
{
    ll a, b, c;
    kek(ll a = 0, ll b = 1, ll c = 0):
        a(a),
        b(b),
        c(c) {}
    bool operator<(const kek t) const
    {
        return a * t.b > b * t.a;
    }
};

const ll MX = 3e12;

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    int k;
    cin >> k;
    vector<ll> a(n), b(n);
    for (ll &i : a)
        cin >> i;
    for (ll &i : b)
        cin >> i;
    ll l = -1, r = MX;
    while (r - l > 1)
    {
        ll mid = (r + l) / 2;
        bool ok = 1;
        vector<int> pos(k, 0);
        int cnt = 0;
        for (int i = 0; cnt <= k && i < n; i++)
        {
            ll A = a[i], B = b[i];
            while (A / B < k - 1 && cnt <= k)
            {
                pos[A / B]++;
                cnt++;
                A += mid;
            }
        }
        int cur = 0;
        for (int i = 0; i < k; i++)
        {
            cur += pos[i];
            if (cur > i + 1)
                ok = 0;
        }
        if (ok)
            r = mid;
        else
            l = mid;
    }
    if (r == MX)
        r = -1;
    cout << r << endl;
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