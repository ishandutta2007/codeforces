#include<bits/stdc++.h>  
using namespace std;  
typedef long long LL;  
const int MX = 1e5 + 5;  
LL a[MX],dp[MX][2];  
int main(){  
    int n;
    scanf("%d",&n);  
    for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);  
    for(int i=1;i<n;i++) {  
        a[i]=abs(a[i]-a[i+1]);  
    }  
    dp[1][1]=a[1];  
    dp[1][0]=0;  
    LL ans=a[1];  
    for(int i=2;i<n;i++)
	{  
        if(i%2)
		{  
            dp[i][0]=dp[i-1][0]-a[i];  
            dp[i][1]=max(a[i],dp[i-1][1]+a[i]);  
            ans=max(ans,max(dp[i][0],dp[i][1]));  
        }  
        else
		{  
            dp[i][0]=max(a[i],dp[i-1][0]+a[i]);  
            dp[i][1]=dp[i-1][1]-a[i];  
            ans=max(ans,max(dp[i][0],dp[i][1]));  
        }  
    }  
    printf("%I64d\n",ans);  
    return 0;  
}