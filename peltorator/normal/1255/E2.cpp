#ifdef ONPC
    # define _GLIBCXX_DEBUG
    #define deb(a) cerr << "========" << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <bits/stdc++.h>
//#define string basic_string<unsigned char>
#define char unsigned char

using namespace std;
//mt19937 rnd(239);
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    vector<ll> a(n);
    ll sum = 0;
    vector<int> pos;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i])
        {
            sum += a[i];
            pos.push_back(i);
        }
    }
    vector<ll> ds;
    //ds.push_back(sum);
    ll summ = sum;
    for (ll i = 2; i * i <= summ; i++)
        if (summ % i == 0)
        {
            ds.push_back(i);
            while (summ % i == 0)
                summ /= i;
//            if (i * i != sum)
//                ds.push_back(sum / i);
        }
    if (summ > 1)
        ds.push_back(summ);
    if (sum == 1)
    {
        cout << "-1\n";
        return 0;
    }
    ll anss = 1e18;
    for (ll d : ds)
    {
        if (clock() * 1.0 / CLOCKS_PER_SEC > 0.8)
            break;
        ll ans = 0;
        ll curpos = 0;
        vector<ll> b = a;
        for (ll i = 0; i < sum / d; i++)
        {
            if (a[pos[curpos]] >= d)
            {
                i += a[pos[curpos]] / d - 1;
                a[pos[curpos]] %= d;
                continue;
            }
            int x = curpos;
            ll ss = 0;
            while (ss * 2 < d)
                ss += a[pos[x]], x++;
            x--;
            x = pos[x];
            ss = 0;
            int nps = curpos;
            while (ss < d)
            {
                ll t = min(d - ss, a[pos[nps]]);
                ans += t * abs(x - pos[nps]);
                ss += t;
                a[pos[nps]] -= t;
                if (ss < d)
                    nps++;
            }
            curpos = nps;
        }
        a = b;
        anss = min(anss, ans);
    }
    cout << anss << '\n';
    return 0;
}

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    // cin >> TET;
    for (int i = 1; i <= TET; i++)
    {
        if (solve())
            break;
        cout << '\n';
        #ifdef ONPC
            cout << "\n__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}