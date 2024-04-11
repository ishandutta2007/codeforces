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
ll ans[100001],s,n;
int main(){
	//freopen("experiment.in","r",stdin);
	//freopen("experiment.out","w",stdout);
	rd(n);
	for(int k=2;k*k<=n;k++){
		if(n%k==0){
			ans[++s]=(1+n+1-k)*((n-1)/k+1)/2;
			ans[++s]=(1+n+1-n/k)*((n-1)/(n/k)+1)/2;
		}
	}
	ans[++s]=1;
	ans[++s]=n*(n+1)/2;
	sort(ans+1,ans+1+s);
	s=unique(ans+1,ans+1+s)-ans-1;
	for(int i=1;i<=s;i++)
	wr(ans[i]),_t;
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