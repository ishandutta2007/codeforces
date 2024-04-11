#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<map>
#include<set>
#include<deque>
#include<assert.h>
using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

const int MOD = 998244353;

int add(int a, int b){
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int sub(int a, int b){
    a -= b;
    if (a < 0) a += MOD;
    return a;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, len;
    cin >> n >> k >> len;
    len--;
    if (len == 0){
        cout << 0;
        return 0;
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] != -1) a[i]--;
    }
    vector<vector<int>> dp(n, vector<int>(k));
    vector<int> sum(k);
    int sum_all = 0;
    vector<pair<int,int>> all;
    if (a[0] == -1){
        for (int i = 0; i < k; i++){
            dp[0][i] = 1;
            sum[i]++;
            sum_all++;
            all.pb({0, i});
        }
    }
    else{
        dp[0][a[0]] = 1;
        sum[a[0]]++;
        sum_all++;
        all.pb({0, a[0]});
    }
    for (int i = 1; i < n; i++){
        if (a[i] == -1){
            for (int c = 0; c < k; c++){
                dp[i][c] = sub(sum_all, sum[c]);
                all.pb({i, c});
                sum[c] = add(sum[c], dp[i][c]);
            }
            for (int c = 0; c < k; c++) sum_all = add(sum_all, dp[i][c]);
        }
        else{
            vector<pair<int,int>> nw;
            int sumc = 0;
            for (auto to : all){
                if (to.first < i - len) continue;
                if (to.second == a[i]){
                    nw.pb(to);
                }
                else{
                    sumc = add(sumc, dp[to.first][to.second]);
                    sum_all = sub(sum_all, dp[to.first][to.second]);
                    sum[to.second] = sub(sum[to.second], dp[to.first][to.second]);
                    dp[to.first][to.second] = 0;
                }
            }
            all = nw;
            dp[i][a[i]] = sumc;
            sum_all = add(sum_all, dp[i][a[i]]);
            sum[a[i]] = add(sum[a[i]], dp[i][a[i]]);
            all.pb({i, a[i]});
        }
        if (i >= len){
            for (int f = 0; f < k; f++){
                sum_all = sub(sum_all, dp[i - len][f]);
                sum[f] = sub(sum[f], dp[i - len][f]);
                dp[i - len][f] = 0;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < k; j++){
            ans = add(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}