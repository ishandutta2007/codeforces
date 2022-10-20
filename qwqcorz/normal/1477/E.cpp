#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
const int M=1e6+5;

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
struct bit
{
	int tot[M],sum[M];
	void add(int x,int y){for (int i=x+1;i<M;i+=i&-i) tot[i]+=y,sum[i]+=y*x;}
	int querytot(int x){x++;int ret=0;for (x=min(x,M-1);x>0;x&=x-1) ret+=tot[x];return ret;}
	int querysum(int x){x++;int ret=0;for (x=min(x,M-1);x>0;x&=x-1) ret+=sum[x];return ret;}
	int all(){return querysum(M-1);}
	int rk(int x){return querytot(x);}
	int kth(int k)
	{
		int now=0,tmp=0;
		for (int i=20;i>=0;i--)
		{
			now^=1<<i;
			if (now>=M||tmp+tot[now]>=k) now^=1<<i;
									else tmp+=tot[now];
		}
		return now;
	}
}A,B;
int a[N],b[N],n,m,q,mn;
int f(int k,int t)
{
	return (n-(B.kth(B.rk(t))!=t))*max(t-k-mn,0LL)-((t-k)*B.querytot(t-k)-B.querysum(t-k))+(m-n)*t;
}
int query(int k)
{
	mn=min(A.kth(1),B.kth(1));
	int ret=max({f(k,A.kth(1)),f(k,B.kth(1)),f(k,A.kth(n)),f(k,B.kth(m))});
	int rk=B.rk(B.kth(m)+k);
	if (rk>0) ret=max(ret,f(k,B.kth(rk)));
	if (rk<m) ret=max(ret,f(k,B.kth(rk+1)));
	if (m>1)
	{
		rk=A.rk(B.kth(m-1)+k);
		if (rk>0) ret=max(ret,f(k,A.kth(rk)));
		if (rk<n) ret=max(ret,f(k,A.kth(rk+1)));
	}
	return ret;
}

signed main()
{
	n=read(),m=read(),q=read();
	for (int i=1;i<=n;i++) A.add(a[i]=read(),1);
	for (int i=1;i<=m;i++) B.add(b[i]=read(),1);
	while (q--)
	{
		int opt=read(),k=read();
		if (opt==1) A.add(a[k],-1),A.add(a[k]=read(),1);
		if (opt==2) B.add(b[k],-1),B.add(b[k]=read(),1);
		if (opt==3) print(query(k)+(n-m)*k+A.all()-B.all());
	}
	
	return 0;
}