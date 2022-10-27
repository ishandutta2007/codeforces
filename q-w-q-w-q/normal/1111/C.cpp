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
char chh,ss[1<<17],*A=ss,*B=ss;
inline char gc(){
	return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
}
template <typename _Tp> inline void rd(_Tp &x);
template <typename _Tp> inline void wr(_Tp x);
template <typename _Tp> inline _Tp mx(_Tp x,_Tp y);
template <typename _Tp> inline _Tp mn(_Tp x,_Tp y);
int n,k,x,y,a[100001];
inline ll dfs(int l,int r){
	int p=lower_bound(a+1,a+1+k,l)-a;
	int q=upper_bound(a+1,a+1+k,r)-a-1;
	if(p>q) return x;
	if(l==r) return (q-p+1)*y;
	return mn(1ll*(q-p+1)*(r-l+1)*y,dfs(l,(l+r)>>1)+dfs(((l+r)>>1)+1,r));
}
int main(){
	rd(n);
	rd(k);
	rd(x);
	rd(y);
	for(int i=1;i<=k;i++)
	rd(a[i]);
	sort(a+1,a+1+k);
	wr(dfs(1,1<<n));
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