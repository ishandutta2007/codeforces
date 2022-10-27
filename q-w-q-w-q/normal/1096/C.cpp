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
template <typename _Tp> inline _Tp sp(_Tp &x,_Tp &y);
int t,k,ang,tp,x,y;
bool ok,c;
int main(){
	rd(t);
	while(t--){
		rd(k);
		ok=1;
		for(int i=3;i<=360;i++){
			if(360%i) continue;
			ang=180-360/i;
			if(ang==k){
				wr(i),_e,ok=0;
				break;
			}
			c=1;
			for(int a=2;a<i&&c;a++){
				for(int b=a+1;b<=i;b++){
					if(a==2&&b==3) continue;
					tp=(b-a)*180;
					tp-=(b-a-1)*ang;
					x=ang-(a-2)*(180-ang)/2;
					tp-=x;
					y=(b-2)*(180-ang)/2;
					tp-=y;
					if(tp==k&&(a-2)*(180-ang)%2==0&&(b-2)*(180-ang)%2==0){
						c=0;
						break;
					}
				}
			}
			if(!c){
				wr(i),_e,ok=0;
				break;
			}
		}
		if(ok) puts("-1");
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