#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;

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
const int MAX=1;
const int MIN=-1;
struct mqueue
{
	int a[N],q[N],n,h,t,f;
	void send(int *b,int _n,int _f)
	{
		n=_n,f=_f,h=1,t=0;
		for (int i=1;i<=n;i++) a[i]=b[i]*f;
	}
	void push(int i)
	{
		while (h<=t&&a[q[t]]<a[i]) t--;
		q[++t]=i;
	}
	void pop(int l){while (h<=t&&q[h]<=l) h++;}
	int query(int x=0)
	{
		if (!x) return f*a[q[h]];
		return f*max(h<=t?a[q[h]]:-(int)1e9-7,f*x);
	}
}mn[2],mx[2];
int a[N],ans[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),answer=0;
	for (int i=1;i<=n;i++) a[i]=read();
	mn[0].send(a,n,MIN);
	mn[1].send(a,n,MIN);
	mx[0].send(a,n,MAX);
	mx[1].send(a,n,MAX);
	for (int l=1,r=0;l<=n;)
	{
		if ((r-l+1)&1)
		{
			answer=max(answer,(r-l)/2);
			if (l==r) ans[r]=a[r];
			else if (mx[~r&1].query()<mn[r&1].query()) ans[(l+r)/2]=mn[r&1].query();
			else if (mx[r&1].query()<mn[~r&1].query()) ans[(l+r)/2]=mx[r&1].query();
			else assert(0);
		}
//		print(l,','),print(r,':');
//		print(mn[0].query(),' ');
//		print(mx[0].query(),' ');
//		print(mn[1].query(),' ');
//		print(mx[1].query());
		if (r<n&&(l>r||mx[~r&1].query(a[r+1])<mn[r&1].query()||mx[r&1].query()<mn[~r&1].query(a[r+1])))
		{
			r++;
			mn[r&1].push(r);
			mx[r&1].push(r);
		}
		else
		{
			mn[l&1].pop(l);
			mx[l&1].pop(l);
			l++;
		}
	}
	print(answer);
	for (int i=1;i<=n;i++) print(ans[i],' ');
	
	return 0;
}