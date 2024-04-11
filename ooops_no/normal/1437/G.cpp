#include<bits/stdc++.h>
using namespace std;

#pragma GCC target("avx,avx2,sse3,ssse3,sse4.1,sse4.2,tune=native")
#pragma GCC optimize(3)
#pragma GCC optimize("O3")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#define pb push_back

const int K = 550;
const int N = 3e5 + 10;
int mp[N][26];
multiset<int> d[N];
vector<int> po1(N), po2(N);
int now = 1;
const long long p = 29, MOD = 1000009597;
const long long p1 = 27, MOD1 = 1e9 + 7;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    po1[0] = po2[0] = 1;
    for (int i = 1; i < N; ++i){
        po1[i] = (long long) po1[i - 1] * p;
        po1[i] %= MOD;
        po2[i] = (long long) po2[i - 1] * p1;
        po2[i] %= MOD1;
    }
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    vector<int> go(n);
    vector<int> val(n);
    vector<pair<int, pair<pair<int, int>,int>>> lol;
    for (int i = 0; i < n; ++i){
        string s;
        cin >> s;
        v[i] = s;
        if (s.size() < K){
            int v = 1;
            for (int j = 0; j < s.size(); ++j){
                if (mp[v][s[j] - 'a'] == 0){
                    mp[v][s[j] - 'a'] = ++now;
                }
                v = mp[v][s[j] - 'a'];
            }
            go[i] = v;
            d[v].insert(0);
        }
        else{
            long long hsh = 0, hsh1 = 0;
            for (int j = 0; j < s.size(); ++j){
                hsh = hsh * p + s[j];
                hsh %= MOD;
                hsh1 = hsh1 * p1 + s[j];
                hsh1 %= MOD1;
            }
            lol.pb({s.size(), {{hsh, hsh1}, i}});
        }
    }
    sort(lol.begin(), lol.end());
    for (int i = 0; i < m; ++i){
        int t;
        cin >> t;
        if (t == 1){
            int j, x;
            cin >> j >> x;
            j--;
            if (v[j].size() < K){
                d[go[j]].erase(d[go[j]].find(-val[j]));
                val[j] = x;
                d[go[j]].insert(-val[j]);
            }
            else{
                val[j] = x;
            }
        }
        else{
            string t;
            cin >> t;
            int ans = -1;
            for (int i = 0; i < t.size(); ++i){
                int v = 1;
                for (int j = i; j < min(i + K + 1, (int)t.size()); ++j){
                    if (mp[v][t[j] - 'a'] == 0) break;
                    else{
                        v = mp[v][t[j] - 'a'];
                        if (d[v].size() > 0){
                            ans = max(ans, abs(*d[v].begin()));
                        }
                    }
                }
            }
            vector<int> h(t.size() + 1), h2(t.size() + 1);
            for (int i = 0; i < t.size(); ++i){
                h[i + 1] = ((long long)h[i] * p % MOD + t[i]);
                h[i + 1] %= MOD;
                h2[i + 1] = ((long long)h2[i] * p1 % MOD1 + t[i]);
                h2[i + 1] %= MOD1;
            }
            for (int i = 0; i < t.size(); ++i){
                for (auto to : lol){
                    if (i + 1 >= to.first){
                        if (to.second.first.first == (((h[i + 1] - ((long long) h[i + 1 - to.first] * ( long long ) po1[to.first]) % MOD ) + MOD) % MOD)){
                            if (to.second.first.second == (((h2[i + 1] - ((long long) h2[i + 1 - to.first] * ( long long ) po2[to.first]) % MOD1) + MOD1) % MOD1)){
                                ans = max(ans, val[to.second.second]);
                            }
                        }
                    }
                    else break;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}