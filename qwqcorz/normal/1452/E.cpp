#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;

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
struct node
{
	int l,r;
	bool operator <(const node &a)const
	{
		return l+r<a.l+a.r;
	}
}a[N];
inline int cross(int l1,int r1,int l2,int r2)
{
	return max(min(r1,r2)-max(l1,l2)+1,0);
}
int pre[N],suf[N];

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int m=read(),n=read(),k=read(),ans=0;
	for (int i=1;i<=n;i++) a[i].l=read(),a[i].r=read();
	sort(a+1,a+1+n);
	for (int i=1;i+k-1<=m;i++)
	for (int j=1,tmp=0;j<=n;j++)
	pre[j]=max(pre[j],tmp+=cross(i,i+k-1,a[j].l,a[j].r));
	for (int i=1;i+k-1<=m;i++)
	for (int j=n,tmp=0;j>=1;j--)
	suf[j]=max(suf[j],tmp+=cross(i,i+k-1,a[j].l,a[j].r));
	for (int i=0;i<=n;i++)
	ans=max(ans,pre[i]+suf[i+1]);
	print(ans);
	
	return 0;
}