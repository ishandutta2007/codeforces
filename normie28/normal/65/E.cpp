
// Problem : E. Harry Potter and Moving Staircases
// Contest : Codeforces - Codeforces Beta Round #60
// URL : https://codeforces.com/contest/65/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

//----------NMFF0B0H----------//
#include <bits/stdc++.h>
#define IM using
#define GAY namespace
#define LOL std;
IM GAY LOL
/*
Search the term 'algorithm visualization' in your favorite Search Engine, do you see VisuAlgo in the first page of the search result :)? Next level: Search that term again, but in your native language (if it is not English). Is VisuAlgo still listed in the first page? :). And get ready to be surprised: Search the name of your favorite data structure or algorithm without mentioning the keyword 'animation' or 'visualization'. Is VisuAlgo still listed in the first page? :):).
*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define FILE_IN "caps.inp"
#define FILE_OUT "caps.out"
#define ofile                     \
    freopen(FILE_IN, "r", stdin); \
    freopen(FILE_OUT, "w", stdout)
#define fio                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define nfio    \
    cin.tie(0); \
    cout.tie(0)
#define ord(a, b, c) ((a >= b) and (b >= c))
#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define MOD (ll(18101203))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1) << x)
#define PII pair<int, int>
#define piii pair<int, pii>
#define For(i, __, ___) for (int i = __; i <= ___; i++)
#define Rep(i, __, ___) for (int i = __; i >= ___; i--)
#define ordered_set tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update>
#define endl "\n"
#define vi vector<int>
#define bi bigint
#define get geet
#define list_of_primes {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997}
typedef long long LL; 
//--------END----------//

 
struct S {
    int ind;
    bool staircase;
    S(int ind, bool staircase) : ind(ind), staircase(staircase) {}
    S() {}
};
 
int n, m;
vector<PII> g[100000];
bool can[100000] = {};
int vis[100000] = {};
int ind = 0;
bool flag = false;
int sind[200000], sfrom[200000], sto[200000], sc = 0;
vector<S> ans;
 
void mark(int v) {
    can[v] = true;
    for (PII to : g[v]) if (!can[to.first]) {
        mark(to.first);
    }
}
 
int findUnmarked() {
    while (ind < n && (can[ind] || (!flag && g[ind].empty()))) ++ind;
    if (ind == n && !flag) {
        flag = true;
        ind = 0;
        return findUnmarked();
    }
    return ind;
}
 
void dfs(int v) {
    ans.pb(S(v, false));
    vis[v] = 1;
    for (PII to : g[v]) {
        if (vis[to.first] == 0) {
            dfs(to.first);
            ans.pb(S(v, false));
        }
        if (vis[to.first] == 2) {
            int cur = findUnmarked();
            if (cur != n) {
                sind[sc] = to.second;
                sfrom[sc] = v;
                sto[sc] = cur;
                ans.pb(S(sc++, true));
                mark(cur);
                dfs(cur);
                ans.pb(S(v, false));
            }
        }
    }
    vis[v] = 2;
}
 
int tin[100000], fup[100000], timer = 0;
int bestInd = -1, bestFrom, bestTo;
void dfs2(int v, int p) {
    tin[v] = fup[v] = timer++;
    for (PII to : g[v]) if (to.second != p) {
        if (tin[to.first] == -1) {
            dfs2(to.first, to.second);
            if (fup[to.first] < tin[to.first] && bestInd == -1) {
                bestInd = to.second;
                bestFrom = v;
                bestTo = to.first;
            }
            fup[v] = min(tin[v], fup[to.first]);
        } else {
            if (bestInd == -1) {
                bestInd = to.second;
                bestFrom = v;
                bestTo = to.first;
            }
            fup[v] = min(tin[v], tin[to.first]);
        }
    }
}
 
int main() {
    scanf("%d%d", &n, &m);
    if (n == 1) {
        printf("YES\n0\n1 1\n");
        return 0;
    }
    REP(i, m) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(mp(to, i));
        g[to].pb(mp(from, i));
    }
    int st = 0;
    if (g[0].empty()) {
        REP(i, n) tin[i] = -1;
        REP(i, n) if (tin[i] == -1 && bestInd == -1) {
            dfs2(i, -1);
        }
        if (bestInd == -1) {
            REP(i, n) if ((int)g[i].size() > 1) {
                bestInd = g[i][0].second;
                bestFrom = i;
                bestTo = g[i][0].first;
                break;
            }
        }
        if (bestInd == -1) {
            printf("NO\n");
            return 0;
        }
        g[bestFrom].erase(find(g[bestFrom].begin(), g[bestFrom].end(), mp(bestTo, bestInd)));
        g[bestTo].erase(find(g[bestTo].begin(), g[bestTo].end(), mp(bestFrom, bestInd)));
        st = bestFrom;
        ans.pb(S(0, false));
        sind[0] = bestInd;
        sfrom[0] = bestFrom;
        sto[0] = 0;
        ans.pb(S(0, true));
        ++sc;
        vis[0] = can[0] = true;
    }
    mark(st);
    dfs(st);
    REP(i, n) if (!vis[i]) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    int cnt = 0;
    for (S x : ans) if (x.staircase) ++cnt;
    printf("%d\n", cnt);
    for (int beg = 0; beg < (int)ans.size(); ) {
        if (ans[beg].staircase) {
            int ind = ans[beg].ind;
            printf("%d %d %d\n", sind[ind] + 1, sfrom[ind] + 1, sto[ind] + 1);
            ++beg;
        } else {
            int end = beg + 1;
            while (end < (int)ans.size() && !ans[end].staircase) ++end;
            printf("%d", end - beg);
            for (int i = beg; i < end; ++i) {
                printf(" %d", ans[i].ind + 1);
            }
            printf("\n");
            beg = end;
        }
    }
    return 0;
}