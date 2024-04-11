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
#define dbg(x) cerr<<"In Line "<< __LINE__<<" the "<<#x<<" = "<<x<<'\n';
#define dpi(x,y) cerr<<"In Line "<<__LINE__<<" the "<<#x<<" = "<<x<<" ; "<<"the "<<#y<<" = "<<y<<'\n';
#define fer(i,a,b) for(int i=a;i<=b;i++)
#define erf(i,a,b) for(int i=b;i>=a;i--)
// #pragma GCC optimize(3)
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
const int N=4e5+5;
int n,m,x,y;
vi v[N];
int f[N],vis[N],bj[N],in[N],pd[N];
int cmp(int x,int y){
	return f[x]<f[y];
}
void dfs(int u,int deep){
	if(u==n)return ;
	vis[u]=1;bj[u]=1;
	int cnt=0;
	vi st;
	for(auto i:v[u]){
		if(vis[i]){
			if(bj[i])cnt++;
			else st.pb(i);
			continue;
		}
		dfs(i,deep+1);
		st.pb(i);
	}
	sort(st.begin(),st.end(),cmp);
	f[u]=1e9;
	for(int i=0;i<st.size();i++){
		f[u]=min(f[u],f[st[i]]+(int)st.size()-i);
	}
	f[u]+=cnt;
	bj[u]=0;
}
struct node{
	int id,val;
	friend bool operator < (node x,node y){
		return x.val>y.val;
	}
};
priority_queue<node>q;
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();m=read();
	for(int i=1;i<=m;i++){
		x=read();y=read();
		v[y].pb(x);in[x]++;
	}
	mem0x3f(f);
	f[n]=0;
	q.push({n,0});
	while(q.size()){
		node u=q.top();q.pop();
		if(pd[u.id])continue;
		pd[u.id]=1;
		for(auto i:v[u.id]){
			if(f[i]>f[u.id]+in[i]){
				f[i]=f[u.id]+in[i];
				q.push({i,f[i]});
			}
			in[i]--;
		}
	}
	cout<<f[1];
    #ifdef newbiewzs
		cerr<<'\n'<<"Time:"<<clock()<<" ms"<<'\n';
	#endif
	return 0;
}