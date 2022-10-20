#include<bits/stdc++.h>
using namespace std;
const int N=6e5+5;

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
int d[7],t[N];
struct node
{
	int id,v;
	bool operator <(const node &a)const
	{
		return v<a.v;
	}
}a[N];

signed main()
{
	for (int i=1;i<=6;i++) d[i]=read();
	int n=read(),cnt=0,tot=0,ans=1e9+7;
	for (int i=1;i<=n;i++)
	{
		int x=read();
		for (int j=1;j<=6;j++) a[++cnt]=(node){i,x-d[j]};
	}
	sort(a+1,a+1+cnt);
	for (int l=1,r=1;r<=cnt;r++)
	{
		if (t[a[r].id]==0) tot++;
		t[a[r].id]++;
		while (l<=r&&t[a[l].id]>1)
		{
			t[a[l].id]--;
			l++;
		}
		if (tot==n) ans=min(ans,a[r].v-a[l].v);
	}
	print(ans);

	return 0;
}