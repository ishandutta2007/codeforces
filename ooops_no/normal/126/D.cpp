#include<bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

const int INF = 1e18, M = 90;

int dp[M][3][3];

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> f{1, 2};
    while(f.back() < INF){
        f.pb(f.back () + f[(int)(f.size()) - 2]);
    }
    int t, m = f.size();
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        set<int> st;
        for (int i = m - 1; i >= 0; i--){
            if (n >= f[i]){
                n -= f[i];
                st.insert(i);
            }
        }
        for (int i = 0; i < M; i++){
            for (int j = 0; j < 3; j++){
                for (int k = 0; k < 3; k++){
                    dp[i][j][k] = 0;
                }
            }
        }
        dp[m - 1][0][0] = 1;
        for (int i = m - 1; i >= 1; i--){
            int f = (bool)(st.find(i) != st.end());
            for (int j = 0; j < 3; j++){
                for (int k = 0; k < 3; k++){
                    int l = 0;
                    if ((j + f) == 0) dp[i - 1][k][l] += dp[i][j][k];
                    if ((j + f) == 1){
                        dp[i - 1][k][l] += dp[i][j][k];
                        dp[i - 1][k + 1][l + 1] += dp[i][j][k];
                    }
                    if ((j + f) == 2){
                        dp[i - 1][k + 1][l + 1] += dp[i][j][k];
                    }
                }
            }
        }
        if (st.find(0) != st.end()){
            cout << dp[0][0][0] << "\n";
        }
        else{
            cout << dp[0][1][0] + dp[0][0][0] << "\n";
        }
    }
    return 0;
}