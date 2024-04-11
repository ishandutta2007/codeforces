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

int gcd(int a, int b)
{
    while (a)
    {
        b %= a;
        swap(a, b);
    }
    return b;
}

const int N = 300003;

int solve()
{
    int n;
    cin >> n;
    set<int> q;
    int g = 0;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            cout << 1 << endl;
            return 1;
        }
        g = gcd(g, t);
        int j = 1;
        for (int k = 2; k * k <= t; k++)
            if (t % k == 0)
            {
                while (t % k == 0)
                    t /= k;
                j *= k;
            }
        j *= t;
        q.insert(j);
    }
    if (g != 1)
    {
        cout << -1 << endl;
        return 1;
    }
    vector<int> a;
    for (int i : q)
        a.push_back(i);
    n = a.size();
    vector<int> v(N, 0);
    for (int i : a)
    {
        for (int j = 1; j * j < i; j++)
            if (i % j == 0)
            {
                v[j]++;
                v[i / j]++;
            }
        int sq = 1;
        while (sq * sq < i)
            sq++;
        if (sq * sq == i)
            v[sq]++;
    }
    vector<vector<int> > b(n);
    for (int i = 0; i < n; i++)
    {
        int j = a[i];
        for (int k = 2; k * k <= j; k++)
            if (j % k == 0)
            {
                j /= k;
                b[i].push_back(k);
            }
        if (j != 1)
            b[i].push_back(j);
    }
    for (int ans = 2; ; ans++)
    {
        vector<vector<int> > nxt;
        for (int i = 0; i < b.size(); i++)
        {
            int k = b[i].size();
            int B = (1 << k);
            vector<int> cur(B, 0), val = cur;
            val[0] = 1;
            for (int j = 1; j < B; j++)
            {
                int ind = 0;
                while (!((j >> ind) & 1))
                    ind++;
                val[j] = val[(j ^ (1 << ind))] * b[i][ind];

            }
            for (int j = 0; j < B; j++)
                cur[j] = v[val[j]];
            for (int i = 0; i < k; i++) 
                for (int j = 0; j < B; j++) 
                    if (((j >> i) & 1))
                        cur[j - (1 << i)] -= cur[j];
            if (cur[0])
            {
                cout << ans << endl;
                return 1;
            }
            for (int ind = 0; ind < B; ind++)
                if (cur[ind])
                {
                    vector<int> cur;
                    for (int j = 0; j < k; j++)
                        if (((ind >> j) & 1))
                            cur.push_back(b[i][j]);
                    nxt.push_back(cur);
                }
        }
        sort(nxt.begin(), nxt.end());
        b.clear();
        for (int i = 0; i < nxt.size(); i++)
            if (!i || nxt[i - 1] != nxt[i])
                b.push_back(nxt[i]);
    }
    return 1;
}

int32_t main()
{
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0); cin.tie(0);
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