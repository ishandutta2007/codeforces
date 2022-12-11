#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
#define all(vec) vec.begin(),vec.end()
using namespace std;
const int maxn =5050;
int a[maxn];
int pre[maxn];
int last[maxn];
int dp[maxn][maxn];
int main()
{
    int T; cin>>T;
    while(T--){
        int tot; cin>>tot; int n = 1;
        fors(i,0,tot+1) last[i] = 0;
        fors(i,1,tot+1){
            scanf("%d", &a[n]); if(a[n]==a[n-1]) continue;
            pre[n] = last[a[n]]; last[a[n]] = n; n++;
        }n--;
        int ans = n-1;
        fors(i,1,n+1) fors(j,i,n+1) dp[i][j]=0;
        fors(len,2,n+1){
            for(int l=1;l+len-1<=n;++l){
                int r = l+len-1;
                dp[l][r] = dp[l][r-1];
                for(int p = pre[r]; p >= l; p = pre[p]){
                    dp[l][r] = max(dp[l][r], dp[l][p]+dp[p][r-1]+1);
                }
            }
        }
        ans -= dp[1][n];
        cout<<ans<<endl;
    }
	return 0;
}