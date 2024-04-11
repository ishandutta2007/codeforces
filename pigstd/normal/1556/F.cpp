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

const int Mod=1e9+7;
const int N=20;
const int M=(1<<14)+10;
int dp[M],n,a[N],t[N][N],ans;
vector<int>v1,v2;

int poww(int a,int b)
{
	int res=1;
	while(b)
	{
		if (b&1)res=res*a%Mod;
		a=a*a%Mod,b>>=1;
	}return res;
}
int inv(int x){return poww(x,Mod-2);}

int get(int x)
{
	int res=0;
	for (int i=0;i<n;i++)
		if ((1<<i)&x)res++;
	return res;
}

signed main()
{
	n=read();for (int i=1;i<=n;i++)a[i]=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			t[i][j]=a[i]*inv(a[i]+a[j])%Mod;
	for (int i=1;i<(1<<n);i++)
	{
		dp[i]=1;
		for (int j=(i-1)&i;j;j=i&(j-1))
		{
			int res=1;v1.clear(),v2.clear();
			for (int k=0;k<n;k++)
				if (j&(1<<k))v1.pb(k+1);
				else if (i&(1<<k))v2.pb(k+1);
			for (int k1=0;k1<v1.size();k1++)
				for (int k2=0;k2<v2.size();k2++)
					res=res*t[v1[k1]][v2[k2]]%Mod;
			dp[i]=(dp[i]-res*dp[j]%Mod+Mod)%Mod;
		}
	}int ans=0;
	for (int i=1;i<(1<<n);i++)
	{
		int res=1;v1.clear(),v2.clear();
		for (int j=0;j<n;j++)
			if (i&(1<<j))v1.pb(j+1);
			else v2.pb(j+1);
		for (int k1=0;k1<v1.size();k1++)
			for (int k2=0;k2<v2.size();k2++)
				res=res*t[v1[k1]][v2[k2]]%Mod;
		ans=(ans+res*dp[i]%Mod*get(i))%Mod;
//		cout<<i<<' '<<dp[i]<<endl;
	}cout<<ans<<endl;
	return 0;
}