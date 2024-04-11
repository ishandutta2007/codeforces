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
// #pragma GCC optimize(3)
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
namespace CFConTest{
	const int mod=1e9+7;
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
using namespace CFConTest;
const int N=1e5+5;
int n,m,x[N],y[N],z[N];
vector<pii> v[N];
bool bj[N];
int st[N],top;
int flag,hx,hy;
int pos[37000];
int ch[405][405];
bool vis[N];
namespace PREDFSwork{
	struct BIT{
		int bit[5];
		bool ins(int x){
			for(int i=4;i>=0;i--){
				if(x&(1<<i)){
					if(!bit[i]){
						for(int k=i-1;k>=0;k--){
							if(bit[k] && x&(1<<k)){
								x^=bit[k];
							}
						}
						bit[i]=x;
						for(int k=4;k>i;k--){
							if(bit[k]&(1<<i)){
								bit[k]^=x;
							}
						}
						return 1;
					}
					else x^=bit[i];
				}
			}
			return 0;
		}
	}tmpa,tmpb[7],val[405],cd[N];
	int id(BIT x){
		return x.bit[4]*1024+x.bit[3]*64+x.bit[2]*8+x.bit[1]*2+x.bit[0];
	}
	
	int cnt;
	void dfs(int u){
		if(!vis[id(tmpa)]){
			cnt++;
			val[cnt]=tmpa;
			pos[id(tmpa)]=cnt;
		}
		vis[id(tmpa)]=1;
		if(u==6)return ;
		tmpb[u]=tmpa;
		for(int i=1;i<32;i++){
			if(tmpa.ins(i)==1){
				dfs(u+1);
			}
			tmpa=tmpb[u];
		}
	}
	bool merge(BIT x,BIT y){
		BIT z=x;
		bool flag=1;
		for(int i=4;i>=0;i--){
			if(y.bit[i]){
				flag&=z.ins(y.bit[i]);
			}
		}
		return flag;
	}
	BIT mergee(BIT x,BIT y){
		BIT z=x;
		for(int i=4;i>=0;i--){
			if(y.bit[i]){
				z.ins(y.bit[i]);
			}
		}
		return z;
	}
	void init(){
		dfs(1);
		for(int i=1;i<=cnt;i++){
			for(int k=1;k<=cnt;k++){
				if(merge(val[i],val[k])){
					ch[i][k]=pos[id(mergee(val[i],val[k]))];
				}
			}
		}
	}
}
using namespace PREDFSwork;
bool flg[N];
int deep[N],g[N],f[N*2][380],tx,ty,tz;
int sa[N],sb[N],sc[N],zh[N],gg[N],head;
void dfs(int u,int fa,int id){
	vis[u]=1;
	for(auto i:v[u]){
		if(i.fi==fa)continue;
		if(i.fi==1)continue;
		if(vis[i.fi]){
			if(i.fi>u)flg[id]&=cd[id].ins(deep[i.fi]^deep[u]^i.se);
		}
		else{
			deep[i.fi]=deep[u]^i.se;
			dfs(i.fi,u,id);
		}
	}
}
int sd[N];
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	PREDFSwork::init();
	mem0(vis);
	n=read();m=read();
	for(int i=1;i<=m;i++){
		x[i]=read();y[i]=read();z[i]=read();
		v[x[i]].pb(mp(y[i],z[i]));
		v[y[i]].pb(mp(x[i],z[i]));
	}
	
	for(auto i:v[1]){
		bj[i.fi]=1;st[++top]=i.fi;
		sd[i.fi]=i.se;
	}
	int tval=0,ix;
	for(int i=1;i<=top;i++){
		for(auto k:v[st[i]]){
			if(bj[k.fi] && !zh[k.fi]){
				sa[++head]=st[i];
				sb[head]=k.fi;
				tval=k.se;
				tval^=sd[st[i]];
				tval^=sd[k.fi];
				sc[head]=tval;
				zh[sa[head]]=sb[head];
				zh[sb[head]]=sa[head];
			}
		} 
		if(flag)break;
	}
	for(int i=1;i<=top;i++){
		if(!zh[st[i]]){
			flg[st[i]]=1;
			dfs(st[i],1,st[i]);
			if(flg[st[i]])g[st[i]]=pos[id(cd[st[i]])];
		}
		else {
			flg[st[i]]=1;
			if(!vis[st[i]]){
				dfs(st[i],1,st[i]);
				if(flg[st[i]])g[st[i]]=pos[id(cd[st[i]])];
			}
			else {
				g[st[i]]=g[zh[st[i]]];
			}
		}
	}
	for(int i=1;i<=head;i++){
		if(g[sa[i]] && cd[sa[i]].ins(sc[i])){
			gg[i]=pos[id(cd[sa[i]])];
		}
	}
	f[0][1]=1;
	for(int i=1;i<=top;i++){
		for(int k=1;k<=cnt;k++)f[i][k]=f[i-1][k];
		if(!zh[st[i]]){
			int tmp=g[st[i]];
			for(int k=1;k<=cnt;k++){
				f[i][ch[k][tmp]]=add(f[i][ch[k][tmp]],f[i-1][k]);
			}
		}
	}
	int pre=0;
	for(int i=1;i<=head;i++){
		for(int k=1;k<=cnt;k++){
			int tx=g[sa[i]];
			int ty=g[sb[i]];
			int tz=gg[i];
			f[top+i][k]=add(f[top+i][k],f[top+i-1][k]);
			f[top+i][ch[k][tx]]=add(f[top+i][ch[k][tx]],f[top+i-1][k]);
			f[top+i][ch[k][ty]]=add(f[top+i][ch[k][ty]],f[top+i-1][k]);
			f[top+i][ch[k][tz]]=add(f[top+i][ch[k][tz]],f[top+i-1][k]);
		}
	}
	int ans=0;
	for(int k=1;k<=cnt;k++){
		ans=add(ans,f[top+head][k]);
	}
	cout<<ans;
	return 0;
}