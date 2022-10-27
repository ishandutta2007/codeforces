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
#define _t putchar(32)
#define _e putchar(10)
#define inf 2147483647
#define ine -2147483647
#define lb(x) ((x)&(-x))
#define sp(x,y) x^=y^=x^=y
using namespace std;
typedef long long ll;
bool o;
char ch,ss[1<<17],*A=ss,*B=ss;
inline char gc(){
	return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
}
template <typename _Tp> inline void rd(_Tp &x);
template <typename _Tp> inline void wr(_Tp x);
template <typename _Tp> inline _Tp mx(_Tp x,_Tp y);
template <typename _Tp> inline _Tp mn(_Tp x,_Tp y);
int n;
ll k,p1[251],p2[251],g[251],c[251][251];
ll f[251][251];
const ll mod=1e9+7;
int main(){
	rd(n);
	rd(k);
	p1[0]=p2[0]=1;
	for(int i=1;i<=n;i++)
	p1[i]=p1[i-1]*k%mod,p2[i]=p2[i-1]*(k-1)%mod;
	for(int i=1;i<=n;i++){
		c[i][0]=1;
		for(int j=1;j<i;j++)
		c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
		c[i][i]=1;
	}
	for(int i=1;i<=n;i++)
	f[1][i]=c[n][i]*p2[n-i]%mod;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<j;k++){
				f[i][j]+=f[i-1][k]*c[n-k][j-k]%mod*p1[k]%mod*p2[n-j]%mod;
				f[i][j]%=mod;
			}
			f[i][j]+=f[i-1][j]*(p1[j]-p2[j]+mod)%mod*p2[n-j]%mod;
			f[i][j]%=mod;
		}
	}
	wr(f[n][n]);
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