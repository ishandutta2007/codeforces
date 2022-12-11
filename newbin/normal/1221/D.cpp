#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const int maxn = 3e5 + 50;
const ll inf = 0x3f3f3f3f3f3f3f3f;
ll dp[maxn][3];
ll a[maxn], b[maxn];
int n;
int main()
{
	int T;cin>>T;
	while(T--){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i){
            dp[i][0] = dp[i][1] = dp[i][2] = inf;
            scanf("%I64d%I64d", &a[i], &b[i]);
        }
        dp[1][0] = 0; dp[1][1] = b[1]; dp[1][2] = 2*b[1];
        ll ans = 0;
        for(int i = 1; i < n; ++i){
            if(a[i] != a[i+1]) dp[i+1][0] = min(dp[i+1][0], dp[i][0]);
            if(a[i]+1 != a[i+1]) dp[i+1][0] = min(dp[i+1][0], dp[i][1]);
            if(a[i]+2 != a[i+1]) dp[i+1][0] = min(dp[i+1][0], dp[i][2]);

            if(a[i] != a[i+1]+1) dp[i+1][1] = min(dp[i+1][1], dp[i][0]+b[i+1]);
            if(a[i] != a[i+1]) dp[i+1][1] = min(dp[i+1][1], dp[i][1] + b[i+1]);
            if(a[i]+1 != a[i+1]) dp[i+1][1] = min(dp[i+1][1], dp[i][2] + b[i+1]);

            if(a[i]-2 != a[i+1]) dp[i+1][2] = min(dp[i+1][2], dp[i][0]);
            if(a[i]-1 != a[i+1]) dp[i+1][2] = min(dp[i+1][2], dp[i][1]);
            if(a[i] != a[i+1]) dp[i+1][2] = min(dp[i+1][2], dp[i][2]);
            dp[i+1][2] += 2*b[i+1];
        }
        ans = min(dp[n][0], dp[n][1]);
        ans = min(ans, dp[n][2]);
        printf("%I64d\n", ans);
	}
}