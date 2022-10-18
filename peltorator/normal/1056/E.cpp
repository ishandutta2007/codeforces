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

const int T = 5;

const ll MOD[T] = {1000000009, 1000000007, 998244353, 213468981, 324523453};
const ll P[T] = {239, 239017, 71, 711, 127};

const int N = 1e6 + 239;
const int B = 350;

ll hs[T][N];
ll st[T][N];

ll get(int ind, int l, int r)//[l;r)
{
    return ((hs[ind][r] - hs[ind][l] * st[ind][r - l]) % MOD[ind] + MOD[ind]) % MOD[ind];
}

int solve()
{
    string s, t;
    cin >> s >> t;
    ll m = t.size();
    ll n = s.size();
    for (int i = 0; i < T; i++)
        for (int j = 0; j < m; j++)
            hs[i][j + 1] = (hs[i][j] * P[i] + (ll)(t[j] - 'a' + 1)) % MOD[i];
    for (int i = 0; i < T; i++)
        st[i][0] = 1;
    for (int i = 0; i < T; i++)
        for (int j = 1; j < N; j++)
            st[i][j] = (st[i][j - 1] * P[i]) % MOD[i];
    int ans = 0;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == '0')
            cnt0++;
        else
            cnt1++;
    int f0 = 0, f1 = 0;
    while (s[f0] != '0')
        f0++;
    while (s[f1] != '1')
        f1++;
    {
        if (cnt0 < cnt1)
        {
            swap(cnt0, cnt1);
            swap(f1, f0);
            for (int i = 0; i < n; i++)
                if (s[i] == '0')
                    s[i] = '1';
                else
                    s[i] = '0';
        }
        for (int l = 1; cnt0 * l <= m; l++)
        {
            int r = (m - cnt0 * l) / cnt1;
            if (r > 0 && l * cnt0 + r * cnt1 == m)
            {
                if (l == r)
                {
                    bool ok = 1;
                    int pos0 = f0 * l, pos1 = f1 * r;
                  //  cout << pos0 << ' ' << pos1 << endl;
                    for (int k = 0; k < T; k++)
                        if (get(k, pos0, pos0 + l) != get(k, pos1, pos1 + r))
                        {
                            ok = 0;
                            break;
                        }
                    if (ok)
                        continue;

                }
                int last0 = -1, last1 = -1;
                bool ok = 1;
                int ind = 0;
                for (int i = 0; i < n; i++)
                {
                    if (s[i] == '0')
                    {
                        if (last0 == -1)
                        {
                            last0 = ind;
                        }
                        else
                        {
                            for (int k = 0; k < T; k++)
                                if (get(k, last0, last0 + l) != get(k, ind, ind + l))
                                {
                                    ok = 0;
                                    break;
                                }
                        }
                        ind += l;
                    }
                    else
                    {
                        if (last1 == -1)
                        {
                            last1 = ind;
                        }
                        else
                        {
                            for (int k = 0; k < T; k++)
                                if (get(k, last1, last1 + r) != get(k, ind, ind + r))
                                {
                                    ok = 0;
                                    break;
                                }

                        }
                        ind += r;
                    }
                    if (!ok)
                        break;
                }
                if (ok)
                {
                    ans++;
                //    cout << l << ' ' << r << endl;
                }
            }
        }
    }
    cout << ans << endl;
    return 1;
}

int32_t main()
{
    #ifdef ONPC
        freopen("in.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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