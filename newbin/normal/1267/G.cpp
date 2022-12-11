#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
double dp[105][10005];
const double eps = 1e-18;
int main()
{
    int n, x;
    scanf("%d%d", &n, &x);
    dp[0][0] = 1;
    int sum = 0;
    fors(i,0,n){
        int c; scanf("%d", &c);
        for(int k = i; k >= 0; --k){
            for(int j = sum; j >= 0; --j){
                //if(dp[k][j] < eps && dp[k][j] > -eps) continue;
                dp[k+1][j+c] += dp[k][j]*(k+1)/(double)(n-k);
            }
        }
        sum += c;
    }
    double ans = 0;
    fors(i,1,n+1){
        fors(j,1,sum+1){
            //if(dp[i][j] < eps && dp[i][j] > -eps) continue;
            ans += dp[i][j] * min((n/(double)(i)+1)*(x/2.0), j/(double)i);
        }
    }
    printf("%.12f\n", ans);
}