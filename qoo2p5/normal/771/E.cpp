#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define sz(x) (int) (x).size()
const int INF = (int) 1e9 + 123;

void run();

int main() {
#ifndef LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    run();
    return 0;
}

const int N = (int) 3e5 + 123;
const int L = 20;

int n;
ll a[3][N];
ll p[3][N];
int nxt[3][N];
int up[3][L][N];

pair<int, int> dp1[N];
pair<int, int> dp2[N];
int dp[N];

pair<int, int> upd_state1(int i, pair<int, int> cur) {
    int pos = -cur.second;
    int cnt = 0;
    
    for (int j = L - 1; j >= 0; j--) {
        int npos = up[1][j][pos];
        if (npos <= i) {
            pos = npos;
            cnt += (1 << j);
        }
    }
    
    return {cur.first + cnt, -pos};
}

pair<int, int> upd_state2(int i, pair<int, int> cur) {
    int pos = -cur.second;
    int cnt = 0;
    
    for (int j = L - 1; j >= 0; j--) {
        int npos = up[0][j][pos];
        if (npos <= i) {
            pos = npos;
            cnt += (1 << j);
        }
    }
    
    return {cur.first + cnt, -pos};
}

void run() {
    cin >> n;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            a[2][j] += a[i][j];
        }
    }
    
    for (int i = 0; i < 3; i++) {
        partial_sum(a[i], a[i] + n, p[i]);
        for (int t = 0; t < 20; t++) {
            fill(up[i][t], up[i][t] + n + 1, n + 1);
        }
        map<ll, int> q;
        q[0] = -1;
        int last_l = -1;
        
        for (int j = 0; j < n; j++) {
            if (q.count(p[i][j])) {
                int l = q[p[i][j]] + 1;
                int r = j;
                if (l > last_l) {
                    up[i][0][l] = r + 1;
                }
                last_l = l;
            }
            q[p[i][j]] = j;
        }
        
        for (int j = n - 1; j >= 0; j--) {
            up[i][0][j] = min(up[i][0][j], up[i][0][j + 1]);
            for (int t = 1; t < L; t++) {
                if (up[i][t - 1][j] != n + 1) {
                    up[i][t][j] = up[i][t - 1][up[i][t - 1][j]];
                }
            }
        }
    }
    
    fill(dp, dp + N, -INF);
    fill(dp1, dp1 + N, make_pair(-INF, 0));
    fill(dp2, dp2 + N, make_pair(-INF, 0));
    
    dp[0] = 0;
    dp1[0] = {0, 0};
    dp2[0] = {0, 0};
    
    for (int i = 0; i <= n; i++) {
        if (i > 0) {
            dp[i] = max(dp[i - 1], dp[i]);
        }
        
        if (dp[i] != -INF) {
            dp1[i] = max(dp1[i], {dp[i], -i});
            dp2[i] = max(dp2[i], {dp[i], -i});
        }
        
        if (dp1[i].first != -INF) {
            int pos = -dp1[i].second;
            
            {
                int to = max(pos, i);
                dp[to] = max(dp[to], dp1[i].first);
            }
            
            {
                int to = up[0][0][i];
                if (to != n + 1) {
                    dp1[to] = max(dp1[to], upd_state1(to, {dp1[i].first + 1, -pos}));
                }
            }
            
            {
                int to = up[1][0][pos];
                if (to != n + 1) {
                    dp2[to] = max(dp2[to], upd_state2(to, {dp1[i].first + 1, -i}));
                }
            }
        }
        
        if (dp2[i].first != -INF) {
            int pos = -dp2[i].second;
            
            {
                int to = max(pos, i);
                dp[to] = max(dp[to], dp2[i].first);
            }
            
            {
                int to = up[1][0][i];
                if (to != n + 1) {
                    dp2[to] = max(dp2[to], upd_state2(to, {dp2[i].first + 1, -pos}));
                }
            }
            
            {
                int to = up[0][0][pos];
                if (to != n + 1) {
                    dp1[to] = max(dp1[to], upd_state1(to, {dp2[i].first + 1, -i}));
                }
            }
        }
        
        if (dp[i] != -INF) {
            int to = up[2][0][i];
            if (to != n + 1) {
                dp[to] = max(dp[to], dp[i] + 1);
            }
        }
    }
    
    cout << dp[n] << "\n";
}