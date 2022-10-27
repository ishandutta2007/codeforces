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
int n,a,b,k[4001],s,t[4001],st;
inline bool check(int q){
	for(int i=1;i<=s;++i)
	if(k[i]==q) return 0;
	return 1;
}
inline bool p(int q){
	if(q<2) return 0;
	for(int i=2;i*i<=q;i+=2)
	if(q%i==0) return 0;
	return 1;
}
int main(){
	//freopen("experiment.in","r",stdin);
	//freopen("experiment.out","w",stdout);
	//qwq
	rd(n);
	rd(a);
	rd(b);
	for(int i=1;i*i<=a||i*i<=b;++i){
		if(a%i==0||b%i==0){
			if(p(i)&&check(i)) k[++s]=i;
			if(a%i==0&&p(a/i)&&check(a/i)) k[++s]=a/i;
			if(b%i==0&&p(b/i)&&check(b/i)) k[++s]=b/i;
		}
	}
	while(--n&&s){
		rd(a);
		rd(b);
		for(int i=1;i<=s;++i)
		if(a%k[i]==0||b%k[i]==0) t[++st]=k[i];
		s=st;
		st=0;
		for(int i=1;i<=s;++i)
		k[i]=t[i];
	}
	if(s==0) wr(-1);
	else wr(k[1]);
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