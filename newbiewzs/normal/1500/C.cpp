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
const int N=1505;
const int h=1747;
const int mod=998244353;
int n,m,a[N][N],b[N][N],p[N],in[N*2],st[N],top;
int sa[N],sb[N];
vi v[N*2];
bool vis[N*2],bj[N*2];
struct node{
	int val;
	int id;
	friend bool operator == (node x,node y){
		return ((x.val==y.val)&&(x.id==y.id));
	}
	friend bool operator < (node x,node y){
		if(x.val!=y.val)return x.val<y.val;
		else return x.id<y.id;
	}
};
set<node>s;
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();m=read();
	for(int i=1;i<=n;i++){
		for(int k=1;k<=m;k++){
			a[i][k]=read();
		}
		for(int k=1;k<=m;k++)sa[i]=(1ll*sa[i]*h%mod+a[i][k]+1)%mod;
	}
	for(int i=1;i<=n;i++){
		for(int k=1;k<=m;k++){
			b[i][k]=read();
		}
		for(int k=1;k<=m;k++)sb[i]=(1ll*sb[i]*h%mod+b[i][k]+1)%mod;
		s.insert({sb[i],i});
	}
	for(int i=1;i<=n;i++){
		auto it=s.lower_bound({sa[i],0});
		if((*it).val!=sa[i]){
			puts("-1");return 0;
		}
		p[(*it).id]=i;
		s.erase(it);
	}
	for(int i=1;i<=m;i++){
		for(int k=1;k<n;k++){
			int u=p[k];
			int vv=p[k+1];
			if(a[u][i]>a[vv][i]){
				v[k+m].pb(i);
				in[i]++;
			}
			else if(a[u][i]!=a[vv][i]){
				v[i].pb(k+m);
			}
		}
	}
	queue<int>q;
	for(int i=1;i<=m;i++)if(!in[i]){
		q.push(i);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(u<=m){
			st[++top]=u;
			for(auto i:v[u]){
				if(!vis[i]){
					vis[i]=1;
					q.push(i);
				}
			}
		}
		else{
			bj[u-m]=1;
			for(auto i:v[u]){
				in[i]--;
				if(!in[i])q.push(i);
			}
		}
	}
	for(int i=1;i<n;i++){
		if(!bj[i] && p[i]>p[i+1]){
			puts("-1");return 0;
		}
	}
	cout<<top<<'\n';
	for(int i=top;i>=1;i--){
		cout<<st[i]<<" ";
	}
	return 0;
}