#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#include<bitset>
#include<set>
#include<cmath>
#include<ctime>
#include<random>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define bc(x) __builtin_popcount(x)
#define re register
#define il inline
#define pii pair<int,int>
#define pil pair<int,long long>
#define pll pair<long long,long long>
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
#define cpy(x,y) memcpy(x,y,sizeof(x))
//#pragma GCC optimize(3)
//#define int long long
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
namespace IO_BUFF{
	mt19937 rnd(time(0)^(ll)(new char));
	int rend(int x){
		return rnd()%x+1;
	}
	void rendom_shuffle(int *a,int len){
		shuffle(a+1,a+len+1,rnd);
	}
	const int BS=(1<<24)+5;char Buffer[BS],*HD,*TL;
	inline int gc(){
	    if(HD==TL) TL=(HD=Buffer)+fread(Buffer,1,BS,stdin);
	    return (HD==TL)?EOF:*HD++;
	}
	inline int inn(){
	    int x,ch,s=1;while((ch=gc())<'0'||ch>'9')if(ch=='-')s=-1;x=ch^'0';
	    while((ch=gc())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^'0');return x*s;
	}
	char ssss[19999999],tttt[20];int ssl,ttl;
    inline int print(int x)
    {
        if(x<0)ssss[++ssl]='-',x=(-x);
		if(!x) ssss[++ssl]='0';for(ttl=0;x;x/=10) tttt[++ttl]=char(x%10+'0');
        for(;ttl;ttl--) ssss[++ssl]=tttt[ttl];return ssss[++ssl]='\n';
    }
	inline int Flush(){return fwrite(ssss+1,sizeof(char),ssl,stdout),ssl=0,0;}
	int read(){
		char c=getchar();int x=1;int s=0;
		while(c<'0' || c>'9'){if(c=='-')x=-1;c=getchar();}
		while(c>='0' && c<='9'){
			s=s*10+c-'0';c=getchar();
		}
		return s*x;
	}
}using namespace IO_BUFF;
/*namespace CFConTest{
	const int mod=998244353;
	inline int add(const int &x,const int &y){
		return (x+y>=mod?x+y-mod:x+y);
	}
	inline int del(const int &x,const int &y){
		return (x-y<0?x-y+mod:x-y);
	}
	int ksm(int x,int k){
		int base=1;
		while(k){
			if(k&1)base=1ll*base*x%mod;
			k>>=1;
			x=1ll*x*x%mod;
		}
		return base;
	}
};
using namespace CFConTest;*/
const int N=3e5+5;
int n,m,op,x,y,z,val[N*2],f[N*2],ch[N*2][2],tot;
struct node{
	int x,y,z;
}a[N];
int cmp(node x,node y){
	return x.z<y.z;
}
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
int maxx[N*4],minn[N*4],ca[N*4],ci[N*4],tag[N*4];
void pushdown(int u){
	if(tag[u]==-1)return ;
	if(tag[u]==1){
		tag[ls]=tag[rs]=1;
		maxx[ls]=ca[ls];minn[ls]=ci[ls];
		maxx[rs]=ca[rs];minn[rs]=ci[rs];
	}
	else{
		tag[ls]=tag[rs]=0;
		maxx[ls]=maxx[rs]=-1e9;
		minn[ls]=minn[rs]=1e9;
	}
	tag[u]=-1;
}
void update(int u){
	maxx[u]=max(maxx[ls],maxx[rs]);
	minn[u]=min(minn[ls],minn[rs]);
}
void add(int u,int l,int r,int L,int R,int k){
	if(L<=l && R>=r){
		if(k==1)maxx[u]=ca[u],minn[u]=ci[u],tag[u]=1;
		else maxx[u]=-1e9,minn[u]=1e9,tag[u]=0;
		return ;
	}
	pushdown(u);
	if(L<=mid)add(ls,l,mid,L,R,k);
	if(R>mid)add(rs,mid+1,r,L,R,k);
	update(u);
}
int dfn[N*2],pos[N*2],cnt;
void build(int u,int l,int r){
	tag[u]=-1;
	if(l==r){
		ca[u]=ci[u]=dfn[l];
		minn[u]=1e9;
		maxx[u]=-1e9;
		return ;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	update(u);
	ca[u]=max(ca[ls],ca[rs]);
	ci[u]=min(ci[ls],ci[rs]);
}
int find(int x){
	if(f[x]!=x)return f[x]=find(f[x]);
	else return x;
}
int fu[N*2][20],deep[N*2];
void dfs(int u){
	for(int i=1;i<=19;i++)fu[u][i]=fu[fu[u][i-1]][i-1];
	dfn[u]=++cnt;
	pos[cnt]=u;
	if(ch[u][0]){
		fu[ch[u][0]][0]=u;
		deep[ch[u][0]]=deep[u]+1;
		dfs(ch[u][0]);
	}
	if(ch[u][1]){
		fu[ch[u][1]][0]=u;
		deep[ch[u][1]]=deep[u]+1;
		dfs(ch[u][1]);
	}
}
int lca(int x,int y){
	if(deep[x]<deep[y])swap(x,y);
	for(int i=19;i>=0;i--){
		if(deep[x]-(1<<i)>=deep[y]){
			x=fu[x][i];
		}
	}
	if(x==y)return x;
	for(int i=19;i>=0;i--){
		if(fu[x][i]!=fu[y][i]){
			x=fu[x][i];
			y=fu[y][i];
		}
	}
	return fu[x][0];
}
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();m=read();
	for(int i=1;i<n;i++){
		x=read();y=read();z=read();
		a[i]={x,y,z};
	}
	for(int i=1;i<=n;i++)f[i]=i;tot=n;
	sort(a+1,a+n,cmp);
	for(int i=1;i<n;i++){
		if(find(a[i].x)!=find(a[i].y)){
			tot++;val[tot]=a[i].z;
			ch[tot][0]=find(a[i].x);
			ch[tot][1]=find(a[i].y);
			f[find(a[i].x)]=f[find(a[i].y)]=f[tot]=tot;
		}
	}
	deep[tot]=1;dfs(tot);
	build(1,1,n);
	for(int i=1;i<=m;i++){
		op=read();
		if(op==1){
			x=read();y=read();
			add(1,1,n,x,y,1);
		}
		if(op==2){
			x=read();y=read();
			add(1,1,n,x,y,0);
		}
		if(op==3){
			x=read();
			int ans=-1;
			int tx=minn[1];
			if(tx<1e9){
				int tmp=pos[tx];
				if(tmp!=x)ans=max(ans,val[lca(tmp,x)]);
			}
			int ty=maxx[1];
			if(ty>-1e9){
				int tmp=pos[ty];
				if(tmp!=x)ans=max(ans,val[lca(x,tmp)]);
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}