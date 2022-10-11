// Not my code https://codeforces.com/contest/382/submission/148209528

#pragma GCC optimize ("O3")

#include "bits/stdc++.h"
using namespace std;
 
#ifdef PRABH
#include "debug.h"
#else
#define dbg(...)
#endif
 
#define ld long double
#define pb push_back
#define all(v) begin(v), end(v)
const int N = 4e6 + 10;  // verify before using
 
template <typename T> bool ckmin(T& a, T b) { return b < a && (a = b, true); }
template <typename T> bool ckmax(T& a, T b) { return b > a && (a = b, true); }
 
vector<int> adjList[N];
int cnt;
 
int dfs(int u) {
    cnt--;
    int ans = 0;
    for (int v : adjList[u]) {
        ckmax(ans, dfs(v));
    }
 
    return ans + 1;
}
 
void testCase() {
    int n, m;
    cin >> n >> m;
    vector<int> root;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c != '#') {
                int ni = i, nj = j;
                if (c == '<') nj--;
                if (c == '>') nj++;
                if (c == '^') ni--;
                if (c == 'v') ni++;
                cnt++;
                adjList[ni * m + nj].pb(i * m + j);
            } else
                root.pb(i * m + j);
        }
    }
 
    pair<int, int> ans = {0, 0};
 
    auto merge = [&](int x) {
        if (x >= ans.first) {
            ans.second = ans.first;
            ans.first = x;
        } else if (x > ans.second) {
            ans.second = x;
        }
    };
 
    for (int i : root) {
        for (int j : adjList[i]) {
            merge(dfs(j));
        }
    }
 
    int tot = ans.first + max(ans.second, ans.first - 1);
    cout << (cnt ? -1 : tot);
}
 
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t_c = 1;
    // cin >> t_c;
    for (int testNo = 1; testNo <= t_c; testNo++) {
        // cout << "Case #" << testNo << ": ";
        testCase();
    }
}