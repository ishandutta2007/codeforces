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

const int N = 10000;

int a[N], b[N];
int q[] = {1, 5, 10, 50};

int solve()
{
    ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    if (n > 20)
    {
        cout << 49LL * (n - 20) + 733LL << endl;
        return 1;
    }
    a[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int i = 0; i < N; i++)
            b[i] = 0;
        for (int i = 0; i < N; i++)
        {
            if (a[i])
                for (int j = 0; j < 4; j++)
                    if (i + q[j] < N)
                        b[i + q[j]] = 1;
        }
        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            a[i] = b[i];
            ans += b[i];
        }
        if (i == n)
        {
            cout << ans << endl;
            return 1;
        }
    }
    return 1;
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