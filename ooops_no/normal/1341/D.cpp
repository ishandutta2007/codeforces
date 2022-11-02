#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
#define sz(x) ((long long)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
 
/*
#pragma GCC optimize("unroint-loops")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#pragma GCC optimize "-O3"
*/
 
const ld eps = 1e-9;
const ld pi = acosl(-1);
const int mod = 998244353;
const int mod1 = 1e9 + 7;
 
mt19937_64 rnd(time(0));
 
void faster()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
}
 
signed main() {
    faster();
    // freopen("substr.in", "r", stdin);
    // freopen("substr.out", "w", stdout);
    //______________________________________
    /*__*/double start = clock();/*__*/
    //_____________________________________
    ll n, k;
    cin >> n >> k;
    string a[10] = {
            "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"
    };
    vector <vector <ll> > cnt(n, vector <ll>(10, 0));
    vector <bool> need(n, false);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int z = 0; z < 10; z++)
        {
            ll ok = 0;
            for (int j = 0; j < 7; j++)
            {
                if (s[j] == '1')
                    need[i] = true;
                if (a[z][j] == '1' && s[j] != '1')
                    ok++;
                if (a[z][j] == '0' && s[j] == '1')
                {
                    ok = -1;
                    break;
                }
            }
            cnt[i][z] = ok;
        }
    }
    vector < set <ll> > lol(n + 1);
    for (int z = 0; z < 10; z++)
    {
        lol[n].insert(0);
    }
    for (int i = n - 1; i > 0; i--)
    {
        for (int z = 0; z < 10; z++)
        {
            if (cnt[i][z] == -1) continue;
            for (auto w : lol[i + 1])
            {
                if (w + cnt[i][z] <= k)
                {
                    lol[i].insert(w + cnt[i][z]);
                }
            }
        }
    }
    vector <ll> ans;
    for (int i = 0; i < n; i++)
    {
        bool ok = false;
        for (int z = 9; z >= 0 && !ok; z--)
        {
            if (cnt[i][z] == -1) continue;
            for (auto w : lol[i + 1])
            {
                if (w + cnt[i][z] == k)
                {
                    k -= cnt[i][z];
                    ans.push_back(z);
                    ok = true;
                    break;
                }
            }
        }
        if (!ok && need[i])
        {
            cout << -1;
            return 0;
        }
    }
    if (sz(ans) == 0)
        cout << -1;
    else
        for (auto i : ans)
        cout << i;
    //______________________________________
    cerr << "Time " << (clock() - start)  * 1.0 / CLOCKS_PER_SEC << "s\n";
    return 0;
}