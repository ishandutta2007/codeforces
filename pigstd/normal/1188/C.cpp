#include<bits/stdc++.h>
#define WT int T=read();while(T--)
#define int long long
#define pb push_back
#define YES puts("YES")
#define NO puts("NO")
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int Mod=998244353;
const int M=1e3+10;
const int N=1e5+10;
int n,k,a[M],f[M][M],ans[N];

signed main()
{
	n=read(),k=read();int maxn=0;
	for (int i=1;i<=n;i++)a[i]=read(),maxn=max(maxn,a[i]);
	sort(a+1,a+1+n);
	for (int v=1;v<=maxn/(k-1);v++)
	{
		for (int i=1;i<=n;i++)
			for (int j=2;j<=k;j++)f[i][j]=0;
		for (int i=1;i<=n;i++)f[i][1]=1;
		for (int j=2;j<=k;j++)
		{
			int l=1,sum=0;
			for (int i=1;i<=n;i++)
			{
				while(a[i]-a[l]>=v&&l<i)sum=(sum+f[l][j-1])%Mod,l++;
				f[i][j]=sum;
			}
		}
		for (int i=1;i<=n;i++)
			ans[v]=(ans[v]+f[i][k])%Mod;
	}int sum=0;
	for (int v=1;v<=(int)(1e5)/(k-1);v++)
		sum=((ans[v]-ans[v+1]+Mod)%Mod*v+sum)%Mod;
	cout<<sum<<endl;
	return 0;
}