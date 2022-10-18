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

const ll P = 1e9 + 7, Q = 1e9 + 9;
const int N = 1e5;

vector<ll> add[N];

int solve()
{
    ios::sync_with_stdio(0);
    int n;
    if (!(cin >> n))
    {
        return 1;
    }
    vector<ll> a(n + 1, 0), b(n + 1, 0);
    int q;
    for (int i = 0; i < N; i++)
        add[i].clear();
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int l, r, x;
        cin >> l >> r >> x;
        l--;
        add[l].push_back(x);
        add[r].push_back(-x);
    }
    vector<int> can(n + 1, 0);
    a[0] = b[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j : add[i])
        {
            if (j > 0)
            {
                for (int k = n; k >= j; k--)
                {
                    a[k] += a[k - j];
                    if (a[k] >= P)
                        a[k] -= P;
                    b[k] += b[k - j];
                    if (b[k] >= Q)
                        b[k] -= Q;
                }
            }
            else
            {
                int J = -j;
                for (int k = J; k <= n; k++)
                {
                    a[k] -= a[k - J];
                    if (a[k] < 0)
                        a[k] += P;
                    b[k] -= b[k - J];
                    if (b[k] < 0)
                        b[k] += Q;
                }
            }
        }
        for (int i = 1; i <= n; i++)
            if (a[i] || b[i])
                can[i] = 1;
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++)
        if (can[i])
            ans.push_back(i);
    cout << ans.size() << endl;
    for (int i : ans)
        cout << i << ' ';
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