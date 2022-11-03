#include<bits/stdc++.h>
typedef long long ll;
#define db double
std::mt19937 rnd(time(NULL));
#define rand rnd
#define all(x) (x).begin(),(x).end()
#define pr std::pair<int,int>
#define fi first
#define se second
template<class T>void cxk(T&a,T b){a=a>b?a:b;}
template<class T>void cnk(T&a,T b){a=a<b?a:b;}
ll gi(){
	ll x=0,f=1;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
struct V{db x,y;}P[100010];
int st[300010],po[300010];
db operator^(V a,V b){return a.x*b.y-a.y*b.x;}
V operator+(V a,V b){return{a.x+b.x,a.y+b.y};}
V operator-(V a,V b){return{a.x-b.x,a.y-b.y};}
V operator*(V a,db b){return{a.x*b,a.y*b};}
int EA[300010],EB[300010],down[300010],up[100010],cc[300010];
V EV[300010];
db key[300010];
db sqr(db x){return x*x;}
#define mid ((l+r)>>1)
std::vector<int>vec[524389];
void update(int x,int l,int r,int L,int R,int d){
	if(L<=l&&r<=R)return vec[x].push_back(d);
	if(L<=mid)update(x<<1,l,mid,L,R,d);
	if(mid<R)update(x<<1|1,mid+1,r,L,R,d);
}
void build(int x,int l,int r,int o){
	if(vec[x].size()){
		db lx=P[st[l]].x,rx=P[st[r]].x;
		for(int i:vec[x])key[i]=(P[EA[i]]+EV[i]*((lx-P[EA[i]].x)/EV[i].x)).y+(P[EA[i]]+EV[i]*((rx-P[EA[i]].x)/EV[i].x)).y;
		std::sort(all(vec[x]),[&](int a,int b){return key[a]<key[b];});
		for(int i=0;i<vec[x].size();++i)cc[i]=0;
		for(int i=l;i<=r;++i){
			int L=0,R=vec[x].size(),md;
			while(L<R){
				md=(L+R>>1);
				if(((P[st[i]]-P[EA[vec[x][md]]])^EV[vec[x][md]])<0)L=md+1;else R=md;
			}
			++cc[L];up[st[i]]+=vec[x].size()-L;
		}
		for(int i=1;i<vec[x].size();++i)cc[i]+=cc[i-1];
		if(o==1)for(int i=0;i<vec[x].size();++i)down[vec[x][i]]+=cc[i];
		vec[x].clear();
	}
	if(l!=r)build(x<<1,l,mid,o),build(x<<1|1,mid+1,r,o);
}
#undef mid
int A[300010],E[300010];
std::unordered_map<int,int>Edge[100010];
int main(){
	int n=gi(),m=gi();
	for(int i=1;i<=m;++i){
		EA[i]=gi(),EB[i]=gi();
		Edge[EA[i]][EB[i]]=i;
		Edge[EB[i]][EA[i]]=i;
	}
	db alpha=rand()+0.1145141919810;
	db co=cos(alpha),si=sin(alpha);
	for(int i=1;i<=n;++i){
		int x=gi(),y=gi();st[i]=i;
		P[i].x=co*x-si*y,P[i].y=co*y+si*x;
	}
	std::sort(st+1,st+n+1,[&](int a,int b){return P[a].x<P[b].x;});
	for(int i=1;i<=n;++i)po[st[i]]=i;
	for(int i=1,l,r;i<=m;++i){
		l=po[EA[i]],r=po[EB[i]];if(l>r)std::swap(l,r),std::swap(EA[i],EB[i]);
		EV[i]=P[EB[i]]-P[EA[i]];
		if(l+1<=r-1)update(1,1,n,l+1,r-1,i);
	}
	build(1,1,n,1);
	int Q=gi();
	while(Q--){
		int K=gi();
		for(int i=1;i<=K;++i)A[i]=gi(),st[i]=A[i],up[A[i]]=0;
		for(int i=1;i<K;++i)E[i]=Edge[A[i]][A[i+1]];
		E[K]=Edge[A[K]][A[1]];
		std::sort(st+1,st+K+1,[&](int a,int b){return P[a].x<P[b].x;});
		for(int i=1;i<=K;++i)po[st[i]]=i;
		for(int _=1,i,l,r;_<=K;++_){
			i=E[_];l=po[EA[i]],r=po[EB[i]];
			if(l+1<=r-1)update(1,1,K,l+1,r-1,i);
		}
		build(1,1,K,2);
		ll ans=0;
		for(int i=1;i<=K;++i)ans+=(up[A[i]]&1?0:1);
		for(int i=1;i<=K;++i){
			bool s=up[A[i]]&1;
			V pv=P[A[i-1+K*(i==1)]]-P[A[i]],nx=P[A[i==K?1:i+1]]-P[A[i]];
			if((pv.x>0)==(nx.x>0)&&((pv.y/pv.x>nx.y/nx.x)^(pv.x<0)))s^=1;
			ans+=(s?-1:1)*down[E[i]];
		}
		printf("%lld\n",ans);
	}
	return 0;
}