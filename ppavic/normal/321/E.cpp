#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 4005;
const int K = 805;
const int INF = 0x3f3f3f3f;

int C[N][N], n, k, dp[N][K];

int get(int l,int r){
    return C[r][r] - C[r][l - 1] - C[l - 1][r] + C[l - 1][l - 1];
}

void solve(int l,int r,int ll,int rr,int kk){
    if(r < l) return;
    int mi = (l + r) / 2, bst = ll, mx = INF;
    for(int i = ll;i<=min(rr, mi);i++){
        if(dp[i - 1][kk - 1] + get(i, mi) <= mx){
            mx = dp[i - 1][kk - 1] + get(i, mi);
            bst = i;
        }
    }
    dp[mi][kk] = mx;
    solve(l, mi - 1, ll, bst, kk);
    solve(mi + 1, r, bst, rr, kk);
}

int main(){
    scanf("%d%d", &n, &k);
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=n;j++)
            scanf(" %c", &C[i][j]), C[i][j] -= '0';
    for(int i = 1;i<=n;i++){
        dp[i][0] = INF;
        int cur = 0;
        for(int j = 1;j<=n;j++){
            cur += C[i][j];
            C[i][j] = cur + C[i - 1][j];
        }
    }
    for(int b = 1;b<=k;b++) solve(1,n,1,n,b);
    printf("%d\n", dp[n][k] / 2);
}