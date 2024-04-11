#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long

mt19937 rnd(51);

const int N = 710;
int a[N];
bool good[N][N];
vector<vector<int>> pr(N);
int dp[N][N][2];

bool solve(int l, int r, int val){
    if (l > r) return 1;
    int check = (val == 0 ? l - 1 : r + 1);
    if (l == r){
        dp[l][r][val] = good[l][check];
    }
    if (dp[l][r][val] != -1){
        return dp[l][r][val];
    }
    dp[l][r][val] = (solve(l + 1, r, 0) && good[l][check]) || (solve(l, r - 1, 1) && good[check][r]);
    for (int i = l + 1; i < r; ++i){
        if (good[i][check]){
            dp[l][r][val] |= solve(l, i - 1, 1) && solve(i + 1, r, 0);
        }
    }
    return dp[l][r][val];
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) dp[i][j][0] = dp[i][j][1] = -1;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        int now = a[i];
        for (int j = 2; j * j <= now; j++){
            if (now % j == 0){
                while(now % j == 0) now /= j;
                pr[i].pb(j);
            }
        }
        if (now != 1) pr[i].pb(now);
    }
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            bool x = 0;
            for (auto to : pr[i]){
                for (auto t : pr[j]){
                    x |= to == t;
                }
            }
            good[i][j] = good[j][i] = x;
        }
        good[i][n] = good[n][i] = 1;
    }
    cout << (solve(0, n - 1, 1) ? "Yes" : "No") << endl;
    return 0;
}