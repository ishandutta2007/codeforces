#include<bits/stdc++.h>
#define int long long
using namespace std;

const int inf=1e18;
const int M=5005;
int n,k,m,a[M],dp[M][M];
deque<int> q[M];

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

signed main()
{
	n=read(),k=read(),m=read();
	for (int i=1;i<=n;i++)a[i]=read();
	memset(dp,-0x3f,sizeof(dp));dp[0][0]=0,q[0].push_back(0);
    for(int i=1;i<=n;i++)
        for(int j=m;j>=1;j--)
		{
            while(q[j-1].size()&&q[j-1].front()<i-k)q[j-1].pop_front();
            if(q[j-1].size())
			{
                dp[i][j]=dp[q[j-1].front()][j-1]+a[i];
                while(q[j].size()&&dp[q[j].back()][j]<=dp[i][j])q[j].pop_back();
                q[j].push_back(i);
            }
        }
    int ans=0;
    for (int i=n-k+1;i<=n;i++)ans=max(ans,dp[i][m]);
    cout<<(ans>0?ans:-1);
	return 0; 
}