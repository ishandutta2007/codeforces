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
const int N=205;
int f[205][205][205];
int c[205][205];
int n;
int g[205][205];
int s[N][N];
int solve(int l,int r,int mid){
	if(f[l][r][mid]!=-1)return f[l][r][mid];
	if(l==r){
		return 0;
	}
	int tmp=1e15;
	for(int i=l;i<mid;i++){
		tmp=min(tmp,solve(l,mid-1,i)+g[l][mid-1]);
	}
	if(l==mid)tmp=0;
	int tmx=1e15;
	for(int i=mid+1;i<=r;i++){
		tmx=min(tmx,solve(mid+1,r,i)+g[mid+1][r]);
	}
	if(mid==r)tmx=0;
	f[l][r][mid]=tmp+tmx;
	return f[l][r][mid];
}
int fu[N];
void work(int l,int r,int mid){
	if(l==r)return ;
	int tmp=1e15,ia=-1;
	for(int i=l;i<mid;i++){
		if(f[l][mid-1][i]+g[l][mid-1]<tmp){
			tmp=f[l][mid-1][i]+g[l][mid-1];
			ia=i;
		}
	}
	if(l!=mid)fu[ia]=mid,work(l,mid-1,ia);
	tmp=1e15;ia=0;
	for(int i=mid+1;i<=r;i++){
		if(f[mid+1][r][i]+g[mid+1][r]<tmp){
			tmp=f[mid+1][r][i]+g[mid+1][r];
			ia=i;
		}
	}
	if(mid!=r)fu[ia]=mid,work(mid+1,r,ia);
}
signed main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();
	for(int i=1;i<=n;i++){
		for(int k=1;k<=n;k++){
			c[i][k]=read();
			s[i][k]=s[i][k-1]+c[i][k];
		}
	}
	memset(f,-1,sizeof(f));
	int ans=1e15;
	for(int i=1;i<=n;i++){
		for(int k=i;k<=n;k++){
			for(int j=i;j<=k;j++){
				g[i][k]+=s[j][i-1]+(s[j][n]-s[j][k]);
			}
		}
	}
	int id;
	for(int i=1;i<=n;i++){
		int tmp=solve(1,n,i);
		if(tmp<ans){
			ans=tmp;
			id=i;
		}
	}
	work(1,n,id);
	for(int i=1;i<=n;i++){
		cout<<fu[i]<<" ";
	}
// 	cout<<ans;
    #ifdef newbiewzs
		cerr<<'\n'<<"Time:"<<clock()<<" ms"<<'\n';
	#endif
	return 0;
}