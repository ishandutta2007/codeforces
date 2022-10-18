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

mt19937 rnd(239);

typedef long long ll;
typedef long double ld;

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    ll t;
    cin >> t;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i], x[i]--;
    for (int i = 0; i < n; i++)
        if (x[x[i]] != x[i])
        {
            cout << "No\n";
            return 0;
        }
    for (int i = 0; i < n; i++)
        if (x[i] < i)
        {
            cout << "No\n";
            return 0;
        }
    for (int i = 1; i < n; i++)
        if (x[i] < x[i - 1])
        {
            cout << "No\n";
            return 0;
        }
    vector<ll> b(n);
    for (int i = 0; i < n; i++)
        if (x[i] == i)
        {
            b[i] = a[i] + t;
            if (i)
                b[i] = max(b[i], b[i - 1] + 1);
            if (i + 1 < n && a[i + 1] + t <= b[i])
            {
                cout << "No\n";
                return 0;
            }
        }
        else
        {
            b[i] = a[i + 1] + t;
            if (i)
                b[i] = max(b[i], b[i - 1] + 1);
        }
    cout << "Yes\n";
    for (int i = 0; i < n; i++)
        cout << b[i] << ' ';
    cout << endl;
    return 0;
}

int32_t main()
{
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
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
            cout << "_______________________________\n";
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1000LL / CLOCKS_PER_SEC << " ms" << endl;
    #endif
    return 0;
}