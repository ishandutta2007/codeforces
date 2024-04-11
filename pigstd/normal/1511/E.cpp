#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define WT int T=read();while(T--) 
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

const int Mod=998244353;
const int M=3e5+10;
int n,m,ff[M][2],g[M][2],f[M],pow2[M],ans,cnt;
vector<int>a[M];
// cf  
// /tuu

signed main()
{
	n=read(),m=read();pow2[0]=1;g[0][0]=1;
	for (int i=1;i<=3e5;i++)
		ff[i][0]=(ff[i-1][0]+ff[i-1][1]+g[i-1][1])%Mod,
		ff[i][1]=(ff[i-1][0]+ff[i-1][1])%Mod,
		g[i][1]=g[i-1][0],
		g[i][0]=(g[i-1][1]*2+g[i-1][0])%Mod,
		f[i]=(ff[i][0]+ff[i][1])%Mod,
		pow2[i]=pow2[i-1]*2%Mod;
	for (int i=1;i<=n;i++)
	{
		a[i].pb(0);string s;cin>>s;
		for (int j=1;j<=m;j++)
			a[i].pb(s[j-1]=='*'?1:2),
			cnt+=s[j-1]=='o'?1:0;
	}
	for (int i=1;i<=n;i++)
	{
		int sum=0;
		for (int j=1;j<=m;j++)
		{
			if (a[i][j]==2)sum++;
			else
			{
				ans=(ans+pow2[cnt-sum]*f[sum]%Mod)%Mod;
				sum=0;
			}
		}
		ans=(ans+pow2[cnt-sum]*f[sum]%Mod)%Mod;
		sum=0;
	}
	for (int j=1;j<=m;j++)
	{
		int sum=0;
		for (int i=1;i<=n;i++)
		{
			if (a[i][j]==2)sum++;
			else
			{
				ans=(ans+pow2[cnt-sum]*f[sum]%Mod)%Mod;
				sum=0;
			}
		}
		ans=(ans+pow2[cnt-sum]*f[sum]%Mod)%Mod;
		sum=0;
	}
	cout<<ans<<endl;
	return 0;
}