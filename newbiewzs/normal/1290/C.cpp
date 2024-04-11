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
const int N=3e5+5;
int n,m,x,a[N],ta[N],tb[N];
char c[N];
int f[N*2],siz[N*2];
int find(int x){
	if(f[x]!=x)return f[x]=find(f[x]);
	else return x;
}
void merge(int x,int y){
	x=find(x);y=find(y);
	if(x==y)return ;
	siz[y]+=siz[x];f[x]=y;
}
int calc(int x){
	return min(siz[find(x)],siz[find(x+m)]);
}
int main(){
	#ifdef newbiewzs
		freopen("data.in","r",stdin);
	#else
	#endif
	n=read();m=read();
	scanf("%s",c+1);
	for(int i=1;i<=m;i++){
		x=read();
		for(int k=1;k<=x;k++){
			a[k]=read();
			if(!ta[a[k]])ta[a[k]]=i;
			else tb[a[k]]=i;
		}
	}
	// 0  2*m+1 
	for(int i=0;i<=2*m+1;i++)f[i]=i;
	siz[0]=1e9;
	for(int i=1;i<=m;i++)siz[i]=1;
	int ans=0;
	for(int i=1;i<=n;i++){
		int x=ta[i],y=tb[i];
		if(i==3){
			new char;
		}
		if(tb[i]){
			if(c[i]=='0'){
				if(find(x)!=find(y+m)){
					ans=ans-calc(x)-calc(y);
					merge(x,y+m);
					merge(x+m,y);
					ans=ans+calc(x);
				}
			}
			else {
				if(find(x)!=find(y)){
					ans=ans-calc(x)-calc(y);
					merge(x+m,y+m);
					merge(x,y);
					ans=ans+calc(x);
				}
			}
		}
		else {
			if(c[i]=='0'){
				if(find(0)!=find(x+m)){
					ans=ans-calc(x);
					merge(x+m,0);
					ans=ans+siz[find(x)];
				}
			}
			else {
				if(ta[i] && find(0)!=find(x)){
					ans=ans-calc(x);
					merge(x,0);
					ans=ans+siz[find(x+m)];
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}