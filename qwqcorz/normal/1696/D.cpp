#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2.5e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int mn1[N][20],mn2[N][20],Log[N];
int st1[N],st2[N],p[N],dp[N];
int query(int (*st)[20],int l,int r)
{
	int k=Log[r-l+1];
	return min(st[r][k],st[l+(1<<k)-1][k]);
}
void work()
{
	int n=read(),top1=0,top2=0;
	for (int i=2;i<=n;i++) Log[i]=Log[i/2]+1;
	for (int i=1;i<=n;i++) p[i]=read();
	for (int i=1;i<=n;i++)
	{
		if (i==1) dp[i]=0;
		else if (p[i-1]<p[i])
		{
			int x=top2;
			while (x&&p[st2[x]]<p[i]) x--;
			int l=lower_bound(st1+1,st1+1+top1,st2[x])-st1;
			dp[i]=query(mn1,l,top1)+1;
		}
		else
		{
			int x=top1;
			while (x&&p[st1[x]]>p[i]) x--;
			int l=lower_bound(st2+1,st2+1+top2,st1[x])-st2;
			dp[i]=query(mn2,l,top2)+1;
		}
		while (top1&&p[st1[top1]]>p[i]) top1--;
		st1[++top1]=i;
		mn1[top1][0]=dp[i];
		for (int j=1;(1<<j)<=top1;j++) mn1[top1][j]=min(mn1[top1][j-1],mn1[top1-(1<<(j-1))][j-1]);
		while (top2&&p[st2[top2]]<p[i]) top2--;
		st2[++top2]=i;
		mn2[top2][0]=dp[i];
		for (int j=1;(1<<j)<=top2;j++) mn2[top2][j]=min(mn2[top2][j-1],mn2[top2-(1<<(j-1))][j-1]);
	}
	print(dp[n]);
}

signed main()
{
	int T=read();
	while (T--) work();
	
	return 0;
}