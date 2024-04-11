#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
//#pragma GCC optimize(3)
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

const int N=1e5+5;
int n,m,v[10];
struct node{
	int id,val;
}w[N];
struct E{
	int a[6],pos;
}a[N];
struct C{
	int pos,val;
}f[N*10];
int tot;
int cpp(C x,C y){
	return x.val<y.val;
}
int id;
int cmpp(E x,E y){
	return x.a[id]<y.a[id];
}
int cmp(node x,node y){
	return x.val<y.val;
}char aa;
#define bitSEET bis 
namespace MYbitset{
	const int M=1e5;
	ull mip[65];
	ull summ=0;
   	int len;
	struct bitSEET{
		ull bit[M/64+5];
		bis() {memset(bit,0,sizeof(bit));}
		void clear(){
			memset(bit,0,sizeof(bit));
		}
		void set0(int x){
			bit[x>>6]&=~mip[x&63];
		}
		void set1(int x){
			bit[x>>6]|=mip[x&63];
		}
		bool operator [](int x){
			return (bit[x>>6]>>(x&63))&1;
		}
		int count(){
			int tmp=0;
			for(int i=0;i<len;i++)tmp+=__builtin_popcountll(bit[i]);
			return tmp;
		}
		bis operator & (const bis &b)const{
			bis tmp;
			for(int i=0;i<len;i++)tmp.bit[i]=bit[i]&b.bit[i];return tmp;
		}
		void operator &= (const bis &b){
			for(int i=0;i<len;i++)bit[i]&=b.bit[i];
		}
		bis operator | (const bis &b)const{
			bis tmp;
			for(int i=0;i<len;i++)tmp.bit[i]=bit[i]|b.bit[i];return tmp;
		}
		void operator |= (const bis &b){
			int i=0;
			for(;i+7<len;i+=8){
				bit[i]|=b.bit[i];
				bit[i+1]|=b.bit[i+1];
				bit[i+2]|=b.bit[i+2];
				bit[i+3]|=b.bit[i+3];
				bit[i+4]|=b.bit[i+4];
				bit[i+5]|=b.bit[i+5];
				bit[i+6]|=b.bit[i+6];
				bit[i+7]|=b.bit[i+7];
			}
			for(;i<len;i++){
				bit[i]|=b.bit[i];
			}
		}
		bis operator ^ (const bis &b)const{
			bis tmp;
			for(int i=0;i<len;i++)tmp.bit[i]=bit[i]^b.bit[i];return tmp;
		}
		void operator ^= (const bis &b){
			for(int i=0;i<len;i++)bit[i]^=b.bit[i];
		}
		int first0(){
			for(int i=0;i<len;i++){
				if(bit[i]!=summ){
					const ull h=(~bit[i]);
					return (i<<6)+__builtin_ffsll(h&(-h))-1;
				}
			}
			return 1e9;
		}
		int first1(){
			for(int i=0;i<len;i++){
				if(bit[i]){
					return (i<<6)+__builtin_ffsll(bit[i]&(-bit[i]))-1;
				}
			}
			return 1e9;
		}
		bis operator << (const int x)const{
			bis tmp;
			const int tx=(x>>6),ty=(x&63);
			ull las=0;
			for(int i=0;i+tx<len;i++){
				tmp.bit[i+tx]=(las|(bit[i]<<ty));
				if(ty)las=(bit[i]>>(64-ty));
			}
			return tmp;
		}
		bis operator >> (const int x)const{
			bis tmp;
			const int tx=(x>>6),ty=(x&63);
			ull las=0;
			for(int i=len-1;i>=tx;i--){
				tmp.bit[i-tx]=(las|(bit[i]>>ty));
				if(ty)las=(bit[i]<<(64-ty));
			}
			return tmp;
		}
	};
	void preweak(){
		for(int i=0;i<=63;i++)mip[i]=(1ull<<i);
		for(int i=0;i<=63;i++)summ|=(1ull<<i);
	}
}; //  len  preweak() 
using namespace MYbitset;
bis b[N/3];
char bb;
int main(){
	#ifdef newbiewzs
	//	cout<<(&bb-&aa)/1024/1024<<'\n';;
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();m=read();preweak();len=n/64+2;
	for(int i=0;i<n;i++){
		for(int k=1;k<=m;k++){
			a[i].a[k]=read();
		}
		w[i].val=read();w[i].id=i;
	}
	sort(w,w+n,cmp);
	for(int i=0;i<n;i++){
		a[w[i].id].pos=i;
	}
	for(int i=0;i<n;i++){
		for(int k=1;k<=m;k++){
			f[++tot]={a[i].pos,a[i].a[k]};
		}
	}
	sort(f+1,f+tot+1,cpp);
	bis s;
	for(int i=0;i<n;i++)s.set1(i);
	int len=n/3;ll ans=1e15;
	for(int T=0;;){
		int R=min(T+len,n-1);
		for(int k=0;k<N/3-1;k++)b[k].clear();
		for(int k=1;k<=tot;k){
			int l=k;
			while(k<tot && f[k+1].val==f[k].val)k++;
			int r=k;
			bis tmp;
			for(int j=l;j<=r;j++){
				tmp.set1(f[j].pos);
			}
			for(int j=l;j<=r;j++){
				if(f[j].pos>=T && f[j].pos<=R)b[f[j].pos-T]|=tmp;
			}
			k=r+1;
		}
		for(int i=0;i<n;i++){
			if(i>=T && i<=R){
				int tmp=b[i-T].first0();
				if(tmp<n){
					ans=min(ans,(ll)(w[i].val+w[tmp].val));
				}
			}
		}
		if(R==n-1)break;
		T=R+1;
	}
	if(ans==1e15){
		cout<<-1;
	}
	else{
		cout<<ans;
	}
	return 0;
}