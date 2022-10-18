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

const ll MOD = 1e9 + 7;

int duga(int x, int y)
{
    return (x ^ y);
}

int dvedugi(int x, int y)
{
    return (x | y);
}

int pryamo(int x, int y)
{
    return (x & y);
}

int solve()
{
    ios::sync_with_stdio(0);
    int a, b, c, d;
    if (!(cin >> a))
    {
        return 1;
    }
    cin >> b >> c >> d;
    int x = duga(a, b);
    int y = dvedugi(c, d);
    int z = pryamo(b, c);
    int t = duga(a, d);
    int A = pryamo(x, y);
    int B = dvedugi(z, t);
    int ans = duga(A, B);
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