#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second
#define chkmin(a, b) (a = ((a > b) ? b : a))
#define chkmax(a, b) (a = ((a < b) ? b : a))

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
#include <set>
#include <map>
#include <random>
#include <memory>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ld, ld> pld;
typedef pair<ll, int> pdi;
typedef ll T;

vector<vector<int>> idxvec;
map<vector<int>, int> vecidx;

void gen(int i, int crsm, vector<int> cur) {
    if (i == 4) {
        cur[i] = 8 - crsm;
        int mysz = idxvec.size();
        idxvec.push_back(cur);
        vecidx[cur] = mysz;
        return;
    }
    for (int j = 8-crsm; j>=0; j--) {
        cur[i] = j;
        gen(i + 1, crsm + j, cur);
    }
}

const int sz = 500;
vector<pii> adj[sz][sz], radj[sz][sz];
int dp[sz][sz];//0 draw, 1 alice, 2 bob
int indeg[sz][sz];


void calc(int as, int bs) {
    vector<int> av = idxvec[as], bv = idxvec[bs];
    foru(i, 1, 5) {
        foru(j, 1, 5) {
            if (av[i] && bv[j]) {
                int sm = (i + j) % 5;
                av[sm]++;
                av[i]--;
                int vav = vecidx[av];
                adj[bs][vav].push_back({ as,bs });
                radj[as][bs].push_back({ bs,vav });
                av[i]++;
                av[sm]--;
                indeg[as][bs]++;
                //force other
                /*
                bv[sm]++;
                bv[j]--;
                vav = vecidx[bv];
                adj[vav][as].push_back({ as,bs });
                radj[as][bs].push_back({ vav,as });
                bv[sm]--;
                bv[j]++;
                indeg[as][bs] += 2;
                */
            }
        }
    }
}

void dfs(int as, int bs, bool win) {
    if (!win) {
        for (pii ii : adj[as][bs]) {
            if (!dp[ii.ff][ii.ss]) {
                dp[ii.ff][ii.ss] = 1;
                dfs(ii.ff, ii.ss, !win);
            }
        }
    }
    else {
        for (pii ii : adj[as][bs]) {
            indeg[ii.ff][ii.ss]--;
            if (indeg[ii.ff][ii.ss] == 0) {
                if (dp[ii.ff][ii.ss] == 0) {
                    dp[ii.ff][ii.ss] = 2;
                    dfs(ii.ff, ii.ss, !win);
                }
            }
        }
    }
}

int main() {
    fast;
    gen(0, 0, vector<int>{0, 0, 0, 0, 0});
    foru(i, 1, 495) {
        foru(j, 1, 495) {
            calc(i, j);
        }
    }
    foru(i, 1, 495) {
        dp[0][i] = 1;
        dp[i][0] = 2;
        dfs(0, i, 1);
        dfs(i, 0, 0);
    }
    int t;
    cin >> t;
    while (t--) {
        bool f = 0;
        cin >> f;
        vector<int> av(5), bv(5);
        const int n = 8;
        foru(i, 0, n) {
            int x;
            cin >> x;
            av[x]++;
        }
        foru(i, 0, n) {
            int x;
            cin >> x;
            bv[x]++;
        }
        if (f)swap(av, bv);
        int as = vecidx[av], bs = vecidx[bv];
        int val = dp[as][bs];
        if (val == 0)cout << "Deal\n";
        else if ((val == 1) ^ (!f))cout << "Bob\n";
        else cout << "Alice\n";
    }
    return 0;
}