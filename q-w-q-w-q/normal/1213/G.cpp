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
template <typename _Tp> inline void wr(_Tp x);
template <typename _Tp> inline _Tp mx(_Tp x,_Tp y);
template <typename _Tp> inline _Tp mn(_Tp x,_Tp y);
int n,m,v[200001];
struct p{
	int x,y,v;
	friend bool operator<(p i,p j){
		return i.v<j.v;
	}
}a[200001];
ll ans[200001],s[200001];
int f[200001],x;
inline int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
int main(){
	rd(n);
	rd(m);
	for(int i=1;i<n;i++){
		rd(a[i].x);
		rd(a[i].y);
		rd(a[i].v);
	}
	for(int i=1;i<=n;i++)
	f[i]=i,s[i]=1;
	sort(a+1,a+n);
	for(int i=1;i<n;i++){
		a[i].x=find(a[i].x);
		a[i].y=find(a[i].y);
		ans[i]=ans[i-1]+s[a[i].x]*s[a[i].y];
		s[a[i].y]+=s[a[i].x];
		f[a[i].x]=a[i].y;
		v[i]=a[i].v;
	}
	while(m--){
		rd(x);
		x=upper_bound(v+1,v+n,x)-v-1;
		wr(ans[x]),_t;
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