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
#include<cmath>
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
#define int long long
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
int T,n,x,las,ii,jj,kk,hh;
int query(int l,int r){
	cout<<"? "<<l<<" "<<r<<endl;
	cin>>x;
	return x;
}
void clear(){
	
}
int work(int u){
	int tmp=sqrt(u*2);
	for(int i=max(1ll,tmp-100);i<=tmp+100;i++){
		if((i*(i-1))==u*2){
			return i;
		}
	}
	return -1;
}
bool check(int u){
	int tmp=query(1,u);
	int tpp=work(tmp);
	if(tpp==-1)return 0;
	return 1;
}
signed main(){
	#ifdef newbiewzs
	#else
	#endif
	T=read();
	while(T--){
		n=read();
		int summ=query(1,n);
		int l=1,r=n,jl;
		#define mid ((l+r)>>1)
		while(l<=r){
			if(query(1,mid)>=1)jl=mid,r=mid-1;
			else l=mid+1;
		}
		ii=jl-1;
		int tmp=summ-query(ii+1,n)+1;
		jj=ii+tmp;
		kk=jj+work(summ-tmp*(tmp-1)/2)-1;
		cout<<"! "<<ii<<" "<<jj<<" "<<kk<<endl;
	}
	return 0;
}