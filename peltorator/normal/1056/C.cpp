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

int solve()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> p(2 * n), from(2 * n, -1), used(2 * n, 0);
    set<pair<int, int> > good;
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> p[i];
        good.insert({-p[i], i});
    }
    vector<int> f(m), s(m);
    set<int> pr;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if (p[x] < p[y])
            swap(x, y);
        f[i] = x;
        s[i] = y;
        pr.insert(i);
        from[x] = from[y] = i;
        good.erase({-p[x], x});
        good.erase({-p[y], y});
    }
    int t;
    cin >> t;
    int need = -1;
    int cnt = 0;
    if (t == 2)
    {
        cnt++;
        int k;
        cin >> k;
        k--;
        used[k] = 1;
        need = from[k];
        good.erase({-p[k], k});
    }
    while (cnt < 2 * n)
    {
        if (need != -1)
        {
            if (!used[f[need]])
            {
                cout << f[need] + 1 << endl;
                used[f[need]] = 1;
            }
            else
            {
                cout << s[need] + 1 << endl;
                used[s[need]] = 1;
            }
            pr.erase(need);
        }
        else
        {
            if (pr.size())
            {
                int it = *pr.begin();
                cout << f[it] + 1 << endl;
                used[f[it]] = 1;
                pr.erase(it);
            }
            else
            {
                int it = good.begin()->second;
                good.erase(good.begin());
                used[it] = 1;
                cout << it + 1 << endl;
            }
        }
        cnt++;
        if (cnt < 2 * n)
        {
            int k;
            cin >> k;
            k--;
            used[k] = 1;
            if (pr.count(from[k]))
                need = from[k];
            else
                need = -1;
            good.erase({-p[k], k});
        }
        cnt++;
    }
    return 1;
}

int32_t main()
{
    #ifdef ONPC
   //     freopen("in.txt", "r", stdin);
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