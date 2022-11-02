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
const int N=3e5+5;
int T,n,m,x,y;
int f[N];
vi v[N];
int find(int x){
	if(f[x]!=x)return f[x]=find(f[x]);
	else return x;
}
void merge(int x,int y){
	x=find(x);y=find(y);
	if(x==y)return ;
	f[x]=y;
}
int vis[N],st[N],deep[N],pd[N],top;
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	T=read();
	while(T--){
		n=read();m=read();
		for(int i=1;i<=n;i++)f[i]=i;
		for(int i=1;i<=m;i++){
			x=read();y=read();
			merge(x,y);
			v[x].pb(y);
			v[y].pb(x);
		}
		bool flag=0;
		for(int i=1;i<=n;i++){
			if(find(i)!=find(1)){
				puts("NO");
				flag=1;
				break;
			}
		}
		if(flag){
			for(int i=1;i<=n;i++)v[i].clear();
			continue;
		}
		puts("YES");
		queue<int>q;
		q.push(1);
		deep[1]=1;
		vis[1]=1;
		while(!q.empty()){
			int u=q.front();q.pop();
			bool flag=0;
			for(auto k:v[u]){
				if(pd[k])flag=1;
			}
			if(!flag)st[++top]=u,pd[u]=1;
			for(auto i:v[u]){
				if(vis[i])continue;
				deep[i]=deep[u]+1;
				vis[i]=1;
				q.push(i);
			}
		}
		cout<<top<<'\n';
		for(int i=1;i<=top;i++)cout<<st[i]<<" ";
		for(int i=1;i<=top;i++){
			for(auto k:v[st[i]]){
				if(pd[k]){
					puts("Fxxk");
				}
			}
		}
		cout<<'\n';
		for(int i=1;i<=n;i++)vis[i]=pd[i]=deep[i]=0,v[i].clear();
		top=0;
	}
	return 0;
}