#ifdef ONPC
    # define _GLIBCXX_DEBUG
    #define deb(a) cerr << "========" << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <bits/stdc++.h>

using namespace std;
mt19937 rnd(239);

#define X first
#define Y second
#define pb push_back
#define eb emplace_back
#define ob pop_back
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<bool> vb;

int solve()
{
    ll n;
    if (!(cin >> n))
        return 1;
    ll m;
    cin >> m;
    if (n <= 1000)
    {
        int ans = 0;
        for (int i = 1; i <= n; i++)
            if (i % m == 0)
                ans += i % 10;
        cout << ans << '\n';
        return 0;
    }
    vector<int> c;
    c.push_back(m % 10);
    ll x = 2;
    while (true)
    {
        ll cur = x * m;
        if (c[0] == cur % 10)
            break;
        c.push_back(cur % 10);
        x++;
    }
    ll t = n / m;
    ll sum = 0;
    for (int i : c)
        sum += i;
    ll q = t / (ll)sz(c);
    ll z = t % (ll)sz(c);
    ll ans = q * sum;
    for (int i = 0; i < z; i++)
        ans += c[i];
    cout << ans << '\n';
    return 0;
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    cin >> TET;
    while (TET--)
    {
        if (solve())
            break;
        #ifdef ONPC
            cout << "\n__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}