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
char a[1001];
int n,x,y;
bool ok[4][4],c;
inline void check(){
	for(int i=1;i<5;i++){
		c=1;
		for(int j=1;j<5;j++)
		if(ok[i][j]==0) c=0;
		if(c){
			for(int j=1;j<5;j++)
			ok[i][j]=0;
		}
	}
	for(int i=1;i<5;i++){
		c=1;
		for(int j=1;j<5;j++)
		if(ok[j][i]==0) c=0;
		if(c){
			for(int j=1;j<5;j++)
			ok[j][i]=0;
		}
	}
}
int main(){
	ch=gc();
	x=y=1;
	while(ch=='0'||ch=='1'){
		if(ch=='0'){
			wr(1),_t,wr(x),_e;
			x=x%4+1;
		}
		else{
			wr(3),_t,wr(y),_e;
			if(y==1) y=3;
			else y=1;
		}
		ch=gc();
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