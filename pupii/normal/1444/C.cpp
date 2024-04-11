#include<bits/stdc++.h>
typedef long long ll;
#define mod 998244353
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
std::mt19937 rnd(time(NULL));
#define rand rnd
#define pr std::pair<int,int>
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
template<class T>void cxk(T&a,T b){a=a>b?a:b;}
template<class T>void cnk(T&a,T b){a=a<b?a:b;}
#ifdef mod
int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
template<class Ta,class Tb>void inc(Ta&a,Tb b){a=a+b>=mod?a+b-mod:a+b;}
template<class Ta,class Tb>void dec(Ta&a,Tb b){a=a>=b?a-b:a+mod-b;}
#endif
int bel[500010],Bel[500010],n,m,k,ev[500010],eu[500010];
bool del[500010];
std::vector<int>_G[500010];
int _col[500010];
bool flag;
void printc(int x){
	for(int i:_G[x])
		if(!_col[i])_col[i]=3-_col[x],Bel[i]=Bel[x],printc(i);
		else if(_col[i]!=3-_col[x])del[bel[x]]=1;
}
int col[500010];
std::vector<pr>G[500010];
void check(int x){
	for(auto[t,w]:G[x]){
		if(col[t]==-1)col[t]=col[x]^w,check(t);
		else if((col[t]^col[x])!=w)flag=0;
	}
}
pr E[500010];
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	n=gi(),m=gi(),k=gi();int u,v;
	for(int i=1;i<=n;++i)bel[i]=gi();
	for(int i=1;i<=m;++i){
		eu[i]=u=gi(),ev[i]=v=gi();
		if(bel[u]==bel[v])_G[u].push_back(v),_G[v].push_back(u);
	}
	for(int i=1;i<=n;++i)if(!_col[i])_col[i]=1,Bel[i]=i,printc(i);
	std::vector<int>edge;
	auto get=[&](int x){
		int a=bel[eu[x]],b=bel[ev[x]];
		if(a>b)std::swap(a,b);
		return pr{a,b};
	};
	for(int i=1;i<=m;++i)if(bel[eu[i]]!=bel[ev[i]])edge.push_back(i),E[i]=get(i);
	std::sort(all(edge),[&](int a,int b){return E[a]<E[b];});
	ll ans=0,sum=0;for(int i=1;i<=k;++i)sum+=!del[i];
	memset(col,-1,sizeof col);
	for(int l=0,r;l<edge.size();l=r+1){
		r=l;while(r+1<edge.size()&&E[edge[r+1]]==E[edge[r]])++r;
		if(del[bel[eu[edge[l]]]]||del[bel[ev[edge[l]]]])continue;
		std::vector<int>nodes;
		for(int i=l;i<=r;++i){
			int x=Bel[eu[edge[i]]],y=Bel[ev[edge[i]]],w=_col[eu[edge[i]]]!=_col[ev[edge[i]]];
			G[x].push_back({y,w});G[y].push_back({x,w});nodes.push_back(x),nodes.push_back(y);
		}
		flag=1;
		for(int i:nodes)if(col[i]==-1)col[i]=0,check(i);
		if(!flag)--ans;
		for(int i:nodes)col[i]=-1,G[i].clear();
	}
	ans+=sum*(sum-1)/2;
	printf("%lld\n",ans);
	return 0;
}