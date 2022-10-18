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
#include <iomanip>

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
    if (!(cin >> n))
        return 1;
    int q;
    cin >> q;
    vector<int> l(q), r(q);
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < q; i++)
    {
        cin >> l[i] >> r[i];
        l[i]--;
        cnt[l[i]]++;
        cnt[r[i]]--;
    }
    for (int i = 1; i <= n; i++)
        cnt[i] += cnt[i - 1];
    vector<int> c1(n + 1, 0), c2(n + 1, 0);
    int kek = 0;
    for (int i = 0; i < n; i++)
        if (!cnt[i])
            kek++;
    for (int i = 0; i < n; i++)
    {
        c1[i + 1] = c1[i];
        c2[i + 1] = c2[i];
        if (cnt[i] == 1)
            c1[i + 1]++;
        if (cnt[i] == 2)
            c2[i + 1]++;
    } 
    int ans = 1e9;
    for (int i = 0; i < q; i++)
        for (int j = i + 1; j < q; j++)
        {
            int cur = 0;
            cur = c1[r[i]] - c1[l[i]] + c1[r[j]] - c1[l[j]];
            int L = max(l[i], l[j]);
            int R = min(r[i], r[j]);
            if (L <= R)
                cur += c2[R] - c2[L];
            ans = min(ans, cur);
        }
    cout << n - (ans + kek) << '\n';
    return 0;
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