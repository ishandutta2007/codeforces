#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
const int inf=1LL<<60;

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
	int t[N],n;
	void add(int x,int y){x++;for (;x;x&=x-1) t[x]+=y;}
	int query(int x){x++;int ret=0;for (;x<=n+1;x+=x&-x) ret+=t[x];return ret;}
	void add(int l,int r,int y){add(r,y);if (l>0) add(l-1,-y);}
}t;
int a[N],p[N],b[N];

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) p[i]=read();
	int m=t.n=read();
	for (int i=1;i<=m;i++) b[i]=read();
	t.add(1,m,inf);
	for (int i=1;i<=n;i++)
	{
		int pos=lower_bound(b+1,b+1+m,a[i])-b,x=inf;
		if (b[pos]==a[i]) x=t.query(pos-1);
		t.add(0,pos-1,p[i]);
		t.add(pos,m,min(p[i],0LL));
		t.add(pos,pos,-max(t.query(pos)-x,0LL));
	}
	int ans=t.query(m);
	if (ans<inf/2) puts("YES"),print(ans);
			  else puts("NO");
	
	return 0;
}