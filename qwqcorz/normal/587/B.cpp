#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

inline void add(int &x,int y){x+=y;if (x>=mod) x-=mod;}
vector<int>dp[N];
int a[N],p[N],np[N];

void GreenDay()
{
	int n=read();
	ll l=read(),x=l/n,y=l%n;
	int k=read();
	for (int i=0;i<n;i++) a[i]=read(),p[i]=i;
	for (int i=0;i<=k;i++) dp[i].resize(n);
	sort(p,p+n,[&](int x,int y){return a[x]<a[y];});
	for (int i=0;i<n;i++) np[p[i]]=i;
	dp[0][0]=1;
	for (int i=1;i<=k;i++)
	for (int j=0,t=0,sum=0;j<n;j++)
	{
		while (t<n&&a[p[t]]<=a[p[j]]) add(sum,dp[i-1][t++]);
		dp[i][j]=sum;
	}
	int ans=0;
	for (int i=1;i<=min((ll)k,x+1);i++)
	{
		for (int j=0;j<n;j++) add(ans,1LL*max(x-i+1,0LL)%mod*dp[i][j]%mod);
		for (int j=0;j<y;j++) add(ans,dp[i][np[j]]);
	}
	print(ans);
}

signed main()
{
	int T=1;
//	int T=read();
	while (T--) GreenDay();
	
	return 0;
}