#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
const int p=1e9+7;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

char a[N];
int pre[N],sum[N],dp[N],w[N];

signed main()
{
	scanf("%s",a+1);
	int n=strlen(a+1)+1,cnt=0;
	a[n]='1';
	for (int i=1,now=0;i<=n;i++)
	if (a[i]=='1') pre[++cnt]=now,now=0;
			  else now++;
	if (cnt==1) return print(n-1),0;
	int ans=1LL*(pre[1]+1)*(pre[cnt]+1)%p;
	for (int i=0;i<=n;i++) w[i]=1;
	sum[1]=dp[1]=1;
	for (int i=2;i<cnt;i++)
	{
		for (int j=0;j<=pre[i];j++) dp[i]=(1LL*dp[i]+sum[i-1]-sum[w[j]-1]+p)%p;
		for (int j=0;j<=pre[i];j++) w[j]=i;
		sum[i]=(sum[i-1]+dp[i])%p;
	}
	print(1LL*ans*sum[cnt-1]%p);
	
	return 0;
}