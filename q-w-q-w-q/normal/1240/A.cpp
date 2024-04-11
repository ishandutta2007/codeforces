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
char chh,ss[1<<17],*A=ss,*B=ss;
inline char gc(){
	return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
}
template <typename _Tp> inline void rd(_Tp &x);
template <typename _Tp> inline void wr(_Tp x);
template <typename _Tp> inline _Tp mx(_Tp x,_Tp y);
template <typename _Tp> inline _Tp mn(_Tp x,_Tp y);
int t;
int n;
ll a[200001],k,x,y,p,q,qwq,tp;
int l,r,m,ans,c,d;
inline int gcd(int x,int y){
	while(x%y){
		int tp=y;
		y=x%y;
		x=tp;
	}
	return y;
}
inline bool check(int m){
	tp=0;
	for(int i=1;i<=m/qwq;i++)
	tp+=a[i]*(x+y);
	c=m/p-m/qwq;
	d=m/q-m/qwq;
	if(x>y){
		for(int i=m/qwq+1;i<=m/qwq+c;i++)
		tp+=a[i]*x;
		for(int i=m/qwq+c+1;i<=m/qwq+c+d;i++)
		tp+=a[i]*y;
	}
	else{
		for(int i=m/qwq+1;i<=m/qwq+d;i++)
		tp+=a[i]*y;
		for(int i=m/qwq+d+1;i<=m/qwq+d+c;i++)
		tp+=a[i]*x;
	}
	return tp>=k;
}
int main(){
	rd(t);
	while(t--){
		rd(n);
		for(int i=1;i<=n;i++)
		rd(a[i]),a[i]/=100;
		sort(a+1,a+1+n,greater<ll>());
		rd(x);
		rd(p);
		rd(y);
		rd(q);
		rd(k);
		qwq=p/gcd(p,q)*q;
		l=1,r=n,ans=-1;
		while(l<=r){
			m=(l+r)>>1;
			if(check(m)) ans=m,r=m-1;
			else l=m+1;
		}
		wr(ans),_e;
	}
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