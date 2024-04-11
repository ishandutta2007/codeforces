#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int f[N],g[N],d[N];
vector<int>e[N];
bool is[N],vis[N];
bool dfs0(int now,int father,int ed,vector<int>&a)
{
	if (now==ed) return a.push_back(now),1;
	for (int to:e[now])
	{
		if (to==father) continue;
		if (dfs0(to,now,ed,a)) return a.push_back(now),1;
	}
	return 0;
}
int dfs1(int now,int father,int k)
{
	f[now]=d[now]=0;
	for (int to:e[now])
	{
		if (to==father||vis[to]) continue;
		int tmp=dfs1(to,now,k)+1;
		f[now]+=tmp>=k;
		d[now]=max(d[now],tmp);
		is[now]|=is[to];
	}
	return d[now];
}
void dfs2(int now,int father,int k,int l)
{
	g[now]=l>=k;
	int mx1=0,mx2=0;
	for (int to:e[now])
	{
		if (to==father) continue;
		if (d[to]+1>mx1) mx2=mx1,mx1=d[to]+1;
		else if (d[to]+1>mx2) mx2=d[to]+1;
	}
	for (int to:e[now])
	{
		if (to==father) continue;
		dfs2(to,now,k,max(d[to]+1==mx1?mx2:mx1,l)+1);
	}
}
bool work()
{
	int n=read(),S=read(),T=read();
	for (int i=1;i<=n;i++) e[i].clear();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	vector<int>a;
	dfs0(T,0,S,a);
	int k=a.size()-1;
	for (int i=1;i<=n;i++) vis[i]=0;
	dfs1(1,0,k);
	dfs2(1,0,k,0);
	bool flag=0;
	for (int i=1;i<=n;i++) flag|=is[i]=f[i]+g[i]>=3;
	if (!flag) return 0;
	for (int i:a) vis[i]=1;
	for (int i=0;i<=k;i++) dfs1(a[i],0,k);
	vector<int>preis(k+1),sufis(k+1);
	vector<pair<int,int>>pred(k+1),sufd(k+1);
	for (int i=0;i<=k;i++) preis[i]=sufis[i]=is[a[i]];
	for (int i=0;i<=k;i++) pred[i]={d[a[i]]-i,i},sufd[i]={d[a[i]]+i,i};
	for (int i=1;i<=k;i++) preis[i]|=preis[i-1];
	for (int i=1;i<=k;i++) pred[i]=max(pred[i],pred[i-1]);
	for (int i=k-1;i>=0;i--) sufis[i]|=sufis[i+1];
	for (int i=k-1;i>=0;i--) sufd[i]=max(sufd[i],sufd[i+1]);
	int l=0,r=k,ld=0,rd=0;
	for (int t=0,T=1;T<=2000;T++,t^=1)
	if (t)
	{
		assert(ld==0);
		if (preis[l]) return 1;
		int pos=pred[l].second,D=d[a[pos]],len=l-pos+D;
		int tmp=min(rd,len);
		len-=tmp,rd-=tmp,r-=len;
		l=pos,ld=D;
		if (l>r) return 1;
	}
	else
	{
		assert(rd==0);
		if (sufis[r]) return 1;
		int pos=sufd[r].second,D=d[a[pos]],len=pos-r+D;
		int tmp=min(ld,len);
		len-=tmp,ld-=tmp,l+=len;
		r=pos,rd=D;
		if (l>r) return 1;
	}
	return 0;
}
signed main()
{
	int T=read();
	while (T--) puts(work()?"YES":"NO");
	
	return 0;
}