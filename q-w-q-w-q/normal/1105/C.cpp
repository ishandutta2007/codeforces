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
ll n,l,r,mod=1e9+7,f[200001][3],a,b,c;
int main(){
	rd(n);
	rd(l);
	rd(r);
	while(l%3!=0&&l<=r){
		if(l%3==1) b++;
		else c++;
		l++;
	}
	a=r/3-(l-1)/3;
	b+=(r-1)/3-(l-2)/3;
	c+=(r-2)/3-(l-3)/3;
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		f[i][0]=(f[i-1][0]*a%mod+f[i-1][1]*c%mod+f[i-1][2]*b%mod)%mod;
		f[i][1]=(f[i-1][0]*b%mod+f[i-1][1]*a%mod+f[i-1][2]*c%mod)%mod;
		f[i][2]=(f[i-1][0]*c%mod+f[i-1][1]*b%mod+f[i-1][2]*a%mod)%mod;
	}
	wr(f[n][0]);
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