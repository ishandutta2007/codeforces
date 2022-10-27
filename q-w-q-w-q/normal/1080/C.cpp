#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
//#include<cmath>
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
template <typename _Tp> inline _Tp bs(_Tp x);
template <typename _Tp> inline _Tp sp(_Tp &x,_Tp &y);
int t;
ll n,m,x1,y1,x2,y2,x3,y3,x4,y4,x,y,a,b,c,d,tp;
inline ll get(ll a,ll b,ll c,ll d,bool k){
	if(k){
		if((a+b)&1)
		return ((c-a+1)*(d-b+1)+1)>>1;
		return (c-a+1)*(d-b+1)>>1;
	}
	else{
		if((a+b)&1)
		return (c-a+1)*(d-b+1)>>1;
		return ((c-a+1)*(d-b+1)+1)>>1;
	}
}
int main(){
	//freopen("experiment.in","r",stdin);
	//freopen("experiment.out","w",stdout);
	rd(t);
	while(t--){
		rd(n),rd(m);
		x=(n*m+1)>>1,y=n*m>>1;
		rd(x1),rd(y1),rd(x2),rd(y2),rd(x3),rd(y3),rd(x4),rd(y4);
		x+=get(x1,y1,x2,y2,1),y-=get(x1,y1,x2,y2,1);
		y+=get(x3,y3,x4,y4,0),x-=get(x3,y3,x4,y4,0);
		if(x1>x3) sp(x1,x3),sp(x2,x4),sp(y1,y3),sp(y2,y4);
		tp=0;
		if(x3<=x2){
			if(y3>=y1&&y3<=y2)
			tp=get(x3,y3,mn(x2,x4),mn(y2,y4),1);
			else if(y3<=y1&&y4>=y1)
			tp=get(x3,y1,mn(x2,x4),mn(y2,y4),1);
		}
		wr(x-tp),_t,wr(y+tp),_e;
	}
}
template <typename _Tp>
    inline void rd(_Tp &x){
    	o=0;
        x=0;
        ch=gc();
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
	inline _Tp bs(_Tp x){
		return x<0?-x:x;
	}
template <typename _Tp>
    inline _Tp sp(_Tp &x,_Tp &y){
        _Tp t=x;
        x=y;
        y=t;
    }