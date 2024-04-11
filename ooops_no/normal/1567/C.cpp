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
#define ll long long
#define int long long

mt19937 rnd(51);

void solve(int n){
    string s = to_string(n);
    vector<vector<int>> dp(2, vector<int>(2));
    dp[0][0] = 1;
    reverse(s.begin(), s.end());
    for (auto to : s){
        vector<vector<int>> dpp(2, vector<int>(2));
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                for (int k = 0; k < 2; k++){
                    for (int f = 0; f < 2; f++){
                        if ((i + j + k) % 10 == to - '0'){
                            dpp[f][(i + j + k) / 10] += dp[k][f];
                        }
                    }
                }
            }
        }
        dp = dpp;
    }
    cout << dp[0][0] - 2 << endl;
}

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
        solve(n);
    }
    return 0;
}