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
namespace CFConTest{
	const int mod=1e9+7;
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
using namespace CFConTest;
const int N=2005;
int n,m,d,ans,fl;
int f[N][2][N];
char l[N],r[N],v[N];
int dfs(int pos,int flag,int mo){
	if(pos==0){
		return (mo==0);
	}
	if(f[pos][flag][mo]!=-1)return f[pos][flag][mo];
	int summ=0;
	if((n-pos+1)&1){
		for(int i=0;i<=(flag?v[pos]-'0':9);i++){
			if(i==d)continue;
			if(!fl && pos==3 && i==4){
				new char;
			}
			/*if(i==9 && pos==2 && flag==0 && mo==11){
				new char;
			}*/
			summ=add(summ,dfs(pos-1,flag&(v[pos]-'0'==i),(mo*10+i)%m));
		}
	}
	else{
		/*if(pos==3 && mo==8){
			new char;
		}*/
		if(flag && v[pos]-'0'<d)summ=0;
		else{
			summ=dfs(pos-1,flag&(v[pos]-'0'==d),(mo*10+d)%m);
		}
	}
	f[pos][flag][mo]=summ;
	return summ;
}
int calc(){
	memset(f,-1,sizeof(f));
	reverse(v+1,v+n+1);
	return dfs(n,1,0);
}
int check(){
	int summ=0,flag=1;
//	reverse(v+1,v+n+1);
	for(int i=n;i>=1;i--){
		summ=(summ*10+v[i]-'0')%m; 
		if((n-i+1)%2==0 && v[i]-'0'!=d)flag=0;
		if((n-i+1)%2==1 && v[i]-'0'==d)flag=0;
	}
	if(!summ && flag)return 1;
	return 0;
}
int main(){
	#ifdef newbiewzs	
		freopen("data.in","r",stdin);
	#else
	#endif
	m=read();d=read();
	scanf("%s",l+1);
	scanf("%s",r+1);
	n=strlen(l+1);
	memcpy(v,r,sizeof(v));
	ans=calc();
	memcpy(v,l,sizeof(v));
	fl=1;
	ans=del(ans,calc());
	ans=add(ans,check());
	cout<<ans;
    #ifdef newbiewzs
		cerr<<'\n'<<"Time:"<<clock()<<" ms"<<'\n';
	#endif
	return 0;
}