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

const int MOD = 998244353;

int mul(int a, int b){
    return (a * b % MOD);
}

int sub(int a, int b){
    a -= b;
    if (a < 0) a += MOD;
    return a;
}

int add(int a, int b){
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> v(n);
    vector<int> ans(m + 1);
    for (int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }
    for (int i = m; i >= 1; --i){
        int val = (m / i + 1);
        vector<int> dp(val);
        dp[0] = 1;
        for (int j = 0; j < n; ++j){
            int first = ((v[j].first + i - 1) / i), brk = v[j].second / i;
            vector<int> dpp(val);
            for (int k = 1; k < val; k++){
                dp[k] = add(dp[k], dp[k - 1]);
            }
            for (int f = 0; f < val; f++){
                if (f >= first){
                    dpp[f] = dp[f - first];
                }
                if (f - brk - 1 >= 0){
                    dpp[f] = sub(dpp[f], dp[f - brk - 1]);
                }
            }
            dp = dpp;
        }
        for (int f = i; f <= m; f += i){
            ans[i] = sub(ans[i], ans[f]);
        }
        for (int j = 0; j < val; j++){
            ans[i] = add(ans[i], dp[j]);
        }
    }
    cout << ans[1] << endl;
    return 0;
}