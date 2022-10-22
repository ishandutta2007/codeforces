#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
//#define int long long
#define pb push_back
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int Mod=1e9+7;
const int M=3010;
int f[M][M][4],n,m;
bool a[M][M];

int F(int x1,int y1,int x2,int y2,int tt)
{
//	for (int i=1;i<=n;i++)for (int j=1;j<=m;j++)f[i][j]=0;
	f[x1][y1][tt]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (a[i][j]==0)f[i][j][tt]=0;
			else f[i][j][tt]=((f[i][j][tt]+f[i-1][j][tt])%Mod+f[i][j-1][tt])%Mod;
	return f[x2][y2][tt];
}

char s[M];

signed main()
{
//	freopen("qwq.txt","r",stdin);
	n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
			a[i][j]=(getchar()=='#'?0:1);
		getchar();
	}
	long long ans=1ll*F(1,2,n-1,m,0)*F(2,1,n,m-1,1)-1ll*F(1,2,n,m-1,2)*F(2,1,n-1,m,3);
	ans%=Mod,ans+=Mod,ans%=Mod;printf("%d",ans);
	return 0;
}