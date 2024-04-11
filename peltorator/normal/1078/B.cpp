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

const int MOD = 1e9 + 7;
const int N = 110;
const int M = 10005;

int c[N][N];

int kn[N][M];

int solve()
{
    int n;
    if (!(cin >> n))
        return 1;
    vector<int> a(n);
    set<int> q;
    for (int &i : a)
        cin >> i, q.insert(i);
    if (q.size() < 3)
    {
        cout << n << endl;
        return 0;
    }
    for (int i = 0; i < N; i++)
        c[i][0] = 1;
    for (int i = 1; i < N; i++)
        for (int j = 1; j < N; j++)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
    sort(a.begin(), a.end());
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            kn[j][i] = 0;
    kn[0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = M - a[i] - 1; j >= 0; j--)
            for (int k = 0; k < n; k++)
                if (kn[k][j])
                    kn[k + 1][j + a[i]] = (kn[k + 1][j + a[i]] + kn[k][j]) % MOD;
    int ans = 0;
    for (int i = 0; i < n;)
    {
        int j = i;
        while (j < n && a[i] == a[j])
            j++;
        int cnt = j - i;
        for (int k = 1; k <= cnt; k++)
            if (kn[k][a[i] * k] == c[cnt][k])
                ans = max(ans, k);
        i = j;
    }
    cout << ans << endl;
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