#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 4005;
int u[N][N];

int C(int l, int r){
    return u[r][r] - u[r][l-1] - u[l-1][r] + u[l-1][l-1];
}

int Cost[N][N];

int dp[2][N];
void solve(int bit, int l, int r, int optl, int optr){
    if(l > r)
        return;
    int mid = (l + r) / 2;
    int best = (int)1e9;
    int id = -1;
    for(int j = optl ; j <= min(optr, mid - 1); j ++ ){
        if(best > dp[!bit][j] + Cost[j + 1][mid]){
            best = dp[!bit][j] + Cost[j + 1][mid];
            id = j;
        }
    }
    dp[bit][mid] = best;
    solve(bit, l, mid - 1, optl, id);
    solve(bit, mid + 1, r, id, optr);
}

int main(){
    fastIO;
    int n, k;
    scanf("%i %i", &n, &k);
    char ti;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= n; j ++ ){
            ti = getchar();
            while(!(ti >= '0' && ti <= '9')) ti = getchar();
            u[i][j] = ti - '0';
            if(j>i)
                u[i][j] = 0;
        }
    }
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= n;  j ++ ){
            u[i][j] += u[i-1][j] + u[i][j-1] - u[i-1][j-1];
        }
    }
    for(int i = 1; i <= n; i ++ ) for(int j = i; j <= n ; j ++ ) Cost[i][j] = C(i,j);
    for(int i = 0 ; i <= n; i ++ ){
        dp[0][i] = (int)1e9;
    }
    dp[0][0] = 0;
    int cur = 1;
    for(int t = 0 ;t < k ; t ++ ){
        solve(cur, 1, n, 0, n-1);
        cur ^= 1;
    }
    printf("%i\n", dp[!cur][n]);
    return 0;
}