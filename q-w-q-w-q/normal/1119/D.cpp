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
int n,q,qwq;
ll s[100001],l,r,ans,sum[100001];
int main(){
	rd(n);
	for(int i=1;i<=n;i++){
		rd(s[i]);
	}
	sort(s+1,s+1+n);
	for(int i=n;i;i--)
	s[i]-=s[i-1];
	sort(s+2,s+1+n);
	for(int i=2;i<=n;i++)
	sum[i]=sum[i-1]+s[i];
	rd(q);
	while(q--){
		rd(l);
		rd(r);
		ans=0;
		qwq=upper_bound(s+2,s+1+n,r-l+1)-s-1;
		ans=sum[mn(qwq,n)];
		if(qwq<n) ans+=(n-qwq)*(r-l+1);
		wr(ans+r-l+1),_t;
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