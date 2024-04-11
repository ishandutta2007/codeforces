#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
typedef long long ll;
using namespace std;

const int MXN = 205;

int n;
ll c[MXN][MXN];
ll ps[MXN][MXN];

ll dp[MXN][MXN];
int optk[MXN][MXN];

ll query(int t, int b, int l, int r){
    if (t == 0){
        if (l == 0)
            return ps[b][r];
        return ps[b][r] - ps[b][l - 1];
    }
    if (l == 0)
        return ps[b][r] - ps[t - 1][r];
    return ps[b][r] - ps[t - 1][r] - ps[b][l - 1] + ps[t - 1][l - 1];
}

ll cost(int i, int j){
    return query(i, j, 0, n - 1) - query(i, j, i, j);
}

int parent[MXN];

void build(int l, int r, int prev = -1){
    if (l > r) return;
    if (l == r){
        parent[l] = prev;
        return;
    }
    int k = optk[l][r];
    parent[k] = prev;
    build(l, k - 1, k);
    build(k + 1, r, k);
}

void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++){
        cin >> c[i][j];
    }
    ps[0][0] = c[0][0];
    for (int i = 1; i < n; i++){
        ps[0][i] = c[0][i] + ps[0][i - 1];
        ps[i][0] = c[i][0] + ps[i - 1][0];
    }
    for (int i = 1; i < n; i++) for (int j = 1; j < n; j++){
        ps[i][j] = c[i][j] + ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
    }

    for (int i = 0; i < n; i++)
        dp[i][i] = cost(i, i);
    for (int d = 1; d < n; d++){
        for (int i = 0; i + d < n; i++){
            int j = i + d;
            ll add = cost(i, j);
            dp[i][j] = (ll)3e18;
            optk[i][j] = -1;
            for (int k = i; k <= j; k++){
                if (dp[i][j] > dp[i][k - 1] + dp[k + 1][j]){
                    dp[i][j] = dp[i][k - 1] + dp[k + 1][j];
                    optk[i][j] = k;
                }
            }
            dp[i][j] += add;
        }
    }
    build(0, n - 1);
    for (int i = 0; i < n; i++)
        cout << parent[i] + 1 << " ";
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    solve();
}