#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=505;
int n,Mod,dp1[2][M*M/2],sum[2][M*M/2],sum2[2][M*M/2],f[M];
int C2(int n){return n*(n-1)/2;}

signed main()
{
	n=read(),Mod=read();
	dp1[1][0]=1;sum[1][0]=1,sum2[1][0]=1;
	for (int i=2;i<=n;i++)
	{
		memset(dp1[i&1],0,sizeof(dp1[i&1]));
		memset(sum[i&1],0,sizeof(sum[i&1]));
		memset(sum2[i&1],0,sizeof(sum2[i&1]));
		for (int j=0;j<=C2(i);j++)
		{
			if (j<i)dp1[i&1][j]=sum[(i-1)&1][min(C2(i-1),j)];
			else dp1[i&1][j]=(sum[(i-1)&1][min(C2(i-1),j)]-sum[(i-1)&1][j-i]+Mod)%Mod;
			sum[i&1][j]=(sum[i&1][j==0?0:j-1]+dp1[i&1][j])%Mod;
			sum2[i&1][j]=(sum2[i&1][j==0?0:j-1]+sum[i&1][j])%Mod;
		}
		f[i]=i*f[i-1]%Mod;int x=0;
		for (int p1=2;p1<=C2(i-1);p1++)
		{
			int cnt;
			if (p1>i)cnt=sum2[(i-1)&1][p1-2]-sum2[(i-1)&1][p1-i-1];
			else cnt=sum2[(i-1)&1][p1-2];cnt=(cnt+Mod)%Mod;
			x=(x+cnt)%Mod,cnt=cnt*i%Mod;
			if (p1>=i+1)x=(x-sum[(i-1)&1][p1-1-i]*(i-1)%Mod+Mod)%Mod;
			cnt=(cnt-x+Mod)%Mod;//cout<<cnt<<endl;
			f[i]=(f[i]+dp1[(i-1)&1][p1]*cnt)%Mod; 
		}
	}
	cout<<f[n]<<endl;
	return 0;
}