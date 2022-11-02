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
const int N=1e5+5;
int T,n,x,y,flag,col,a[N],ans[N],tong[N];
vi v[N];
int st[N],top;
struct node{
	int id,val;
	friend bool operator < (node x,node y){
		if(x.id!=y.id)return x.val<y.val;
		else return x.id<y.id;
	}
};
struct ID{
	int pos,col;
}f[N];
int cmp(ID x,ID y){
	if(x.col!=y.col)return x.col<y.col;
	else return x.pos<y.pos;
}
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	T=read();
	while(T--){
		n=read();x=read();y=read();
		for(int i=1;i<=n;i++)a[i]=read(),v[a[i]].pb(i);
		flag=0;
		priority_queue<node>q;
		for(int i=1;i<=n;i++){
			tong[a[i]]++;
			q.push({i,tong[a[i]]});
		}
		for(int i=1;i<=n+1;i++){
			if(!tong[i])col=i;
		}
		for(int i=1;i<=x;i++){
			auto u=q.top();
			q.pop();
			ans[u.id]=a[u.id];
		}
		for(int i=1;i<=n;i++)tong[a[i]]=0;
		
		int summ=0;top=0;
		for(int i=1;i<=n;i++){
			if(ans[i])continue;
			tong[a[i]]++;
			summ++;
			f[++top]={i,a[i]};
		}
		int maxx=0;
		for(int i=1;i<=n+1;i++){
			maxx=max(maxx,tong[i]);
		}
		if(2*maxx>(n-x) && 2*(n-x-maxx)<(y-x)){
			puts("NO");
		}
		else{
			puts("YES");
			int head=maxx+1,tot=0;
			sort(f+1,f+top+1,cmp);
			for(int i=1;i<=top;i++){
				if(tot==y-x)break;
				int tmp=(i+maxx-1)%top+1;
				if(f[tmp].col==f[i].col)ans[f[tmp].pos]=col;
				else{
					tot++;
					ans[f[tmp].pos]=f[i].col;
				}
			} 
			for(int i=1;i<=top;i++){
				if(!ans[f[i].pos]){
					ans[f[i].pos]=col;
				}
			}
			for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
			cout<<'\n';
		}
		for(int i=1;i<=n;i++)ans[i]=tong[a[i]]=0,v[a[i]].clear();
	}
	return 0;
}