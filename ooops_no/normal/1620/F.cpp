#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define ld long double

mt19937 rnd(51);

const int INF = 1e9, N = 1e6 + 10;
pair<int,int> par[N][2][2];

void solve(int n, vector<int> p){
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(2, INF)));
    dp[0][0][1] = -INF;
    for (int i = 0; i < n; i++){
        vector<vector<int>> arr;
        if (dp[i][0][0] != INF){
            arr.pb({p[i], dp[i][0][0], 0, 0});
        }
        if (dp[i][0][1] != INF){
            arr.pb({-p[i], dp[i][0][1], 0, 1});
        }
        if (dp[i][1][0] != INF){
            arr.pb({dp[i][1][0], p[i], 1, 0});
        }
        if (dp[i][1][1] != INF){
            arr.pb({dp[i][1][1], -p[i], 1, 1});
        }
        for (auto to : arr){
            int x = to[0], y = to[1], a = to[2], b = to[3];
            if (p[i + 1] > x){
                if (y < dp[i + 1][0][0]){
                    dp[i + 1][0][0] = y;
                    par[i + 1][0][0] = {a, b};
                }
            }
            else if (p[i + 1] > y){
                if (x < dp[i + 1][1][0]){
                    dp[i + 1][1][0] = x;
                    par[i + 1][1][0] = {a, b};
                }
            }
            if (-p[i + 1] > x){
                if (y < dp[i + 1][0][1]){
                    dp[i + 1][0][1] = y;
                    par[i + 1][0][1] = {a, b};
                }
            }
            else if (-p[i + 1] > y){
                if (x < dp[i + 1][1][1]){
                    dp[i + 1][1][1] = x;
                    par[i + 1][1][1] = {a, b};
                }
            }
        }
    }
    for (int j = 0; j < 2; j++){
        for (int k = 0; k < 2; k++){
            if (dp[n][j][k] != INF){
                vector<int> arr;
                for (int i = n; i >= 1; i--){
                    if (k == 0){
                        arr.pb(p[i]);
                    }
                    else{
                        arr.pb(-p[i]);
                    }
                    pair<int,int> p = par[i][j][k];
                    j = p.first, k = p.second;
                }
                reverse(arr.begin(), arr.end());
                cout << "YES\n";
                for (auto to : arr) cout << to << ' ';
                cout << endl;
                return;
            }
        }
    }
    cout << "NO\n";
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> p(n + 1);
        p[0] = INF;
        for (int i = 1; i <= n; i++){
            cin >> p[i];
        }
        solve(n, p);
    }
    return 0;
}