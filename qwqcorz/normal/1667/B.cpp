#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

struct bit
{
	int t[N],n;
	void send(int _n){n=_n;for (int i=1;i<=n;i++) t[i]=-1e9;}
	void add(int x,int y){for (;x<=n;x+=x&-x) t[x]=max(t[x],y);}
	int query(int x){int ret=-1e9;for (;x;x&=x-1) ret=max(ret,t[x]);return ret;}
}t;
int dp[N],mx[N];
ll sum[N],b[N];
void work()
{
	int n=read();
	for (int i=1;i<=n;i++) b[i]=sum[i]=sum[i-1]+read();
	b[n+1]=0;
	sort(b+1,b+2+n);
	int cnt=unique(b+1,b+2+n)-b-1;
	t.send(cnt);
	for (int i=1;i<=n;i++) sum[i]=lower_bound(b+1,b+1+cnt,sum[i])-b;
	for (int i=1;i<=cnt;i++) mx[i]=-1e9;
	int pos0=lower_bound(b+1,b+1+cnt,0)-b;
	mx[pos0]=0,t.add(pos0,0);
	for (int i=1;i<=n;i++)
	{
		dp[i]=max(dp[i-1]-1,mx[sum[i]]);
		dp[i]=max(dp[i],t.query(sum[i]-1)+i);
		mx[sum[i]]=dp[i];
		t.add(sum[i],dp[i]-i);
	}
	print(dp[n]);
}

signed main()
{
	int T=read();
	while (T--) work();
	
	return 0;
}