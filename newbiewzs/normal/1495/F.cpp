#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<ctime>
#include<set>
#define fi first
#define se second
#define mp make_pair
#define pi pair<int,int>
#define pb push_back
#define pl pair<int,long long>
#define vi vector<int>
#define vl vector<long long>
#define int long long
using namespace std;
typedef long long ll;
const int N=4e5+55;
int n,m,a[N],b[N],p[N],val[N],st[N],head,vis[N],x;
vi v[N];
int deep[N],son[N],siz[N],top[N],fu[N],dis[N];
void link(int x,int y){
	v[x].pb(y);
}
void dfs(int u,int fa){
	siz[u]=1;deep[u]=deep[fa]+1;
	for(unsigned int i=0;i<v[u].size();i++){
		if(v[u][i]==fa)continue;
		dfs(v[u][i],u);
		siz[u]+=siz[v[u][i]];
		if(dis[v[u][i]]<0)dis[u]+=dis[v[u][i]],dis[v[u][i]]=0;
		if(siz[v[u][i]]>siz[son[u]])son[u]=v[u][i];
	}
	dis[u]+=val[u];
}
void dfs1(int u,int fa){
	top[u]=fa;
	if(u)dis[u]+=dis[fu[u]];
	if(son[u])dfs1(son[u],fa);
	for(unsigned int i=0;i<v[u].size();i++){
		if(top[v[u][i]])continue;
		dfs1(v[u][i],v[u][i]);
	}
}
int lca(int x,int y){
	while(top[x]!=top[y]){
		if(deep[top[x]]<deep[top[y]])swap(x,y);
		x=fu[top[x]];
	}
	if(deep[x]<deep[y])swap(x,y);
	return y;
}
int Dis(int x,int y){
	return dis[x]+dis[y]-2ll*dis[lca(x,y)];
}
set<int>s;
set<int>::iterator it,iv;
int da=0;
int fq[N];
void add(int x){
	s.insert(x);
	it=s.lower_bound(x);
	int L=*(--it);
	it++;it++;
	int R;
	if(it==s.end())it=s.begin(),R=*it;
	else R=*it;
	da+=(Dis(L,x)+Dis(R,x)-Dis(L,R));
}
void del(int x){
	iv=it=s.lower_bound(x);
	it--;
	//s.erase(iv);
	int L=*(it);
	it++;it++;
	int R;
	if(it==s.end())it=s.begin(),R=*it;
	else R=*it;
	da-=(Dis(L,x)+Dis(R,x)-Dis(L,R));
	s.erase(iv);
}
int zero[N];
signed main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&p[i]);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)scanf("%lld",&b[i]);
	p[0]=1e9+7;st[++head]=0;
	for(int i=1;i<=n;i++){
		while(head and p[st[head]]<p[i])head--;
		link(st[head],i);fu[i]=st[head];
		st[++head]=i;
	}
	for(int i=1;i<=n;i++){
		val[i]=a[i]-b[i];
		val[fu[i]]+=b[i];
	}
	dfs(0,0);
	dfs1(0,0);
	int ans1=dis[0];
	s.insert(0);
	fq[0]=1;
	for(int i=1;i<=m;i++){
		scanf("%lld",&x);
		if(!vis[x]){
			fq[fu[x]]++;
			if(fq[fu[x]]==1){
				add(fu[x]);
				
			}vis[x]=1;
		}
		else{
			fq[fu[x]]--;
			if(!fq[fu[x]]){
				del(fu[x]);
				
			}vis[x]=0;
		}
		printf("%lld\n",ans1+da/2ll);
	}
	return 0;
}