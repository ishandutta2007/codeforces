#include<bits/stdc++.h>
typedef long long ll;
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
int d[100010],fir[100010],dis[200010],nxt[200010],dep[200010],id;
std::vector<pr>G[100010];
int s,sum;
void dfs(int x,int tp,int fa=-1){
	if(fa==-1)++d[x];
	if(d[x]!=2){
		if(tp)G[tp].push_back({x,dep[x]-dep[tp]});
		tp=x;
	}
	if(d[x]==1)s|=1<<(dep[x]&1);
	for(int i=fir[x];i;i=nxt[i])if(dis[i]!=fa)dep[dis[i]]=dep[x]+1,dfs(dis[i],tp,x);
}
void DFS(int x){
	int c1=0;
	for(pr i:G[x]){
		DFS(i.fi);
		if(d[i.fi]==1)c1+=i.se==1;
	}
	sum+=std::max(0,c1-1);
}
void link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int n=gi(),a,b;
	for(int i=1;i<n;++i)a=gi(),b=gi(),link(a,b),link(b,a),++d[a],++d[b];
	int rt;for(int i=1;i<=n;++i)if(d[i]!=1)rt=i;
	dfs(rt,0);
	DFS(rt);
	printf("%d %d\n",s==3?3:1,n-1-sum);
	return 0;
}