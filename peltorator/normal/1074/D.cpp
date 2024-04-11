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

#ifdef ONPC
    #define deb(a) cerr << "       " << #a << " = " << a << endl;
#else
    #define deb(a)
#endif

using namespace std;

mt19937 rnd(time(0));

typedef long long ll;
typedef long double ld;

const int N = 500001;

vector<int> g[N];

int p[N], sz[N];
ll cnt[N];

int solve()
{
    int q;
    if (!(cin >> q))
        return 1;
    int cur = 0;
    map<ll, int> mapa;
    ll last = 0;
    for (int i = 0; i < N; i++)
    {
        g[i].clear();
        g[i].push_back(i);
        cnt[i] = 0;
        sz[i] = 1;
        p[i] = i;
    }
    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            ll l, r, x;
            cin >> l >> r >> x;
            l ^= last;
            r ^= last;
            x ^= last;
         //   cout << "       " << l << ' ' << r << ' ' << x << endl;
            if (l > r)
                swap(l, r);
            l--;
            if (!mapa.count(l))
                mapa[l] = cur++;
            if (!mapa.count(r))
                mapa[r] = cur++;
            l = mapa[l];
            r = mapa[r];
            int L = p[l];
            int R = p[r];
            if (L != R)
            {
                if (sz[L] < sz[R])
                    swap(L, R);
                ll f = (cnt[r] ^ x ^ cnt[l]);
                for (int i : g[R])
                {
                    g[L].push_back(i);
                    p[i] = L;
                    cnt[i] ^= f;
                }
                g[R].clear();
                sz[L] += sz[R];
                sz[R] = 0;
            }
        }
        else
        {
            ll l, r;
            cin >> l >> r;
             l ^= last;
            r ^= last;
         //   cout << "       " << l << ' ' << r  << endl;
            if (l > r)
                swap(l, r);
            l--;
            if (!mapa.count(l))
                mapa[l] = cur++;
            if (!mapa.count(r))
                mapa[r] = cur++;
            l = mapa[l];
            r = mapa[r];
            if (p[l] == p[r])
            {
                last = (cnt[l] ^ cnt[r]);
                cout << last << '\n';
            }
            else
            {
                last = 1;
                cout << "-1\n";
            }
        }
    }
    return 0;   
}

int32_t main()
{
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0); ios::sync_with_stdio(0);
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