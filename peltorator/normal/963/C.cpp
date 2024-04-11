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

using namespace std;

mt19937 rnd(239);

typedef long long ll;
typedef long double ld;


ll gcd(ll a, ll b)
{
    return (a ? gcd(b % a, a) : b);
}

int solve()
{
    ios::sync_with_stdio(0);
    int n;
    if (!(cin >> n))
    {
        return 1;
    }
    ll cur = 0;
    map<ll, ll> y;
    set<ll> q;
    map<ll, vector<pair<ll, ll> > > p, pp;
    for (int i = 0; i < n; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        q.insert(b);
        p[a].push_back({b, c});
        if (i == 0)
            cur = c;
        else
            cur = gcd(cur, c);
    }
    int cnt = 0;
    for (ll i : q)
        y[i] = cnt++;

    for (auto it : p)
    {
        vector<pair<ll, ll> > kek = it.second;
        for (auto &it2 : kek)
        {
            it2.first = y[it2.first];
        }
        pp[it.first] = kek;
    }
    p = pp;
    vector<ll> good(cnt, 0);
    for (auto it : p.begin()->second)
        good[it.first] = it.second;
    for (int i : good)
        if (!i)
        {
            cout << 0 << endl;
            return 0;
        }
    for (auto it : p)
    {
        ll up = it.second.begin()->second;
        ll down = good[it.second.begin()->first];
        for (auto it2 : it.second)
            if (abs((ld)up / (ld)down - (ld)it2.second / (ld)good[it2.first]) > 1e-2)
            {
                cout << 0 << endl;
                return 0;
            }
    }
    ll ans = 0;
    for (ll i = 1; i * i <= cur; i++)
        if (cur % i == 0)
        {
            ans++;
            if (i * i != cur)
                ans++;
        }
    cout << ans << endl;
    return 0;
}

int32_t main()
{
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
    #endif
    int T = 100;
    //cin >> T;
    for (int i = 1; i <= T; i++)
    {
        #ifdef ONPC
            cerr << "Test #" << i << ":\n";
        #endif
        if (solve())
            break;
        #ifdef ONPC
            cerr << "_______________________________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1000LL / CLOCKS_PER_SEC << " ms" << endl;
    #endif
    return 0;
}