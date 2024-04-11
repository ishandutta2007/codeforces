#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

const int mod1=945536861,mod2=945536903; 
int n,tp[100001],tot,hd[100001],fa[100001],cnt,x,y,siz[100001],dfn[100001],m,c[100001],s1,s2,an,ans,z,tmp,son[100001],dep[100001],X,Y,ff[100001][18],tn,Tn,nxt[301],Z,qx[100001],qy[100001],ql[100001];
char s[111],ss[3],t[301],T[301],qs[100001][111];
vector<int> a[200001];
map<pair<int,int>,int> mp;
map<pair<int,int>,int>::iterator it;

struct node
{
	int to,next,c;
}e[200001];

void addedge(int x,int y,int z)
{
	e[++cnt].next=hd[x];
	hd[x]=cnt;
	e[cnt].to=y;
	e[cnt].c=z;
}

void dfs(int x)
{
	siz[x]=1;
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]) dep[e[i].to]=dep[x]+1,c[e[i].to]=e[i].c,fa[e[i].to]=x,dfs(e[i].to),siz[x]+=siz[e[i].to];
}

void Dfs(int x)
{
	dfn[x]=(++cnt); int ma=0,maa;
	s1=s2=0;
	for (int j=1,k=x; j<=100&&k!=1; j++,k=fa[k])
	{
		s1=(27ll*s1+c[k])%mod1;
		s2=(27ll*s2+c[k])%mod2;
		it=mp.find(make_pair(s1,s2));
		if (it!=mp.end()) a[(*it).second].push_back(cnt);
	}
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]&&siz[e[i].to]>ma) ma=siz[e[i].to],maa=e[i].to;
	if (!ma) return;
	son[x]=maa;
	tp[maa]=tp[x]; Dfs(maa);
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]&&e[i].to!=maa) tp[e[i].to]=e[i].to,Dfs(e[i].to);
}

int lca(int x,int y)
{
	if (dfn[x]<dfn[y]) tmp=x,x=y,y=tmp;
	while (tp[x]!=tp[y])
	{
		x=fa[tp[x]];
		if (dfn[x]<dfn[y]) tmp=x,x=y,y=tmp;
	}
	return y;
}

int query(int x,int y)
{
	if (x>y) return 0;
	int l=0,r=a[Z].size()-1,mid,ansl,ansr;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (a[Z][mid]<x) ansl=mid,l=mid+1; else r=mid-1;
	}
	l=0; r=a[Z].size()-1;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (a[Z][mid]>y) ansr=mid,r=mid-1; else l=mid+1;
	}
	return ansr-ansl-1;
}

int main()
{
	scanf("%d",&n); cnt=tot=0;
	memset(hd,0,sizeof(hd));
	for (int i=1; i<n; i++) 
	{
		scanf("%d%d",&x,&y); scanf("%s",s);
		addedge(x,y,s[0]-'a'+1);
		addedge(y,x,s[0]-'a'+1);
	}
	scanf("%d",&m); mp.clear();
	for (int pjy=1; pjy<=m; pjy++)
	{
		scanf("%d%d",&x,&y); scanf("%s",s);
		qx[pjy]=x; qy[pjy]=y; 
		s1=s2=0; z=strlen(s); ql[pjy]=z;
		for (int i=0; i<z; i++) qs[pjy][i]=s[i];
		for (int i=0; i<z; i++) s1=(27ll*s1+(s[i]-'a'+1))%mod1,s2=(27ll*s2+(s[i]-'a'+1))%mod2;
		it=mp.find(make_pair(s1,s2));
		if (it==mp.end()) 
		{
			mp[make_pair(s1,s2)]=(++tot);
			a[tot].clear(); a[tot].push_back(0);	
		}
		s1=s2=0;
		for (int i=z-1; i>=0; i--) s1=(27ll*s1+(s[i]-'a'+1))%mod1,s2=(27ll*s2+(s[i]-'a'+1))%mod2;
		it=mp.find(make_pair(s1,s2));
		if (it==mp.end()) 
		{
			mp[make_pair(s1,s2)]=(++tot);
			a[tot].clear(); a[tot].push_back(0);	
		}
	}
	memset(fa,0,sizeof(fa));
	dep[0]=0; dep[1]=1; tp[1]=1; cnt=0; dfs(1); Dfs(1);
	for (int i=1; i<=n; i++) ff[i][0]=fa[i];
	for (int i=0; i<=17; i++) ff[0][i]=0;
	for (int j=1; j<=17; j++)
		for (int i=1; i<=n; i++) ff[i][j]=ff[ff[i][j-1]][j-1];
	for (int i=1; i<=tot; i++) a[i].push_back(n+1);
	for (int pjy=1; pjy<=m; pjy++)
	{
		x=qx[pjy]; y=qy[pjy];
		s1=s2=0; z=ql[pjy];
		for (int i=0; i<z; i++) s[i]=qs[pjy][i];
		for (int i=0; i<z; i++) s1=(27ll*s1+(s[i]-'a'+1))%mod1,s2=(27ll*s2+(s[i]-'a'+1))%mod2;
		it=mp.find(make_pair(s1,s2)); Z=(*it).second;
		an=lca(x,y); ans=0;
		X=x; Y=y;
		for (int j=17; j>=0; j--)
			if (dep[ff[X][j]]-dep[an]>=z) X=ff[X][j];
		for (int j=17; j>=0; j--)
			if (dep[ff[Y][j]]-dep[an]>=z) Y=ff[Y][j];
		if (dep[X]-dep[an]>=z) X=fa[X];
		if (dep[Y]-dep[an]>=z) Y=fa[Y];
		while (tp[x]!=tp[an])
		{
			if (dep[tp[x]]-dep[an]<z) break;
			ans+=query(dfn[tp[x]],dfn[x]); x=fa[tp[x]];
		}
		if (dep[x]-dep[an]>=z) ans+=query(dfn[son[X]],dfn[x]);
		s1=s2=0;
		for (int i=z-1; i>=0; i--) s1=(27ll*s1+(s[i]-'a'+1))%mod1,s2=(27ll*s2+(s[i]-'a'+1))%mod2;
		it=mp.find(make_pair(s1,s2)); Z=(*it).second;
		while (tp[y]!=tp[an])
		{
			if (dep[tp[y]]-dep[an]<z) break;
			ans+=query(dfn[tp[y]],dfn[y]); y=fa[tp[y]];
		}
		if (dep[y]-dep[an]>=z) ans+=query(dfn[son[Y]],dfn[y]);
		tn=Tn=-1;
		for (int i=X; i!=an; i=fa[i]) t[++tn]=c[i]+'a'-1;
		for (int i=Y; i!=an; i=fa[i]) T[++Tn]=c[i]+'a'-1;
		for (int i=Tn; i>=0; i--) t[++tn]=T[i];
		int i=0,j=-1;
		nxt[i]=-1;
		while (i<z)
		{
			if (j==-1||s[i]==s[j]) nxt[++i]=(++j);
			else j=nxt[j];
		}
		i=j=0;
		while (i<=tn)
		{
			if (j==-1||t[i]==s[j]) ++i,++j; else j=nxt[j];
			if (j==z) ans++,j=nxt[j-1],i--; 
		}
		printf("%d\n",ans);
	}
	return 0;
}