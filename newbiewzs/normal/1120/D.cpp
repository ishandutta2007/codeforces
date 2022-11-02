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
// #pra gma GCC opti mize(3)
#define int long long
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
int n,a[N],x,y,tot,ans,st[N],ed[N];
vi g[N];
void dfs(int u,int fa){
	int siz=0;st[u]=tot+1;
	for(auto i:g[u]){
		if(i==fa)continue;
		dfs(i,u);siz++;
	}
	if(!siz){
		tot++;
	}
	ed[u]=tot;
}
int da[N];
struct node{
	int x,y,z,id;
}v[N*2];
int cmp(node x,node y){
	return x.z<y.z;
}
map<pii,int>ma;
int f[N];
int find(int x){
	if(f[x]!=x)return f[x]=find(f[x]);
	else return x;
}
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<n;i++){
		x=read();y=read();
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++){
		v[i]={st[i],ed[i]+1,a[i],i};
	}
	sort(v+1,v+n+1,cmp);
	for(int i=1;i<=tot+1;i++)f[i]=i;
	int pre=0;
	for(int i=1;i<=n;i++){
		if(find(v[i].x)!=find(v[i].y)){
			f[find(v[i].x)]=find(v[i].y);
			ans+=v[i].z;
		}
	}
	cout<<ans<<" ";
	for(int i=1;i<=tot+1;i++)f[i]=i;
	for(int i=1;i<=n;i++){
		int r=i;
		while(r<n && v[r+1].z==v[r].z)r++;
		for(int k=i;k<=r;k++){
			if(find(v[k].x)!=find(v[k].y)){
				da[v[k].id]=1;
			}
		}
		for(int k=i;k<=r;k++){
			if(find(v[k].x)!=find(v[k].y)){
				f[find(v[k].x)]=find(v[k].y);
			}
		}
		i=r;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)if(da[i])cnt++;
	cout<<cnt<<'\n';
	for(int i=1;i<=n;i++)if(da[i])cout<<i<<" ";
	return 0;
}