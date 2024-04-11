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

const int Mod=1e9+7;
const int M=1e5+10;
int dp[M],n,k,sum1,sum2,a[M],b[M],c[M];
char s1[M],s2[M];

int f(int x)
{
	return x>=Mod?x-Mod:x;
}

bool check(int x)
{
	for (int i=1;i<=n;i++)
		c[i]=a[i+x>n?i+x-n:i+x];
	for (int i=1;i<=n;i++)
		if (c[i]!=b[i])return 0;
	return 1;
}

signed main()
{
	cin>>s1+1>>s2+1>>k;
	n=strlen(s1+1);
	for (int i=1;i<=n;i++)
		a[i]=s1[i]-'a',b[i]=s2[i]-'a';
	dp[1]=sum2=1;
	for (int i=1;i<=k;i++)
	{
		sum1=sum2;sum2=0;
		for (int j=1;j<=n;j++)
			dp[j]=f(sum1-dp[j]+Mod),sum2=f(sum2+dp[j]);
	}
//	for (int i=1;i<=n;i++)
//		cout<<dp[i]<<' ';
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		if (check(i-1))
			ans=f(ans+dp[i]);
	}cout<<ans<<endl;
	return 0;
}