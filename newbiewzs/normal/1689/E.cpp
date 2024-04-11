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
const int N=2005;
int T,n,a[N];
int f[N+50];
int find(int x){
	if(f[x]!=x)return f[x]=find(f[x]);
	else return x;
}
void merge(int x,int y){
	x=find(x);y=find(y);
	if(x==y)return ;
	f[x]=y;
}
bool check(){
	for(int i=1;i<=n+30;i++)f[i]=i;
	for(int i=1;i<=n;i++){
		for(int k=1;k<=30;k++){
			if(a[i]&(1<<(k-1))){
				merge(i,n+k);
			}
		}
	}
	int kel=find(1);
	for(int i=2;i<=n;i++){
		if(find(i)!=kel)return 0;
	}
	return 1;
}
int lowbit(int x){
	return x&(-x);
}
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	T=read();
	for(int ii=1;ii<=T;ii++){
		n=read();
		int cnt=0;
		for(int i=1;i<=n;i++){
			a[i]=read();
			if(!a[i]){
				cnt++;
				a[i]=1;
			}
		}
		int maxx=0;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,lowbit(a[i]));
		}
		if(!check()){
			for(int i=1;i<=n;i++){
				a[i]++;
				if(check()){
					cnt++;break;
				}
				else{
					a[i]-=2; // =lowbit /oh
					if(check()){
						cnt++;break;
					}
					a[i]++;
				}
			}	
		}
		if(!check()){
			for(int i=1;i<=n;i++){
				if(lowbit(a[i])==maxx){
					cnt++;a[i]--;
					if(!check()){
						for(int k=1;k<=n;k++){
							if(find(k)!=find(i)){
								a[k]++;
								cnt++;
								break; // /oh
							}
						}
					}
					break;
				}
			}	
		}
		cout<<cnt<<'\n';
		for(int i=1;i<=n;i++)cout<<a[i]<<" ";
		cout<<'\n';
	}
    #ifdef newbiewzs
		cerr<<'\n'<<"Time:"<<clock()<<" ms"<<'\n';
	#endif
	return 0;
}