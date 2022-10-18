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

#define sz(a) (int)((a).size())

using namespace std;

typedef long long ll;
typedef long double ld;

int solve()
{
    ios::sync_with_stdio(0);
    int n;
    if (!(cin >> n))
    {
        return 1;
    }
    vector<ll> v(n), t(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }
    vector<ll> ans(n, 0), kek(n, 0);
    vector<ll> t1 = t;
    for (int i = 1; i < n; i++)
    {
        t[i] += t[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        ll curt = 0;
        if (i)
        {
            curt = t[i - 1];
        }
        int l = i - 1, r = n;
        while (r - l > 1)
        {
            int mid = (r + l) / 2;
            if (t[mid] - curt >= v[i])
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        if (r < n)
        {
            ll tau = 0;
            if (l >= 0)
            {
                tau = t[l] - curt;
            }
            ans[r] += v[i] - tau;
            kek[r]--;
            kek[i]++;
        }
        else
        {
            kek[i]++;
        }
    }
    for (int i = 1; i < n; i++)
    {
        kek[i] += kek[i - 1];
    }
    t = t1;
    for (int i = 0; i < n; i++)
    {
        ans[i] += kek[i] * t[i];
    }
    for (ll i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

int32_t main()
{
    int T = 1;
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
    #endif
    for (int i = 1;; i++)
    //cin >> T; for (int i = 0; i < T; i++)
    {
        #ifdef ONPC
            cout << "Test #" << i << ":\n";
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