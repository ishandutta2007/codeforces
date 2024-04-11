#include<bits/stdc++.h>
using namespace std;

#define pb push_back
vector<int> v[200001],t[200001],V;
int d[200001],a[200001],n,m,k,q[200001],l,r,x,fa[200011];
bool bo[200001];

int ask(int x) {return (fa[x]==x?x:fa[x]=ask(fa[x]));}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	memset(t,0,sizeof(t));
	for (int i=1; i<=n; i++) scanf("%d",&a[i]),bo[i]=(a[i]>0);
	for (int i=1; i<=m; i++) scanf("%d%d",&l,&r),t[l].pb(r),d[r]++;
	l=1,r=0; for (int i=1; i<=n; i++) if (!d[i]) q[++r]=i,a[i]=((!bo[i])?k:a[i]);
	while (l<=r)
	{
		x=q[l];
		for (int j=0,siz=t[x].size(); j<siz; j++)
		{
			if (!a[t[x][j]]||a[t[x][j]]>=a[x]) 
				{if (bo[t[x][j]]||a[x]==1) return puts("-1"),0; a[t[x][j]]=a[x]-1;}
			if (!(--d[t[x][j]])) q[++r]=t[x][j];
		}
		l++;
	}
	for (int i=1; i<=n; i++) if (d[i]) return puts("-1"),0;
	for (int i=1; i<=n; i++) v[a[i]].pb(i);
	for (int i=1; i<=k; i++)
	{
		V.clear(); fa[i]=i;
		for (int j=0,siz=v[i].size(); j<siz; j++) 
		{
			x=v[i][j],r=0;
			if (bo[x]) {V.pb(x); continue;}
			for (int k=0,sz=t[x].size(); k<sz; k++) r=max(r,a[t[x][k]]);
			r=ask(r+1);
			if (r<i) a[x]=r,v[r].pb(x),fa[r]=r+1;
			else V.pb(x);
		}
		v[i]=V;
		fa[i]=(v[i].size()?i+1:i);
	}
	for (int i=1; i<=k; i++)
		if (!v[i].size()) return puts("-1"),0;
	for (int i=1; i<=n; i++) printf("%d ",a[i]); puts("");
	return 0;
}