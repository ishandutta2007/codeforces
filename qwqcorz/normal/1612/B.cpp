#include<bits/stdc++.h>
using namespace std;
const int N=105;

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
int a[N],vis[N];
void GreenDay()
{
	int n=read(),x=read(),y=read();
	for (int i=1;i<=n;i++) vis[i]=0;
	vis[a[n/2]=x]=1,vis[a[n/2+1]=y]=1;
	for (int i=1,j=n;i<n/2;i++)
	{
		while (vis[j]) j--;
		vis[a[i]=j]=1;
	}
	for (int i=n/2+2,j=1;i<=n;i++)
	{
		while (vis[j]) j++;
		vis[a[i]=j]=1;
	}
	int mn=n,mx=1;
	for (int i=1;i<=n/2;i++) mn=min(mn,a[i]);
	for (int i=n/2+1;i<=n;i++) mx=max(mx,a[i]);
	if (mn!=x||mx!=y) return void(puts("-1"));
	for (int i=1;i<=n;i++) print(a[i]," \n"[i==n]);
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
//	int T=1;
	int T=read();
	while (T--) GreenDay();
	
	return 0;
}