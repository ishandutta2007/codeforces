#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int N=1e6,K=6;
const int g[10]={0,0,0,1,0,0,2,0,0,3};

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int a[K],dp[N];
void add(int w,int v){for (int i=N-1;i>=w;i--) dp[i]=max(dp[i],dp[i-w]+v);}

signed main()
{
	int k=read();
	for (int i=0;i<K;i++) a[i]=read();
	for (int i=0;i<N;i++)
	for (int j=0,x=i;x;j++,x/=10) dp[i]+=g[x%10]*a[j];
	for (int i=0,pw=1;i<K;i++,pw=pw*10)
	{
		int tot=(k-1)*3,w=3*pw,v=a[i];
		for (int j=1;j<=tot;j+=j) add(w*j,v*j),tot-=j;
		if (tot) add(w*tot,v*tot);
	}
	int Q=read();
	while (Q--)
	{
		int x=read();
		print(dp[x]);
	}
	
	return 0;
}