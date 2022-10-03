#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 100005
#define MM 200005
#define MZ 100005
#define Z 100000
#define MS 262145
#define ll long long
#define mod 1000000007
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
inline int qpow(int b,int e){int a=1;for(;e;e>>=1,b=(ll)b*b%mod)if(e&1)a=(ll)a*b%mod;return a;}
inline void Add(int &x,int y){x-=(x+=y)>=mod?mod:0;}
inline void Sub(int &x,int y){x+=(x-=y)<0?mod:0;}
int n,ans;
int lb[MN],rb[MN],len[MN],ilen[MN],pp[MN];
int h[MN],nxt[MM],to[MM],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
int faz[MN],dep[MN],siz[MN],son[MN],top[MN],dfn[MN],idf[MN],dfc;
void DFS0(int u,int f){
	dep[u]=dep[faz[u]=f]+1,siz[u]=1;
	for(int i=h[u];i;i=nxt[i])if(to[i]!=f){
		DFS0(to[i],u);
		siz[u]+=siz[to[i]];
		if(siz[son[u]]<siz[to[i]])son[u]=to[i];
	}
}
void DFS1(int u,int t){
	idf[dfn[u]=++dfc]=u,top[u]=t;
	if(son[u])DFS1(son[u],t);
	for(int i=h[u];i;i=nxt[i])if(to[i]!=faz[u]&&to[i]!=son[u])DFS1(to[i],to[i]);
}
#define li (i<<1)
#define ri (li|1)
#define mid ((l+r)>>1)
#define ls li,l,mid
#define rs ri,mid+1,r
int cnt[MS],sum[MS],tg[MS];
inline void P(int i,int x){Add(sum[i],(ll)x*cnt[i]%mod);Add(tg[i],x);}
inline void pd(int i){if(tg[i])P(li,tg[i]),P(ri,tg[i]),tg[i]=0;}
inline void Build(int i,int l,int r){
	cnt[i]=r-l+1;
	if(l==r)return;
	Build(ls),Build(rs);
}
inline void Mdf(int i,int l,int r,int a,int b,int x){
	if(r<a||b<l)return;
	if(a<=l&&r<=b)return P(i,x);
	pd(i),Mdf(ls,a,b,x),Mdf(rs,a,b,x);
	Add(sum[i]=sum[li],sum[ri]);
}
inline int Qur(int i,int l,int r,int a,int b){
	if(r<a||b<l)return 0;
	if(a<=l&&r<=b)return sum[i];
	pd(i);
	int v=Qur(ls,a,b);
	return Add(v,Qur(rs,a,b)),v;
}
inline void Mdf(int i,int x){
	while(i)Mdf(1,1,Z,dfn[top[i]],dfn[i],x),i=faz[top[i]];
}
inline int Qur(int i){
	int x=0;
	while(i)Add(x,Qur(1,1,Z,dfn[top[i]],dfn[i])),i=faz[top[i]];
	return x;
}
int DFS2(int u){
	int s=ilen[u];
	for(int i=h[u];i;i=nxt[i])if(to[i]!=faz[u])Add(s,DFS2(to[i]));
	Sub(ans,(ll)s*s%mod);
	Add(ans,(ll)dep[u]*ilen[u]%mod*ilen[u]%mod);
	return s;
}
int main(){int x,y;
	scanf("%d",&n);
	F(i,1,n)scanf("%d%d",lb+i,rb+i),len[i]=rb[i]-lb[i]+1,ilen[i]=qpow(len[i],mod-2),pp[i]=i;
	F(i,2,n)scanf("%d%d",&x,&y),ins(x,y),ins(y,x);
	DFS0(1,0),DFS1(1,1);
	{//dep[i]
		static int S[MZ];
		F(i,1,n){
			int v=ilen[i];
			Add(S[lb[i]],v);
			Sub(S[rb[i]+1],v);
		}
		F(i,1,Z)Add(S[i],S[i-1]);
		F(i,1,Z)Add(S[i],S[i-1]);
		F(i,1,n){
			int v=S[rb[i]];
			Sub(v,S[lb[i]-1]);
			v=(ll)v*ilen[i]%mod;
			v=(ll)v*dep[i]%mod;
			Add(ans,v);
			Sub(ans,(ll)dep[i]*ilen[i]%mod);
		}
	}
	Build(1,1,Z);
	sort(pp+1,pp+n+1,[](int i,int j){return rb[i]>rb[j];});
	F(ii,1,n){
		int i=pp[ii];
		int v=Qur(i);
		v=(ll)v*rb[i]%mod*ilen[i]%mod;
		Add(ans,v);
		Mdf(i,(mod-ilen[i])*2%mod);
	}
	F2(i,1,MS)sum[i]=tg[i]=0;
	sort(pp+1,pp+n+1,[](int i,int j){return lb[i]<lb[j];});
	F(ii,1,n){
		int i=pp[ii];
		int v=Qur(i);
		v=(ll)v*lb[i]%mod*ilen[i]%mod;
		Add(ans,v);
		Mdf(i,ilen[i]*2%mod);
	}
	DFS2(1);
	std::vector<int>V1[MZ],V2[MZ];
	F(i,1,n)V1[lb[i]].pb(i),V2[rb[i]].pb(i);
	F2(i,1,MS)sum[i]=tg[i]=0;
	F(x,1,Z){
		for(auto i:V1[x]){
			int v=Qur(i);
			v=(ll)v*ilen[i]%mod*x%mod;
			Sub(ans,v);
		}
		for(auto i:V2[x])Mdf(i,ilen[i]*2%mod);
	}
	F2(i,1,MS)sum[i]=tg[i]=0;
	F(x,1,Z){
		for(auto i:V1[x]){
			int v=Qur(i);
			v=(ll)v*ilen[i]%mod;
			Add(ans,v);
		}
		for(auto i:V2[x])Mdf(i,ilen[i]*2ll%mod*(x+1)%mod);
	}
	F(i,1,n)ans=(ll)ans*len[i]%mod;
	printf("%d\n",ans);
	return 0;
}