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

const int N = 1e5 + 10;
vector<int> a(N);
vector<vector<int>> s(N, vector<int>(8));

bool cmp(int i, int j){
    return a[i] > a[j];
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, p, k;
    cin >> n >> p >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < p; j++){
            cin >> s[i][j];
        }
    }
    vector<int> ind(n);
    iota(ind.begin(), ind.end(), 0);
    sort(ind.begin(), ind.end(), cmp);
    vector<vector<int>> dp(n + 1, vector<int>(1 << p, -1e18)), par(n + 1, vector<int>(1 << p));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < (1 << p); j++){
            if (((i + 1) - (int)(__builtin_popcount(j)) <= k ? dp[i][j] + a[ind[i]] : dp[i][j]) > dp[i + 1][j]){
                dp[i + 1][j] = ((i + 1) - (int)(__builtin_popcount(j)) <= k ? dp[i][j] + a[ind[i]] : dp[i][j]);
                par[i + 1][j] = j;
            }
            for (int k = 0; k < p; k++){
                if (!(j & (1 << k))){
                    if (dp[i][j] + s[ind[i]][k] > dp[i + 1][j + (1 << k)]){
                        dp[i + 1][j + (1 << k)] = dp[i][j] + s[ind[i]][k];
                        par[i + 1][j + (1 << k)] = j;
                    }
                }
            }
        }
    }
    cout << dp[n][(1 << p) - 1] << endl;
    return 0;
}