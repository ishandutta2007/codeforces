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
#include<random>
#define _t putchar(32)
#define _e putchar(10)
#define inf 2147483647
#define ine -2147483647
#define lb(x) ((x)&(-x))
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
int n,m,up,x,y;
int opt[300001],type[300001],a[300001],b[300001],c[300001];
int ans[300001];
int s[600001];
int cnt;
struct p{
	int opt,x,y,v,id;
}q[600001];
inline void nw(int id,int type,int x,int y,int v=0){
	cnt++;
	q[cnt].id=id;
	q[cnt].opt=type;
	q[cnt].x=x;
	q[cnt].y=y;
	q[cnt].v=v;
}
inline void add(int x,int v){
	while(x<=up){
		s[x]+=v;
		x+=lb(x);
	}
}
inline int query(int x){
	int tp=0;
	while(x){
		tp+=s[x];
		x-=lb(x);
	}
	return tp;
}
inline bool cmp(p i,p j){
	return i.x!=j.x?i.x<j.x:i.opt==1;
}
inline void solve1(int l,int r){
	if(l==r) return;
	int m=(l+r)>>1;
	solve1(l,m),solve1(m+1,r);
	cnt=0;
	for(int i=l;i<=m;i++){
		if(type[i]==1){
			nw(i,1,a[i],b[i],1);
			nw(i,1,a[i]+c[i]+1,b[i],-1);
		}
	}
	for(int i=m+1;i<=r;i++){
		if(opt[i]==2) nw(i,2,a[i],b[i]);
	}
	stable_sort(q+1,q+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		if(q[i].opt==1){
			add(q[i].y,q[i].v);
			q[i].y=a[q[i].id]+b[q[i].id]+c[q[i].id]+1;
		}
		else ans[q[i].id]+=query(q[i].y);
	}
	for(int i=1;i<=cnt;i++){
		if(q[i].opt==1) add(q[i].y,q[i].v);
		else ans[q[i].id]-=query(q[i].x+q[i].y);
	}
}
inline void solve2(int l,int r){
	if(l==r) return;
	int m=(l+r)>>1;
	solve2(l,m),solve2(m+1,r);
	cnt=0;
	for(int i=l;i<=m;i++){
		if(type[i]==4){
			nw(i,1,a[i]-c[i],a[i]+b[i]-c[i],1);
			nw(i,1,a[i]+1,a[i]+b[i]-c[i],-1);
		}
	}
	for(int i=m+1;i<=r;i++){
		if(opt[i]==2) nw(i,2,a[i],b[i]);
	}
	stable_sort(q+1,q+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		if(q[i].opt==1){
			add(q[i].y,q[i].v);
			q[i].y=b[q[i].id]+1;
		}
		else ans[q[i].id]+=query(q[i].x+q[i].y);
	}
	for(int i=1;i<=cnt;i++){
		if(q[i].opt==1) add(q[i].y,q[i].v);
		else ans[q[i].id]-=query(q[i].y);
	}
}
int main(){
	rd(n),rd(m),up=n<<1;
	for(int i=1;i<=m;i++){
		rd(opt[i]);
		if(opt[i]==1) rd(type[i]),rd(a[i]),rd(b[i]),rd(c[i]);
		else rd(a[i]),rd(b[i]);
	}
	solve1(1,m),solve2(1,m);
	for(int i=1;i<=m;i++){
		x=a[i],y=b[i];
		a[i]=y,b[i]=n-x+1;
		if(opt[i]==1){
			if(type[i]==1||type[i]==4) type[i]=-1;
			else type[i]=type[i]==2?4:1;
		}
	}
	solve1(1,m),solve2(1,m);
	for(int i=1;i<=m;i++) if(opt[i]==2) wr(ans[i]),_e;
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