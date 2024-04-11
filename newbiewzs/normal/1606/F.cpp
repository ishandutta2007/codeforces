#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#include<ctime>
#include<bitset>
#include<set>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define bc(x) __builtin_popcount(x)
#define fl fflush(stdout)
#define re register
#define il inline
#define pii pair<int,int>
#define pil pair<int,long long>
#define pll pair<long long,long long>
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
// #pra gma GCC opti mize(3)
//#define int long long
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
namespace IO_BUFF{
	const int BS=(1<<24)+5;char Buffer[BS],*HD,*TL;
	inline int gc(){
	    if(HD==TL) TL=(HD=Buffer)+fread(Buffer,1,BS,stdin);
	    return (HD==TL)?EOF:*HD++;
	}
	inline int inn(){
	    int x,ch;while((ch=gc())<'0'||ch>'9');x=ch^'0';
	    while((ch=gc())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^'0');return x;
	}
	char ss[19999999],tt[20];int ssl,ttl;
    inline int print(int x)
    {
        if(x<0)ss[++ssl]='-',x=(-x);
		if(!x) ss[++ssl]='0';for(ttl=0;x;x/=10) tt[++ttl]=char(x%10+'0');
        for(;ttl;ttl--) ss[++ssl]=tt[ttl];return ss[++ssl]='\n';
    }
	inline int Flush(){return fwrite(ss+1,sizeof(char),ssl,stdout),ssl=0,0;}
	int read(){
		char c=getchar();int x=1;int s=0;
		while(c<'0' || c>'9'){if(c=='-')x=-1;c=getchar();}
		while(c>='0' && c<='9'){
			s=s*10+c-'0';c=getchar();
		}
		return s*x;
	}
}using namespace IO_BUFF;
const int N=2e5+5; 
const int M=1e8;
int n,x,y,q,val[N],id[N];
ll g[N],ans[N],iy[N];
vi v[N];
vector<pii>t[N];
void dfs(int u,int fa){
	for(auto i:v[u]){
		if(i==fa)continue;
		dfs(i,u);
		val[u]++;
	} 
	val[u]--;
}
#define ls ch[u][0]
#define rs ch[u][1]
#define mid ((l+r)>>1)
int rt[N];
int ch[N*70][2];
ll summ[N*70];
int siz[N*70];
int tot;
void update(int u){
	siz[u]=siz[ls]+siz[rs];
	summ[u]=summ[ls]+summ[rs];
}

int merge(int x,int y,int l,int r){
	if(!x || !y)return x|y;
	if(l==r){
		siz[x]+=siz[y];
		summ[x]+=summ[y];
		return x;
	}
	int tmp=++tot;
	ch[tmp][0]=merge(ch[x][0],ch[y][0],l,mid);
	ch[tmp][1]=merge(ch[x][1],ch[y][1],mid+1,r);
	update(tmp);
	return tmp;
}
bool fll=0;
void add(int &u,int l,int r,int x,int k){
	//if(fll){
	//	cout<<"qaq:"<<l<<" "<<r<<" "<<siz[u]<<endl;
	//	if(l==-4 && r==-2){
	//		new char;
	//	}
	//}
	if(!u)u=++tot;
	if(l==r){
		siz[u]++;
		summ[u]+=k;
		return ;
	}
	if(x<=mid)add(ls,l,mid,x,k);
	else add(rs,mid+1,r,x,k);
	update(u);
}
void add(int &u,int l,int r,int x,int k1,int k2){
	if(!u)u=++tot;
	if(l==r){
		siz[u]+=k1;
		summ[u]+=k2;
		return ;
	}
	if(x<=mid)add(ls,l,mid,x,k1,k2);
	else add(rs,mid+1,r,x,k1,k2);
	update(u);
}
int mq;
/*int query(int u,int l,int r,int x){
	if(l==r){
		return l;
	}
	if(l==-2 && r==-1){
		new char;
	}
	if(mid*siz[ls]+summ[ls]+(val[mq]+mid)>=x)return query(ls,l,mid,x);
	else return query(rs,mid+1,r,x-mid*siz[ls]-summ[ls]);
} */
pll ask(int u,int l,int r,int L,int R){
	//if(fll){
	//	cout<<l<<" "<<r<<" "<<siz[u]<<endl;
	//	if(l==-4 && r==-2){
	//		new char;
	//	}
	//}
	if(!u)return mp(0,0);
	if(L>R)return mp(0,0);
	if(L<=l && R>=r){
		return mp(siz[u],summ[u]);
	}
	pll tmp=mp(0,0),tb=mp(0,0);
	if(L<=mid)tmp=ask(ls,l,mid,L,R);
	if(R>mid)tb=ask(rs,mid+1,r,L,R);
	tmp.fi+=tb.fi;tmp.se+=tb.se;
	return tmp;
}
void clear(int &u,int l,int r,int L,int R){
	if(L>R)return ;
	if(L<=l && R>=r){
		u=0;return;
	}
	if(L<=mid)clear(ls,l,mid,L,R);
	if(R>mid)clear(rs,mid+1,r,L,R);
	update(u);
}
void dfs1(int u,int fa){
	bool flag=0;
	for(auto i:v[u]){
		if(i==fa)continue;
		dfs1(i,u);
		flag=1;
		if(u==1){
			new char;
		}
		rt[u]=merge(rt[u],rt[i],-M,M);
	}
	if(!flag){
		for(auto i:t[u]){
			pll tmp=ask(rt[u],-M,M,-M,i.fi);
			ans[i.se]=tmp.se+val[u]+i.fi+tmp.fi*i.fi;
		}
		add(rt[u],-M,M,-val[u],val[u]);
		g[u]=-val[u];
		return ;
	}
	mq=u;
	int l=-M,r=M,jl=-1;
	while(l<=r){
		pll tmp=ask(rt[u],-M,M,-M,mid);
		if(tmp.second+tmp.fi*mid+(val[u]+mid)>=0)jl=mid,r=mid-1;
		else l=mid+1;
	}
	if(u==3){
		new char;
	}
	g[u]=jl;
	pll tmp=ask(rt[u],-M,M,-M,g[u]-1);
	if(u==1){
		new char;
	}
	for(auto i:t[u]){
		pll tmp=ask(rt[u],-M,M,-M,i.fi);
		ans[i.se]=tmp.se+val[u]+i.fi+tmp.fi*i.fi;
		fll=0;
	}
	add(rt[u],-M,M,g[u],tmp.fi,tmp.se);
	clear(rt[u],-M,M,-M,g[u]-1);
	add(rt[u],-M,M,g[u],val[u]);
	if(u==7){
	//	fll=1;
	//	cout<<"qwq:"<<ask(rt[u],-M,M,-M,-2).fi<<endl;
	//	fll=0;
	}
}
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	// TEST
	n=read();
	for(int i=1;i<n;i++){
		x=read();y=read();
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1,0);
	q=read();
	for(int i=1;i<=q;i++){
		x=read();y=read();
		id[i]=x;iy[i]=y;
		t[x].pb(mp(-y,i));
	}
/*	for(int i=1;i<=n;i++){
		sort(t[i].begin(),t[i].end());
	}*/
	dfs1(1,0);
	for(int i=1;i<=q;i++){
		ans[i]=max(ans[i]+iy[i]+1,(ll)val[id[i]]+1);
		cout<<ans[i]<<'\n';
	}
	return 0;
}