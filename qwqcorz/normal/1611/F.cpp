#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int st[N][20],sum[N];
void GreenDay()
{
	int n=read(),m=read(),ans=0,l=0,r=0;
	for (int i=1;i<=n;i++) st[i][0]=sum[i]=sum[i-1]+read();
	for (int j=1;j<20;j++)
	for (int i=1;i+(1<<j)-1<=n;i++)
	st[i][j]=min(st[i][j-1],st[i+(1<<j-1)][j-1]);
	for (int i=1;i<=n;i++)
	{
		int k=i;
		for (int j=19;j>=0;j--)
		if (k+(1<<j)<=n+1&&st[k][j]>=sum[i-1]-m)
		k+=1<<j;
		if (k-i>ans) ans=k-i,l=i,r=k-1;
	}
	if (ans) print(l,' '),print(r);
		else puts("-1");
}

signed main()
{
//	int T=1;
	int T=read();
	while (T--) GreenDay();
	
	return 0;
}