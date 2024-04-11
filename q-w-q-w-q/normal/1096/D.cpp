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
int n,s;
int k[100001],x;
ll f[100001][4];
int main(){
	//freopen("experiment.in","r",stdin);
	//freopen("experiment.out","w",stdout);
	rd(n);
	for(int i=1;i<=n;i++){
		ch=gc();
		while(ch<'a'||ch>'z') ch=gc();
		if(ch=='h') k[i]=1;
		if(ch=='a') k[i]=2;
		if(ch=='r') k[i]=3;
		if(ch=='d') k[i]=4;
	}
	for(int i=1;i<=n;i++){
		rd(x);
		if(k[i]){
			s++;
			if(s==1){
				if(k[i]==1)
				f[1][0]=x,f[1][1]=0;
				else f[1][1]=1ll<<62;
				f[1][2]=f[1][3]=1ll<<62;
				continue;
			}
			if(k[i]^1) f[s][0]=f[s-1][0];
			else f[s][0]=f[s-1][0]+x;
			for(int j=1;j<4;j++){
				if(j==k[i])f[s][j]=mn(f[s-1][j-1],f[s-1][j]);
				else if(j+1==k[i]) f[s][j]=f[s-1][j]+x;
				else f[s][j]=f[s-1][j];
			}
		}
	}
	wr(mn(mn(f[s][0],f[s][1]),mn(f[s][2],f[s][3])));
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