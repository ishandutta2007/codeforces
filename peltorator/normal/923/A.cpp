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

const int N = 1000005;

int p[N];
vector<int> pr;

int solve()
{
    ios::sync_with_stdio(0);
    int n;
    if (!(cin >> n))
    {
        return 1;
    }
    for (int i = 0; i < N; i++)
    {
        p[i] = 1;
    }
    pr.clear();
    for (int i = 2; i < N; i++)
    {
        if (p[i])
        {
            pr.push_back(i);
            for (int j = i + i; j < N; j += i)
            {
                p[j] = 0;
            }
        }
    }
    int maxp = 1;
    int k = n;
    int l = n;
    for (int i = 2; i * i <= k; i++)
    {
        if (k % i == 0)
        {
            while (k % i == 0)
            {
                k /= i;
            }
            l = min(l, max(n - i + 1, i + 1));
        }
    }
    if (k > 1)
    {
        l = min(l, max(n - k + 1, k + 1));
    }
    int r = n;
    l = max(l, 3);
    int ans = n;
    for (int i = 0; i < pr.size(); i++)
    {
        int p = pr[i];
        int t = (l + p - 1) / p;
        t *= p;
        if (t <= r && t >= 3)
        {
            ans = min(ans, max(t - p + 1, p + 1));
        }
    }
    cout << ans << endl;
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