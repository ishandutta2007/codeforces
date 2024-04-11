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
#define lb(x) (x)&(-x)
using namespace std;
typedef long long ll;
bool o;
char chh,ss[1<<17],*A=ss,*B=ss;
inline char gc(){
    return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
}
template <typename _Tp> inline void rd(_Tp &x);
template <typename _Tp> inline void wr(_Tp x);
template <typename _Tp> inline _Tp mx(_Tp x,_Tp y);
template <typename _Tp> inline _Tp mn(_Tp x,_Tp y);
ll n,b,ans,tp,st;
ll p[1000001],s;
bool ok[1000001];
inline ll qwq(ll a,ll b){
	tp=0;
	while(a) tp+=a/=b;
	return tp;
}
int main(){
	rd(n);
	rd(b);
	for(int i=2;i<=1000000;i++){
		if(!ok[i]) p[++s]=i;
		for(int j=1;j<=s&&i*p[j]<=1000000;j++){
			ok[i*p[j]]=1;
			if(i%p[j]==0) break;
		}
	}
	ans=1ll<<60;
	for(int i=1;i<=s&&p[i]*p[i]<=b;i++){
		if(b%p[i]==0){
			st=0;
			while(b%p[i]==0) b/=p[i],st++;
			ans=mn(ans,qwq(n,p[i])/st);
		}
	}
	if(b>1) ans=mn(ans,qwq(n,b));
	wr(ans);
}
template <typename _Tp>
    inline void rd(_Tp &x){
    	o=0;
        x=0;
      	while (chh^45&&(chh<48||chh>57)) chh=gc();
      	if(chh==45)o=1,chh=gc();
        while(chh>47&&chh<58){
            x=(x<<1)+(x<<3)+(chh^48);
            chh=gc();
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