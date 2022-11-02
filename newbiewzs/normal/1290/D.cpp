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
#define flush fflush(stdout)
#ifdef newbiewzs
char starta;
#endif
const int N=1050;
int n,k,xox[10],a[N],val[N];
int id[N],st[N][N],top[N];
void clear(){
	cout<<"R"<<endl;
	flush;
}
int ask(int x){
	cout<<"? "<<x<<endl;
	flush;
	scanf("%s",xox+1);
	return (xox[1]=='Y');
}
int suf(int x){
	if(x<=0)x=-x+1;
	else x=-x;
	return x;
}
#ifdef newbiewzs
char startb;
#endif
int main(){
	#ifdef newbiewzs
		double startt=clock();
	//	freopen("data.in","r",stdin);
	#else
	#endif
	n=read();k=read();
	int len=max(k/2,1),ans=n;
	for(int i=1;i<=n/k;i++){
		clear();
		int head=0;
		for(int h=1;h<=n/len;h++){
			int pos=(i+head+(n/len))%(n/len);
		//	dbg(pos);
			if(pos==0){
				pos=n/len;
			}
			for(int j=(pos-1)*len+1;j<=pos*len;j++){
				if(!val[j]){
					if(ask(j)){
						val[j]=1;ans--;
					}
				}
			}
			head=suf(head);
		}
	}
	cout<<"! "<<ans;
	#ifdef newbiewzs
		double endd=clock();
		cerr<<'\n';
		cerr<<"Time:"<<endd-startt<<" ms"<<'\n';
		cerr<<"Memory:"<<abs(&startb-&starta)/1024/1024<<" MB";
	#endif
	return 0;
}