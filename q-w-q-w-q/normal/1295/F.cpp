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
template <typename _Tq> inline void wr(_Tq x);
template <typename _Tp> inline _Tp mx(_Tp x,_Tp y);
template <typename _Tp> inline _Tp mn(_Tp x,_Tp y);
const int mod=998244353,w=100000;
int n,l[51],r[51];
ll f[101][101],ans,tp;
ll inv[51],ffac[101][51];
int v[101],s;
inline ll power(ll a,ll n){
	ll q=a,tp=1;
	while(n){
		if(n&1) tp=1ll*tp*q%mod;
		q=1ll*q*q%mod,n>>=1;
	}
	return tp;
}
int main(){
	rd(n);
	ans=1;
	for(int i=1;i<=n;i++)
	rd(l[i]),rd(r[i]),r[i]++,ans*=r[i]-l[i],ans%=mod;
	ans=power(ans,mod-2);
	for(int i=2;i<=n;i++) if(r[i]>r[i-1]) r[i]=r[i-1];
	for(int i=n-1;i;i--) if(l[i]<l[i+1]) l[i]=l[i+1];
	for(int i=1;i<=n;i++) v[++s]=l[i],v[++s]=r[i];
	sort(v+1,v+1+s);
	s=unique(v+1,v+1+s)-v-1;
	inv[0]=1;
	for(int i=1;i<=n;i++) inv[i]=inv[i-1]*i%mod;
	inv[n]=power(inv[n],mod-2);
	for(int i=n-1;~i;i--) inv[i]=inv[i+1]*(i+1)%mod;
	for(int i=1;i<s;i++){
		ffac[i][0]=v[i+1]-v[i];
		for(int j=1;j<=n;j++) ffac[i][j]=ffac[i][j-1]*(v[i+1]-v[i]+j)%mod;
	}
	f[0][s]=1;
	for(int i=1;i<=n;i++){
		tp=0;
		for(int j=1;j<s;j++){
			if(l[i]>v[j]||r[i]<=v[j]) continue;
			tp=0;
			for(int k=j+1;k<=s;k++) tp+=f[i-1][k],tp%=mod;
			for(int k=i;k<=n;k++){
				if(l[k]>v[j]||r[k]<=v[j]) continue;
				f[k][j]+=tp*ffac[j][k-i]%mod*inv[k-i+1]%mod;
				f[k][j]%=mod;
			}
		}
	}
	tp=0;
	for(int i=1;i<s;i++) tp+=f[n][i],tp%=mod;
	wr(ans*tp%mod);
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