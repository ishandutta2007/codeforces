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

const int M=85;
int dp[M][M],all[M][M],n,m,Mod,C[M][M],f[M][M],pw2[M*M];

int A(int m,int n)
{
	if (m<n)return 0;
	int res=1;
	for (int i=m;i>=m-n+1;i--)res=res*i%Mod;
	return res;
}

void init(int n)
{
	for (int i=0;i<=n;i++)
	{
		C[i][0]=1;
		for (int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%Mod;
	}pw2[0]=1;
	for (int i=1;i<=n*n;i++)pw2[i]=pw2[i-1]*2%Mod;
	for (int i=0;i<=n;i++)
		for (int j=0;j<=n;j++)
		{
			for (int k=0;k<=j;k++)
				all[i][j]=(all[i][j]+(((j-k)&1)?Mod-1:1)*pw2[i*k]%Mod*C[j][k])%Mod,
				f[i][j]=(f[i][j]+(((j-k)&1)?Mod-1:1)*A(pw2[k]-1,i)%Mod*C[j][k])%Mod;
//			cout<<i<<' '<<j<<' '<<all[i][j]<<' '<<f[i][j]<<'\n';
		}
}

signed main()
{
	n=read(),m=read(),Mod=read();
	init(80);
	for (int i=1;i<=n;i++)
		for (int j=0;j<=m;j++)
		{
			for (int w1=0;w1<i;w1++)
				for (int w2=0;w2<j;w2++)
				{
					if ((n&1)&&i==n&&w1==i-1)continue;
					dp[i][j]=(dp[i][j]+(all[w1][w2]-dp[w1][w2]+Mod)*C[i][w1]%Mod
					*C[j][w2]%Mod*f[i-w1][j-w2]%Mod*pw2[w2*(i-w1)])%Mod;
				}
//			cout<<i<<' '<<j<<' '<<dp[i][j]<<endl; 
		}
	int res=0;
	for (int i=0;i<=m;i++)res=(res+(all[n][i]-dp[n][i]+Mod)*C[m][i])%Mod;
	cout<<res<<endl;
	return 0;
}