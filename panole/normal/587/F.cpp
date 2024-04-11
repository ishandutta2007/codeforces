#include<bits/stdc++.h>
using namespace std;

const int B=200;
int m,n,cnt,st[200010],len[200010],t[200010][26],fa[200010],po[200010],tot,x,qu[200010],l,r,siz[200010],hd[200010],bel[200010];
unsigned int sum[200010],ans[200010],laz[1010],nw[200010];
struct node{int l,r,k;}q[200010];
struct que{int next,ord;}e[22000010];
vector<int> v[200010],V[200010];
char s[200010],S[200010];

void dfs(int x)
{
	for (int i=0,sz=V[x].size(),j; i<sz; i++)
	{
		j=V[x][i];
		for (int k=bel[j]+1; k<=bel[n]; k++) laz[k]++;
		for (int k=j; bel[k]==bel[j]; k++) nw[k]++;
	}
	for (int i=hd[x]; i; i=e[i].next)
	{
		ans[e[i].ord]+=(nw[q[e[i].ord].r]+laz[bel[q[e[i].ord].r]]);
		ans[e[i].ord]-=(nw[q[e[i].ord].l-1]+laz[bel[q[e[i].ord].l-1]]);
	}
	for (int i=0,sz=v[x].size(); i<sz; i++) dfs(v[x][i]);
	for (int i=0,sz=V[x].size(),j; i<sz; i++)
	{
		j=V[x][i];
		for (int k=bel[j]+1; k<=bel[n]; k++) laz[k]--;
		for (int k=j; bel[k]==bel[j]; k++) nw[k]--;
	}
	
}

int main()
{
	scanf("%d%d",&n,&m),st[0]=len[0]=tot=0;
	for (int i=1; i<=n; i++)
	{
		scanf("%s",S),len[i]=strlen(S),st[i]=st[i-1]+len[i-1],x=0;
		for (int j=st[i]; j<st[i]+len[i]; j++) s[j]=S[j-st[i]];
		for (int j=0; j<len[i]; j++)
			if (t[x][S[j]-'a']) x=t[x][S[j]-'a'];
			else t[x][S[j]-'a']=(++tot),x=tot;
		po[i]=x,V[x].push_back(i);
	}
	qu[l=r=1]=0,fa[0]=0;
	while (l<=r)
	{
		x=qu[l++];
		if (!x) 
		{
			for (int i=0; i<26; i++)
				if (t[x][i]) fa[t[x][i]]=0,qu[++r]=t[x][i];
		} else
		{
			for (int i=0; i<26; i++)
				if (t[x][i]) fa[t[x][i]]=t[fa[x]][i],qu[++r]=t[x][i];
				else t[x][i]=t[fa[x]][i];
		}
	}
	for (int i=1; i<=tot; i++) v[fa[i]].push_back(i);
	for (int i=1; i<=m; i++) scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].k);
	for (int i=1; i<=n; i++) if (len[i]>B)
	{
		x=0,memset(siz,0,sizeof(siz)),sum[0]=0;
		for (int j=st[i]; j<st[i]+len[i]; j++) x=t[x][s[j]-'a'],siz[x]++;
		for (int j=r; j>1; j--) siz[fa[qu[j]]]+=siz[qu[j]];
		for (int j=1; j<=n; j++) sum[j]=siz[po[j]]+sum[j-1];
		for (int j=1; j<=m; j++) if (q[j].k==i) ans[j]=sum[q[j].r]-sum[q[j].l-1];
	} 
	bel[0]=bel[n+1]=0;
	for (int i=1; i<=n; i++) bel[i]=(i-1)/B+1;
	memset(nw,0,sizeof(nw)),memset(laz,0,sizeof(laz)),cnt=0;
	for (int i=1,y; i<=m; i++) if (len[q[i].k]<=B)
	{
		x=0,y=q[i].k;
		for (int j=st[y]; j<st[y]+len[y]; j++) x=t[x][s[j]-'a'],e[++cnt]=(que){hd[x],i},hd[x]=cnt;
	}
	dfs(0);
	for (int i=1; i<=m; i++) printf("%u\n",ans[i]);
	return 0;
}