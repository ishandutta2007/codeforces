#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb emplace_back
#define ll long long

mt19937 rnd(51);

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        vector<int> mve(n * m, -1), cnt(n * m), dp(n * m, -1);
        vector<vector<int>> par(n * m);
        vector<bool> cycle(n * m, 1);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                int ii = i, jj = j;
                if (a[i][j] == 'U'){
                    ii--;
                }
                else if (a[i][j] == 'D'){
                    ii++;
                }
                else if (a[i][j] == 'R'){
                    jj++;
                }
                else{
                    jj--;
                }
                if (ii >= 0 && ii < n && jj >= 0 && jj < m){
                    mve[i * m + j] = ii * m + jj;
                    cnt[ii * m + jj]++;
                }
            }
        }
        deque<int> q;
        for (int i = 0; i < n * m; i++){
            if (mve[i] == -1){
                q.pb(i);
                dp[i] = 1;
            }
            else par[mve[i]].pb(i);
        }
        while(!q.empty()){
            int v = q.front();
            q.pop_front();
            for (auto to : par[v]){
                dp[to] = dp[v] + 1;
                q.pb(to);
            }
        }
        for (int i = 0; i < n * m; i++){
            if (cnt[i] == 0){
                q.pb(i);
            }
            else if (dp[i] != -1){
                cycle[i] = 0;
            }
        }
        while(!q.empty()){
            int v = q.front();
            q.pop_front();
            cycle[v] = 0;
            if (mve[v] != -1){
                cnt[mve[v]]--;
                if (cnt[mve[v]] == 0){
                    q.pb(mve[v]);
                }
            }
        }
        for (int i = 0; i < n * m; i++){
            if (cycle[i] && dp[i] == -1){
                int v = i;
                vector<int> a;
                while(1){
                    a.pb(v);
                    if (i == mve[v]) break;
                    v = mve[v];
                }
                for (auto to : a){
                    dp[to] = a.size();
                    deque<int> q{to};
                    while(!q.empty()){
                        int v = q.front();
                        q.pop_front();
                        for (auto t : par[v]){
                            if (!cycle[t]){
                                dp[t] = dp[v] + 1;
                                q.pb(t);
                            }
                        }
                    }
                }
            }
        }
        int now_ans = -1, val = -1;
        for (int i = 0; i < n * m; i++){
            if (dp[i] > now_ans){
                now_ans = dp[i];
                val = i;
            }
        }
        cout << val / m + 1 << ' ' << val % m + 1 << ' ' << now_ans << endl;
    }
    return 0;
}