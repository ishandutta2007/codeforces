#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;

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
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int sqr(int x)
{
	return x*x;
}
int a[N],b[N];
int calc(int l,int p)
{
	return l%p*sqr(l/p+1)+(p-l%p)*sqr(l/p);
}
struct node
{
	int val,pos;
	bool operator <(const node &a)const
	{
		return val<a.val;
	}
}qwq;
priority_queue<node>q;

signed main()
{
	int n=read(),m=read(),ans=0;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=1;
	for (int i=1;i<=n;i++) ans+=sqr(a[i]);
	for (int i=1;i<=n;i++)
	if (b[i]<a[i])
	q.push((node){calc(a[i],b[i])-calc(a[i],b[i]+1),i});
	for (int i=n+1;i<=m;i++)
	{
		qwq=q.top();
		q.pop();
		ans-=qwq.val;
		int now=qwq.pos;
		b[now]++;
		if (b[now]<a[now])
		q.push((node){calc(a[now],b[now])-calc(a[now],b[now]+1),now});
	}
	print(ans);

	return 0;
}