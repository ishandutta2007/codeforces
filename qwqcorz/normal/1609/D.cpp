#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;

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
int fa[N],siz[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void merge(int x,int y)
{
	x=find(x),y=find(y);
	if (x==y) return;
	siz[y]+=siz[x];
	fa[x]=y;
}
void GreenDay()
{
	int n=read(),d=read();
	for (int i=1;i<=n;i++) fa[i]=i,siz[i]=1;
	for (int i=1;i<=d;i++)
	{
		int u=read(),v=read();
		merge(u,v);
		vector<int>a;
		for (int i=1;i<=n;i++) if (fa[i]==i) a.push_back(siz[i]);
		sort(a.begin(),a.end(),greater<int>());
		int tot=i-(n-a.size()),ans=a[0];
		for (int i=1;i<min(tot+1,(int)a.size());i++) ans+=a[i];
		print(ans-1);
	}
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
	int T=1;
//	int T=read();
	while (T--) GreenDay();
	
	return 0;
}