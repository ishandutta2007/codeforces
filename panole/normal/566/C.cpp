#include<bits/stdc++.h>
using namespace std;

vector<int> v;
pair<long double,int> ans;
long double f[200010],g[200010],h[200010];
int n,hd[200001],cnt,w[200001],x,y,val,siz[200010];
struct node{int to,next,val;}e[400001];
bool bo[400010];

void addedge(int x,int y,int val) {e[++cnt]=(node){y,hd[x],val},hd[x]=cnt;}
long double calc(long double x) {return x*sqrt(x);}

void getsiz(int x,int fa)
{
	siz[x]=1,v.push_back(x);
	for (int i=hd[x]; i; i=e[i].next)
		if (bo[e[i].to]&&e[i].to!=fa) getsiz(e[i].to,x),siz[x]+=siz[e[i].to];
}

void dfs(int x,int fa,int df,int dg,int dh)
{
	f[x]=calc(df)*w[x],g[x]=calc(dg)*w[x],h[x]=calc(dh)*w[x];
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa) dfs(e[i].to,x,df+e[i].val,dg+e[i].val,dh+e[i].val),f[x]+=f[e[i].to],g[x]+=g[e[i].to],h[x]+=h[e[i].to];
}

long double getans(int x)
{
	long double ans=0;
	for (int i=hd[x]; i; i=e[i].next)
		dfs(e[i].to,x,e[i].val,e[i].val+1,e[i].val-1),ans+=f[e[i].to];
	return ans;
}

pair<long double,int> solve(int x)
{
	v.clear(),getsiz(x,0); 
	if (siz[x]==1) return make_pair(getans(x),x);
	int mi=n+1,mii,ma,nw;
	for (int i=0; i<siz[x]; i++)
	{
		nw=v[i],ma=siz[x]-siz[nw];
		for (int j=hd[nw]; j; j=e[j].next)
			if (bo[e[j].to]&&siz[e[j].to]<siz[nw]&&siz[e[j].to]>ma)
				ma=siz[e[j].to];
		if (ma<mi) mi=ma,mii=nw;
	}
	bo[x=mii]=0,mii=0;
	long double ans=getans(x),Ans=w[x],Mi=ans;
	for (int i=hd[x]; i; i=e[i].next) Ans+=g[e[i].to];
	for (int i=hd[x]; i; i=e[i].next)
		if (bo[e[i].to]&&Ans-g[e[i].to]+h[e[i].to]<Mi) Mi=Ans-g[e[i].to]+h[e[i].to],mii=e[i].to;
	if (mii) return min(make_pair(ans,x),solve(mii));
	else return make_pair(ans,x);
}

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%d",&w[i]);
	for (int i=1; i<n; i++)
	{
		scanf("%d%d%d",&x,&y,&val);
		addedge(x,y,val),addedge(y,x,val);
	}
	memset(bo,1,sizeof(bo)),ans=solve(1);
	printf("%d %.10lf\n",ans.second,(double)ans.first);
	return 0;
}