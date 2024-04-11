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
int a[100010],b[100010];
std::vector<int>S[100010];
struct qwq{int cost,x,y;};
std::vector<qwq>v;
int fa[100010],head[100010];
int hd(int x){return fa[x]==x?x:fa[x]=hd(fa[x]);}
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int m=gi(),n=gi();
	for(int i=1;i<=m;++i)a[i]=gi();
	for(int i=1;i<=n;++i)b[i]=gi();
	for(int i=1;i<=m;++i){
		int s=gi(),x;
		while(s--)S[i].push_back(x=gi()),v.push_back({b[x]+a[i],i,x});
	}
	std::sort(all(v),[](qwq a,qwq b){return a.cost>b.cost;});
	for(int i=1;i<=n;++i)fa[i]=i;
	ll ans=0;
	for(qwq s:v){
		int x=s.x,y=s.y;
		if(!head[x])head[x]=y;
		else if(hd(y)!=hd(head[x]))fa[hd(y)]=hd(head[x]);
		else ans+=s.cost;
	}
	printf("%lld\n",ans);
	return 0;
}