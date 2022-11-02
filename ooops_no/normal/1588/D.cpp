#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long
#define pb push_back
#define int long long

mt19937 rnd(51);

const int N = (1 << 10) + 10;
vector<pair<int,int>> g[N][52];
vector<pair<int,int>> gr[N][52];
bool used[N][52];
vector<pair<int,int>> ord;
int ind[150];
char rev[150];

void dfs(int a, int b){
    used[a][b] = 1;
    for (auto to : g[a][b]){
        if (!used[to.first][to.second]){
            dfs(to.first, to.second);
        }
    }
    ord.pb({a, b});
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int now = 0;
    for (int i = 'a'; i <= 'z'; i++) {
        rev[now] = i;
        ind[i] = now++;
    }
    for (int i = 'A'; i <= 'Z'; i++) {
        rev[now] = i;
        ind[i] = now++;
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for (int i = 0; i < (1 << n); i++){
            for (int j = 0; j < 52; j++){
                used[i][j] = 0;
                g[i][j].clear();
                gr[i][j].clear();
            }
        }
        vector<string> s(n);
        vector<vector<int>> dp((1 << n), vector<int>(52, -1));
        vector<vector<vector<int>>> a(n, vector<vector<int>>(52));
        vector<vector<pair<int,int>>> par(1 << n, vector<pair<int,int>>(52, {-1, -1}));
        for (int i = 0; i < n; i++){
            cin >> s[i];
            for (int j = 0; j < s[i].size(); j++){
                a[i][ind[s[i][j]]].pb(j);
            }
        }
        deque<pair<int,int>> q;
        for (int j = 0; j < 52; j++){
            bool f = 1;
            for (int i = 0; i < n; i++){
                f &= a[i][j].size() > 0;
            }
            if (f){
                dp[0][j] = 1;
                q.pb({0, j});
            }
        }
        while(q.size() > 0){
            int i = q.front().first, j = q.front().second;
            q.pop_front();
            for (int k = 0; k < 52; k++){
                bool f = 1;
                int msk = 0;
                for (int q = 0; q < n; q++){
                    int ind = a[q][j][(bool)(i & (1 << q))];
                    bool x = 0;
                    if (a[q][k].size() > 0 && a[q][k][0] > ind){
                        x = 1;
                    }
                    else if (a[q][k].size() > 1 && a[q][k][1] > ind){
                        x = 1;
                        msk += (1 << q);
                    }
                    f &= x;
                }
                if (f){
                    if (dp[msk][k] == -1){
                        dp[msk][k] = 1;
                        q.pb({msk, k});
                    }
                    g[i][j].pb({msk, k});
                    gr[msk][k].pb({i, j});
                }
            }
        }
        ord.clear();
        for (int j = 0; j < 52; j++){
            if (!used[0][j] && dp[0][j] != -1){
                dfs(0, j);
            }
        }
        for (auto to : ord){
            for (auto t : gr[to.first][to.second]){
                if (dp[t.first][t.second] < dp[to.first][to.second] + 1){
                    par[t.first][t.second] = {to.first, to.second};
                    dp[t.first][t.second] = dp[to.first][to.second] + 1;
                }
            }
        }
        int ans = 0, j = -1;
        for (int i = 0; i < 52; i++){
            if (dp[0][i] > ans){
                ans = dp[0][i];
                j = i;
            }
        }
        if (j == -1){
            cout << ans << endl;
        }
        else{
            string t = "";
            int i = 0;
            while(i != -1){
                t += rev[j];
                pair<int,int> p = par[i][j];
                i = p.first, j = p.second;
            }
            cout << ans << endl << t << endl;
        }
    }
    return 0;
}