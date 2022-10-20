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
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int f[N],c[N],Max[N];

signed main()
{
	int n=read();
	for (int i=1;i<=n;i++)
	{
		int x=read(),y=read();
		if (x>n&&y>n) return puts("-1"),0;
		if (x<=y) f[x]=y,c[x]=0;
			 else f[y]=x,c[y]=1;
	}
	int top1=n+n+1,top2=n+n+1,tot1=0,tot2=0,c1=0,c2=0,Min=n+n+1,ans=0;
	for (int i=n;i>=1;i--) Max[i]=max(Max[i+1],f[i]);
	for (int i=1;i<=n;i++)
	{
		Min=min(Min,f[i]);
		if (top1>top2) swap(top1,top2),swap(tot1,tot2),swap(c1,c2);
		if (f[i]<top1) top1=f[i],tot1++,c1+=c[i];
		else if (f[i]<top2) top2=f[i],tot2++,c2+=c[i];
		else return puts("-1"),0;
		if (Min>Max[i+1])
		{
			ans+=min(c1+tot2-c2,c2+tot1-c1);
			top1=top2=n+n+1;
			tot1=tot2=c1=c2=0;
		}
	}
	print(ans);
	
	return 0;
}