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

const ll INF = 1000000000000000000LL;

ll bin(ll a, ll b)
{
    if (!b)
        return 0;
    if (b % 2)
        return min(INF + 1, bin(a, b - 1) + a);
    ll t = bin(a, b / 2);
    return min(INF + 1, t + t);
}

int solve()
{
    vector<ll> p;
    for (ll i = 1; i * i * i <= INF; i++)
    {
        ll t = sqrt(i);
        t = max(0LL, t - 3);
        while (t * t < i)
            t++;
        if (t * t == i)
            continue;
        ll q = i * i * i;
        ll cur = 3;
        while (q <= INF)
        {
            if (cur % 2)
                p.push_back(q);
            q = bin(q, i);
            cur++;
        }
    }
    vector<ll> q;
    sort(p.begin(), p.end());
    q.push_back(p[0]);
    for (int i = 1; i < p.size(); i++)
        if (p[i] != p[i - 1])
            q.push_back(p[i]);
    int t;
    cin >> t;
    p.clear();
    for (int i = 0; i < t; i++)
    {
        ll n;
        cin >> n;
        ll ans = sqrt(n);
        ans = max(0LL, ans - 3);
        while (ans * ans <= n)
            ans++;
        ans--; 
        ans += (ll)(upper_bound(q.begin(), q.end(), n) - q.begin());
        cout << n - ans << '\n';
    }
    return 1;
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