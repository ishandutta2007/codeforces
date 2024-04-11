#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const int maxn = 2e5 + 50;
int h[maxn];
int dp[maxn];
int main()
{
	int T; cin>>T;
	while(T--){
        int n, H; cin>>H>>n;
        for(int i = 1; i <= n; ++i) scanf("%d", &h[i]);
        dp[1] = 0; dp[2] = 1;
        for(int i = 3; i <= n; ++i){
            if(h[i]+1 == h[i-1]) dp[i] = min(dp[i-2], dp[i-1]+1);
            else{
                dp[i] = min(dp[i-1]+1, dp[i-2]+2);
            }
            //cout<<"h:"<<h[i]<<" dp:"<<dp[i]<<endl;
        }
        int ans = dp[n];
        if(h[n] == 1) ans = min(ans, dp[n-1]);
        cout<<ans<<endl;
	}
}