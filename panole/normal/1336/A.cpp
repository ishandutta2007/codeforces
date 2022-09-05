#include<bits/stdc++.h>
using namespace std;

int n,hd[200010],k,x,y,dep[200010],fa[200010],d[200010],siz[200010];
struct node{int to,next;}e[400010];
set<pair<int,int> > s;
set<pair<int,int> >::iterator it;

int read()
{
	int p=0; char c=getchar();
	while (c>'9'||c<'0') c=getchar();
	while (c>='0'&&c<='9') p=p*10+c-48,c=getchar();
	return p;
}

void dfs(int x)
{
	dep[x]=dep[fa[x]]+1,d[x]=0,siz[x]=1;
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]) fa[e[i].to]=x,dfs(e[i].to),d[x]++,siz[x]+=siz[e[i].to];
	if (!d[x]) s.insert(make_pair(dep[x]-siz[x],x));
}

int main()
{
	scanf("%d%d",&n,&k); int cnt=0;
	for (int i=1; i<n; i++) 
	{
		scanf("%d%d",&x,&y);
		e[++cnt]=(node){y,hd[x]},hd[x]=cnt;
		e[++cnt]=(node){x,hd[y]},hd[y]=cnt;
	}
	s.clear(),dep[0]=0,fa[1]=0,dfs(1);
	long long ans=0;
	while (k--)
	{
		it=s.end(),it--;
		ans+=(*it).first,x=(*it).second,s.erase(it);
		d[fa[x]]--;
		if (!d[fa[x]]) s.insert(make_pair(dep[fa[x]]-siz[fa[x]],fa[x]));
	}
	printf("%I64d\n",ans);
	return 0;
}