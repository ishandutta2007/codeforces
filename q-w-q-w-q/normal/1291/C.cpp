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
char ch,ss[1<<17],*A=ss,*B=ss;
inline char gc(){
	return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
}
template <typename _Tp> inline void rd(_Tp &x);
template <typename _Tq> inline void wr(_Tq x);
template <typename _Tp> inline _Tp mx(_Tp x,_Tp y);
template <typename _Tp> inline _Tp mn(_Tp x,_Tp y);
int t,n,m,k,ans,tp,l,r,qwq;
int a[3501],st[21][3501];
inline int query(int l,int r){
	if(l>r) return 0;
	int k=log2(r-l+1);
	return mx(st[k][l],st[k][r-(1<<k)+1]);
}
int main(){
	rd(t);
	while(t--){
		rd(n),rd(m),rd(k);
		for(int i=1;i<=n;i++) rd(a[i]);
		for(int i=1;i<=n;i++) st[0][i]=a[i];
		for(int j=1;(1<<j)<=n;j++){
			for(int i=1;i+(1<<j)<=n;i++){
				st[j][i]=mx(st[j-1][i],st[j-1][i+(1<<(j-1))]);
			}
		}
		k=mn(k,m-1);
		ans=0;
		for(int lt=0,rt;lt<=k;lt++){
			rt=k-lt;
			l=lt+1,r=n-rt;
			tp=m-1-lt-rt;
			qwq=inf;
			for(int i=l,j=r-tp;l+tp>=i&&j<=r;i++,j++){
				qwq=mn(qwq,mx(a[i],a[j]));
			}
			ans=mx(ans,qwq);
		}
		wr(ans),_e;
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