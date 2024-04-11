#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#define _t putchar(32)
#define _e putchar(10)
#define inf 2147483647
#define ine -2147483647
#define lb(x) (x)&(-x)
using namespace std;
typedef long long ll;
bool o;
char ch,ssss[1<<17],*A=ssss,*B=ssss;
inline char gc(){
    return A==B&&(B=(A=ssss)+fread(ssss,1,1<<17,stdin),A==B)?EOF:*A++;
}
template <typename _Tp> inline void rd(_Tp &x);
template <typename _Tp> inline void wr(_Tp x);
template <typename _Tp> inline _Tp mx(_Tp x,_Tp y);
template <typename _Tp> inline _Tp mn(_Tp x,_Tp y);
template <typename _Tp> inline _Tp sp(_Tp &x,_Tp &y);
int t,n,m,f[300001],ne[600001],to[600001],s,tmp,x,y;
ll ans,mod=998244353;
bool ok,v[300001],odd[300001];
inline ll qwq(int n){
	ll tp=1,q=2;
	while(n){
		if(n&1) tp=tp*q%mod;
		n>>=1,q=q*q%mod;
	}
	return tp;
}
inline void link(int x,int y,int k){
	to[k]=y;
	ne[k]=f[x];
	f[x]=k;
}
inline void dfs(int i,bool tq){
	tmp++;
	v[i]=1;
	odd[i]=tq;
	if(tq) s++;
	int y;
	for(int k=f[i];k;k=ne[k]){
		y=to[k];
		if(!v[y]) dfs(y,!tq);
		else if(tq==odd[y]) ok=0;
	}
}
int main(){
	rd(t);
	while(t--){
		rd(n);
		rd(m);
		for(int i=1;i<=m;i++){
			rd(x);
			rd(y);
			link(x,y,(i<<1)-1);
			link(y,x,i<<1);
		}
		ans=1;
		for(int i=1;i<=n;i++){
			if(!v[i]){
				s=0,tmp=0;
				ok=1;
				dfs(i,1);
				if(ok){
					if(tmp==1) ans*=3;
					else ans*=qwq(s)+qwq(tmp-s);
					ans%=mod;
				}
				else ans=0;
			}
			f[i]=v[i]=0;
		}
		wr(ans),_e;
	}
}
template <typename _Tp>
    inline void rd(_Tp &x){
    	o=0;
        x=0;
      	while (ch^45&&(ch<48||ch>57)) ch=gc();
      	if(ch==45)o=1,ch=gc();
        while(ch>47&&ch<58){
            x=(x<<1)+(x<<3)+(ch^48);
            ch=gc();
        }
      	if(o) x=-x;
 	}
template <typename _Tp>
    inline void wr(_Tp x){
        if(x<0) x=-x,putchar(45);
        if(x<10){
            putchar(x+48);
            return;
        }
        wr(x/10);
        putchar(x%10+48);
    }
template <typename _Tp>
    inline _Tp mx(_Tp x,_Tp y){
        return x>y?x:y;
    }
template <typename _Tp>
    inline _Tp mn(_Tp x,_Tp y){
        return x<y?x:y;
    }
template <typename _Tp>
    inline _Tp sp(_Tp &x,_Tp &y){
        _Tp t=x;
        x=y;
        y=t;
    }