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
const int H=1e6+5;
const int M=1e6;
int T,n,q,x,a[N],f[N+H],siz[N+H],ans[3],las[H];
int find(int x){
	if(f[x]!=x)return f[x]=find(f[x]);
	else return x;
}
int vis[H],st[H],bj[H],top;
void init(){
	for(int i=2;i<=M;i++){
		if(!vis[i])st[++top]=i,las[i]=i;
		for(int k=1;k<=top && i*st[k]<=M;k++){
			vis[i*st[k]]=1;las[i*st[k]]=st[k];
			if(i%st[k]==0)break;
		}
	}
}
int cd[N],head,pd[N];
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	init();
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)a[i]=read(),f[i]=i,siz[i]=1;
		for(int i=1;i<=n;i++){
			int tmp=1;
			while(a[i]!=1){
				int tp=las[a[i]];
				int cnt=0;
				while(a[i]%tp==0)a[i]/=tp,cnt++;
				if(cnt&1)tmp=tmp*tp;
			}
			if(!siz[n+tmp])cd[++head]=tmp;
			f[n+tmp]=n+tmp;siz[n+tmp]++;
			ans[0]=max(ans[0],siz[n+tmp]);
		}
		for(int i=1;i<=head;i++){
			if(cd[i]==1)continue;
			if(siz[n+cd[i]]&1)continue;
			siz[n+1]+=siz[n+cd[i]];
		}
		ans[1]=max(ans[0],siz[n+1]);
		q=read();	
		for(int i=1;i<=q;i++){
			x=read();
			x=min(x,n);
			cout<<(x==0?ans[0]:ans[1])<<'\n';
		}
		for(int i=1;i<=head;i++){
			siz[n+cd[i]]=0;
		}
		for(int i=1;i<=n;i++)siz[i]=0;
		ans[0]=ans[1]=0;
		siz[n+1]=0;
		head=0;
	}
	return 0;
}