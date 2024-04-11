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
int n,t,s1[5204][5204],s2[5204][5204],t1,t2,x11,x22,y11,y22;
bool a[5204][5204],ok;
int main(){
	rd(n);
	for(int i=1;i<=n;i++){
		chh=gc();
		while(chh==' '||chh=='\n') chh=gc();
		for(int j=0;j<n/4;j++){
			while(chh==' '||chh=='\n') chh=gc();
			if(chh<='9') t=chh-'0';
			else t=chh-'A'+10;
			a[i][j*4+4]=t&1;
			t>>=1;
			a[i][j*4+3]=t&1;
			t>>=1;
			a[i][j*4+2]=t&1;
			t>>=1;
			a[i][j*4+1]=t&1;
			chh=gc();
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			s1[i][j]=s1[i-1][j]+s1[i][j-1]-s1[i-1][j-1];
			s2[i][j]=s2[i-1][j]+s2[i][j-1]-s2[i-1][j-1];
			if(a[i][j]) s1[i][j]++;
			else s2[i][j]++;
		}
	}
	for(int x=n;x>1;x--){
		if(n%x) continue;
		ok=1;
		for(int i=1;(n+x-1)/x>=i&&ok;i++){
			for(int j=1;(n+x-1)/x>=j&&ok;j++){
				x11=(i-1)*x+1;
				y11=(j-1)*x+1;
				x22=mn(i*x,n);
				y22=mn(j*x,n);
				t1=s1[x22][y22]-s1[x11-1][y22]-s1[x22][y11-1]+s1[x11-1][y11-1];
				t2=s2[x22][y22]-s2[x11-1][y22]-s2[x22][y11-1]+s2[x11-1][y11-1];
				if(t1!=0&&t2!=0) ok=0;
			}
		}
		if(ok){
			wr(x);
			return 0;
		}
	}
	wr(1);
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