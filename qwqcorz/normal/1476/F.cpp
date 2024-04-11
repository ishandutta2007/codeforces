#include<bits/stdc++.h>
#define piir pair<int,int>
#define mk make_pair
#define fi first
#define se second
using namespace std;
const int N=3e5+5;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
struct BIT
{
	int n;
	piir t[N];
	void add(int x,piir y){for (;x;x=x&(x-1)) t[x]=min(t[x],y);}
	piir query(int x)
	{
		piir ret=mk(N,0);
		for (;x<=n;x+=x&-x) ret=min(ret,t[x]);
		return ret;
	}
	void send(int _n)
	{
		n=_n;
		for (int i=1;i<=n;i++) t[i]=mk(N,0);
	}
}t;
int p[N],a[N][20],r[N][20],Log[N],dp[N],from[N],vis[N];
int query(int st[][20],int l,int r)
{
	if (l>r) return 0;
	int k=Log[r-l+1];
	return max(st[l][k],st[r-(1<<k)+1][k]);
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int T=read();
	for (int i=2;i<N;i++) Log[i]=Log[i/2]+1;
	while (T--)
	{
		int n=read(); t.send(n);
		for (int i=1;i<=n;i++) p[i]=read();
		for (int i=1;i<=n;i++) a[i][0]=min(i+p[i],n);
		for (int i=n;i>=1;i--)
		{
			vis[i]=0;
			r[i][0]=max(query(r,i+1,a[i][0]),a[i][0]);
			for (int j=1;i+(1<<j)-1<=n;j++)
				a[i][j]=max(a[i][j-1],a[i+(1<<(j-1))][j-1]),
				r[i][j]=max(r[i][j-1],r[i+(1<<(j-1))][j-1]);
		}
		int ans=0;
		t.add(1,mk(1,0));
		for (int i=1;i<=n;i++)
		{
			piir x=t.query(max(i-p[i],1));
//			print(x.fi,','),print(x.se);
			if (x.fi>i) continue;
			dp[i]=max(max(dp[x.se],query(a,x.fi,i-1)),i-1);
			dp[i]=max(dp[i],query(r,i+1,dp[i]));
			from[i]=x.se;
//			print(i,':'),print(dp[i]);
			if (dp[i]>=n) {ans=i; break;}
			t.add(dp[i]+1,mk(max(dp[i]+1,i+1),i));
		}
		if (ans)
		{
			puts("YES");
			while (ans) vis[ans]=1,ans=from[ans];
			for (int i=1;i<=n;i++) putchar("RL"[vis[i]]);
			puts("");
		}
		else puts("NO");
	}
	
	return 0;
}