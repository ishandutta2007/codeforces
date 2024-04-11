#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
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

const int M=405;
int dp[M][M],fac[M],pow2[M],ifac[M],n,p;

int poww(int a,int b)
{
	int res=1;
	while(b)
	{
		if (b&1)res=res*a%p;
		a=a*a%p;b>>=1;
	}return res;
}
int inv(int a){return poww(a,p-2);}

signed main()
{
	n=read(),p=read();int ans=0;
	fac[0]=pow2[0]=1;
	for (int i=1;i<=n;i++)
		pow2[i]=pow2[i-1]*2%p,
		fac[i]=fac[i-1]*i%p,
		ifac[i]=inv(fac[i]);
	for (int i=1;i<=n;i++)
		dp[i][0]=pow2[i-1]*ifac[i]%p;
//	puts("qwq");
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			for (int k=1;k<=i-2;k++)
				dp[i][j]=(dp[i][j]+dp[k][j-1]*pow2[i-k-2]%p*ifac[i-k-1])%p;
//	puts("qwq");
	for (int i=0;i<=n;i++)
		ans=(ans+dp[n][i]*fac[n-i])%p;
	cout<<ans<<endl;
	return 0;
}