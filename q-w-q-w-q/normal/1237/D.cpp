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
int n,a[300001],c[300001],tp;
int p[300001],q[300001],top;
int main(){
	rd(n);
	for(int i=1;i<=n;i++){
		rd(a[i]);
		a[i+n*2]=a[i+n]=a[i];
	}
	p[1]=3*n;
	q[1]=a[3*n];
	top=1;
	c[3*n]=-1;
	for(int i=3*n-1;i;i--){
		if(a[i]<=a[i+1]) c[i]=c[i+1]==-1?-1:c[i+1]+1;
		else{
			tp=upper_bound(q+1,q+1+top,(a[i]-1)/2)-q-1;
			if(!tp) c[i]=-1;
			else c[i]=p[tp]-i;
			if(c[i+1]!=-1){
				if(c[i]==-1) c[i]=c[i+1]+1;
				else c[i]=mn(c[i],c[i+1]+1);
			}
		}
		while(top&&q[top]>=a[i]) top--;
		top++;
		q[top]=a[i];
		p[top]=i;
	}
	for(int i=1;i<=n;i++)
	wr(c[i]),_t;
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