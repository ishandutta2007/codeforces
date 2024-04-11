#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

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
struct node
{
	int l,r,id;
	bool operator <(const node &a)const
	{
		return r<a.r;
	}
}a[N];
int fa[N],ans[N];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int st[N],top=0;
int nxt[N],val[N];

signed main()
{
	int n=read(),lst=0,now=0,cnt=0;
	val[0]=n+1;
	for (int i=1;i<=2*n;i++)
	{
		char c=getchar();
		while (c!='+'&&c!='-') c=getchar();
		if (c=='+')
		{
			cnt++;
			for (int j=lst;j<=now;j++) nxt[j]=cnt;
			lst=now+1;
		}
		else val[++now]=read();
	}
	for (int j=lst;j<=now;j++) nxt[j]=n+1;
	st[0]=0;
	for (int i=1;i<=n;i++)
	{
		while (top&&val[st[top]]<val[i]) top--;
		a[i]=(node){nxt[st[top]],nxt[i]-1,val[i]};
		st[++top]=i;
//		print(a[i].l,' ');
//		print(a[i].r,':');
//		print(val[i]);
	}
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=n;i++)
	{
		int pos=find(a[i].l); 
		if (a[i].l>a[i].r||pos>a[i].r||pos==0)
		{
			puts("NO");
			return 0;
		}
		ans[pos]=a[i].id;
		fa[pos]=pos+1;
	}
	puts("YES");
	for (int i=1;i<=n;i++) print(ans[i],' ');

	return 0;
}