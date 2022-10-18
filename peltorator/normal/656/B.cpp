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
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

using namespace std;

typedef long long ll;
typedef long double ld;

int m[100], r[100];

int solve()
{
    ios::sync_with_stdio(0);
    int n;
    cout.precision(30);
    if (!(cin >> n))
        return 1;
    int t = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> m[i];
        t *= m[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> r[i];
    }
    int k = 0;
    t = 1000000;
    for (int i = 0; i < t; i++)
    {
        bool ok = false;
        for (int j = 0; j < n; j++)
        {
            if (i % m[j] == r[j])
            {
                ok = true;
            }
        }
        if (ok)
        {
            k++;
        }
    }
    cout << (ld)k / (ld)t;
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