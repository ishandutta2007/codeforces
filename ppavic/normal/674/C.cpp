#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 2e5 + 500;
const int K = 55;

double dp[N][K], p1[N], p2[N], p3[N];
int n, k, a[N];

double get(int l,int r){
    return p2[r] - p2[l - 1] - p1[l - 1] * ( p3[r] - p3[l - 1] ) ;
}

void solve(int l,int r,int ll,int rr,int kk){
    if(r < l) return;
    int mi = (r + l) / 2, pos = ll;
    double bst = 1e18;
    for(int i = min(mi, rr);i>=ll;i--){
        if(dp[i - 1][kk - 1] + get(i, mi) < bst){
            bst = dp[i - 1][kk - 1] + get(i, mi);
            pos = i;
        }
    }
    dp[mi][kk] = bst;
    solve(l, mi - 1, ll, pos, kk);
    solve(mi + 1, r, pos, rr, kk);
}

int main(){
    scanf("%d%d", &n, &k);
    for(int i = 1;i<=n;i++){
        scanf("%d", a + i);
        p1[i] = (double)a[i] + p1[i - 1];
        p2[i] = (p1[i] / (double)a[i]) + p2[i - 1];
        p3[i] = p3[i - 1] + 1 / (double)a[i];
    }
    for(int i = 0;i<N;i++)
        dp[i][0] = 1e18;
    dp[0][0] = 0;
    for(int b = 1;b<=k;b++)
        solve(1, n , 1, n , b);
    printf("%.10lf\n", dp[n][k]);
}