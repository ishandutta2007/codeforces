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

const ll INF = 1e18;

ll len;

ll dist(ll q)
{
    q = abs(q);
    return min(q, len - q);
}

vector<ll> a, b;

ll dist(int i, int j)
{
    return dist(a[i] - b[j]);
}

int solve()
{
    ios::sync_with_stdio(0);
    int n;
    if (!(cin >> n))
    {
        return 1;
    }
    cin >> len;
    a.assign(n, 0);
    b.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll l = 0, r = len / 2LL;
    vector<int> rev(n);
    for (int i = 0; i < n; i++)
    {
        rev[i] = 0;
        if (dist(i, 0) < dist(i, n - 1))
            rev[i] = n - 1;
        ll t = (a[i] + len / 2) % len;
        int x = lower_bound(b.begin(), b.end(), t) - b.begin();
        for (int j = x - 5; j <= x + 5; j++)
        {
            int k = j;
            while (k < 0)
                k += n;
            while (k >= n)
                k -= n;
            if (dist(i, rev[i]) < dist(i, k))
                rev[i] = k;
        }
        x = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        ll best = min(dist(i, 0), dist(i, n - 1));
        for (int j = x - 5; j <= x + 5; j++)
        {
            int k = j;
            while (k < 0)
                k += n;
            while (k >= n)
                k -= n;
            best = min(best, dist(i, k));
        }
        l = max(l, best);
    }
    l--;
    while (r - l > 1)
    {
        ll mid = (r + l) / 2LL;
        vector<int> pl(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            if (dist(i, rev[i]) <= mid)
            {
                pl[0]++;
                pl[n]--;
                continue;
            }
            ll t = (a[i] - mid + len) % len;
            int x = lower_bound(b.begin(), b.end(), t) - b.begin();
            x = (x - i + n) % n;
            t = (a[i] + mid) % len;
            int y = upper_bound(b.begin(), b.end(), t) - b.begin();
            y = (y + n - 1 - i) % n;
            if (x <= y)
            {
                pl[x]++;
                pl[y + 1]--;
            }
            else
            {
                pl[x]++;
                pl[n]--;
                pl[0]++;
                pl[y + 1]--;
            }
        }
        for (int i = 1; i < n; i++)
            pl[i] += pl[i - 1];
        bool ok = 0;
        for (int i = 0; i < n; i++)
            if (pl[i] == n)
                ok = 1;
     //   for (int i = 0; i < n; i++)
       //     cout << pl[i] << endl;
        if (ok)
            r = mid;
        else
            l = mid;
    }
    cout << r << endl;
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