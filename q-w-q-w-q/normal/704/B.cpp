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
#define lb(x) ((x)&(-(x)))
#define sp(x,y) x^=y^=x^=y
using namespace std;
typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
bool o;
char ch,SSS[1<<17],*A=SSS,*B=SSS;
inline char gc(){
	return A==B&&(B=(A=SSS)+fread(SSS,1,1<<17,stdin),A==B)?EOF:*A++;
}
template <typename _Tp> inline void rd(_Tp &x);
template <typename _Tq> inline void wr(_Tq x);
template <typename _Tp> inline _Tp mx(_Tp x,_Tp y);
template <typename _Tp> inline _Tp mn(_Tp x,_Tp y);
int n,s,e;
ll x[5001],a[5001],b[5001],c[5001],d[5001];
ll f[5005][5005];
inline void check(ll &x,ll y,ll v){
	if(x>y+v) x=y+v;
}
int main(){
	rd(n),rd(s),rd(e);
	for(int i=1;i<=n;i++) rd(x[i]);
	for(int i=1;i<=n;i++) rd(a[i]),a[i]+=x[i];
	for(int i=1;i<=n;i++) rd(b[i]),b[i]-=x[i];
	for(int i=1;i<=n;i++) rd(c[i]),c[i]+=x[i];
	for(int i=1;i<=n;i++) rd(d[i]),d[i]-=x[i];
	if(n==2){
		if(s<e) wr(d[s]+a[e]);
		else wr(c[s]+b[e]);
		return 0;
	}
	memset(f,0x7f,sizeof(f));
	f[0][0]=0;
	for(int i=0;i<n;i++){
		if(i+1==s){
			for(int j=0;j<=i;j++){
				if(j>(i>=e)||(i+1==n&&j==1)) check(f[i+1][j],f[i][j],c[i+1]);
				if(i+1+(e>i)<n) check(f[i+1][j+1],f[i][j],d[i+1]);
			}
		}
		else if(i+1==e){
			for(int j=0;j<=i;j++){
				if(j>(i>=s)||(i+1==n&&j==1)) check(f[i+1][j],f[i][j],a[i+1]);
				if(i+1+(s>i)<n) check(f[i+1][j+1],f[i][j],b[i+1]);
			}
		}
		else{
			for(int j=0;j<=i;j++){
				if(j>=(i>=s&&i>=e?3:2)||(j==2&&i+1==n)) check(f[i+1][j-1],f[i][j],a[i+1]+c[i+1]);
				if(i+3<=n) check(f[i+1][j+1],f[i][j],b[i+1]+d[i+1]);
				if(j>(i>=e)&&i+1+(i<s)<n) check(f[i+1][j],f[i][j],a[i+1]+d[i+1]);
				if(j>(i>=s)&&i+1+(i<e)<n) check(f[i+1][j],f[i][j],b[i+1]+c[i+1]);
			}
		}
	}
	wr(f[n][1]);
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