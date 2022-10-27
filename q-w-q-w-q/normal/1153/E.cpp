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
char chh,ss[1<<17],*A=ss,*B=ss;
inline char gc(){
    return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
}
template <typename _Tp> inline void rd(_Tp &x);
template <typename _Tp> inline void wr(_Tp x);
template <typename _Tp> inline _Tp mx(_Tp x,_Tp y);
template <typename _Tp> inline _Tp mn(_Tp x,_Tp y);
int n,a1,b1,a2,b2,t,l,r,m,q;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		printf("? %d %d %d %d\n",1,i,n,i);
		fflush(stdout);
		cin>>t;
		if(t&1){
			if(b1) b2=i;
			else b1=i;
		}
		printf("? %d %d %d %d\n",i,1,i,n);
		fflush(stdout);
		cin>>t;
		if(t&1){
			if(a1) a2=i;
			else a1=i;
		}
	}
	if(a1&&b1){
		printf("? %d %d %d %d\n",a1,b1,a1,b1);
		fflush(stdout);
		cin>>t;
		if(t%2==0) swap(b1,b2);
		printf("! %d %d %d %d\n",a1,b1,a2,b2);
		return 0;
	}
	l=1,r=n;
	if(b1){
		while(l<=r){
			m=(l+r)>>1;
			printf("? %d %d %d %d\n",l,b1,m,b1);
			fflush(stdout);
			cin>>t;
			if(t&1) q=m,r=m-1;
			else l=m+1;
		}
		printf("! %d %d %d %d\n",q,b1,q,b2);
	}
	else{
		while(l<=r){
			m=(l+r)>>1;
			printf("? %d %d %d %d\n",a1,l,a1,m);
			fflush(stdout);
			cin>>t;
			if(t&1) q=m,r=m-1;
			else l=m+1;
		}
		printf("! %d %d %d %d\n",a1,q,a2,q);
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