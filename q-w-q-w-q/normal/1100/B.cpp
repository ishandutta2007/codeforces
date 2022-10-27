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
int n,m,x,k,qwq[100001];
int l[400001],r[400001],mi[400001];
inline void build(int i,int lt,int rt){
	l[i]=lt,r[i]=rt;
	if(l[i]==r[i]){
		qwq[lt]=i;
		return;
	}
	int m=lt+rt>>1;
	build(i<<1,lt,m);
	build(i<<1|1,m+1,rt);
}
inline void fix(int i){
	mi[qwq[i]]++;
	int x=qwq[i]>>1;
	while(x){
		mi[x]=mn(mi[x<<1],mi[x<<1|1]);
		x>>=1;
	}
}
int main(){
	//freopen("experiment.in","r",stdin);
	//freopen("experiment.out","w",stdout);
	rd(n);
	rd(m);
	build(1,1,n);
	for(int i=1;i<=m;i++){
		rd(x);
		fix(x);
		if(mi[1]>k){
			k++;
			wr(1);
		}
		else wr(0);
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