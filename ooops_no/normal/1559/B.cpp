#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<map>
#include<set>
#include<deque>
#include<assert.h>
#include<bitset>
#include<unordered_map>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++){
            char c;
            cin >> c;
            if (c == 'R'){
                v[i] = 0;
            }
            else if (c == 'B'){
                v[i] = 1;
            }
            else{
                v[i] = 2;
            }
        }
        vector<vector<int>> dp(n, vector<int>(2, 1e18)), par(n, vector<int>(2));
        if (v[0] == 2){
            dp[0][0] = dp[0][1] = 0;
        }
        else{
            dp[0][v[0]] = 0;
        }
        for (int i = 1; i < n; i++){
            if (v[i] == 2){
                for (int f = 0; f < 2; f++){
                    for (int j = 0; j < 2; j++){
                        if (dp[i - 1][j] + (j == f) < dp[i][f]){
                            dp[i][f] = dp[i - 1][j] + (j == f);
                            par[i][f] = j;
                        }
                    }
                }
            }
            else{
                for (int f = v[i]; f <= v[i]; f++){
                    for (int j = 0; j < 2; j++){
                        if (dp[i - 1][j] + (j == f) < dp[i][f]){
                            dp[i][f] = dp[i - 1][j] + (j == f);
                            par[i][f] = j;
                        }
                    }
                }
            }
        }
        int now = 0;
        if (dp[n - 1][1] < dp[n - 1][0]){
            now = 1;
        }
        string s = "";
        for (int i = n - 1; i >= 0; i--){
            if (now == 0){
                s += 'R';
            }
            else{
                s += 'B';
            }
            now = par[i][now];
        }
        reverse(s.begin(), s.end());
        cout << s << endl;
    }
    return 0;
}