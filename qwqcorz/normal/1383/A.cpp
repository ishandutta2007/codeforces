#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int M=26;

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
char a[N],b[N];
int fa[M];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void add_edge(int u,int v){fa[find(u)]=find(v);}
bool check(int n)
{
	for (int i=1;i<=n;i++) if (a[i]>b[i]) return puts("-1"),1;
	return 0;
}

signed main(signed bangumi,char *ss1672[])
{
	(void)bangumi,(void)ss1672;
	int T=read();
	while (T--)
	{
		int n=read(),tot=0;
		scanf("%s%s",a+1,b+1);
		for (int i=0;i<M;i++) fa[i]=i;
		if (check(n)) continue;
		for (int i=1;i<=n;i++) if (a[i]!=b[i]) add_edge(a[i]-'a',b[i]-'a');
		for (int i=0;i<M;i++) tot+=fa[i]==i;
		print(M-tot);
	}
	
	return 0;
}