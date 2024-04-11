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
#define ic(x) ((x>='0'&&x<='9')||(x>='A'&&x<='Z')||(x>='a'&&x<='z'))
using namespace std;
typedef long long ll;
bool o;
char chh,ss[1<<17],*A=ss,*B=ss;
inline char gc(){
    return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
}
inline void getstr(char *a,int &n){
	a[n=1]=gc();
	while(!ic(a[1])) a[1]=gc();
	while(ic(a[n])) a[++n]=gc();
	n--;
}
template <typename _Tp> inline void rd(_Tp &x);
template <typename _Tp> inline void wr(_Tp x);
template <typename _Tp> inline _Tp mx(_Tp x,_Tp y);
template <typename _Tp> inline _Tp mn(_Tp x,_Tp y);
int n,m,x,y;
int f[300001],to[600001],ne[600001];
int h[300001],t[300001],v[300001],nt[300001];
int l[1200001],r[1200001],qwq[300001];
ll lazy[1200001],ans[300001];
inline void link(int x,int y,int k){
	to[k]=y;
	ne[k]=f[x];
	f[x]=k;
}
inline void build(int i,int lt,int rt){
	l[i]=lt,r[i]=rt;
	if(lt==rt){
		qwq[lt]=i;
		return;
	}
	int m=(lt+rt)>>1;
	build(i<<1,lt,m);
	build(i<<1|1,m+1,rt);
}
inline void update(int i,int x,int y,int z){
	if(l[i]>y||r[i]<x) return;
	if(l[i]>=x&&r[i]<=y){
		lazy[i]+=z;
		return;
	}
	update(i<<1,x,y,z);
	update(i<<1|1,x,y,z);
}
inline ll query(int x){
	ll ans=lazy[x=qwq[x]];
	while(x>>=1) ans+=lazy[x];
	return ans;
}
inline void dfs(int i,int dep,int fa){
	for(int k=h[i];k;k=nt[k])
	update(1,dep,dep+t[k],v[k]);
	ans[i]=query(dep);
	for(int k=f[i];k;k=ne[k])
	if(to[k]^fa) dfs(to[k],dep+1,i);
	for(int k=h[i];k;k=nt[k])
	update(1,dep,dep+t[k],-v[k]);
}
int main(){
	rd(n);
	for(int i=1;i<n;i++){
		rd(x);
		rd(y);
		link(x,y,(i<<1)-1);
		link(y,x,i<<1);
	}
	rd(m);
	for(int i=1;i<=m;i++){
		rd(x);
		rd(t[i]);
		rd(v[i]);
		nt[i]=h[x];
		h[x]=i;
	}
	build(1,1,n);
	dfs(1,1,0);
	for(int i=1;i<=n;i++)
	wr(ans[i]),_t;
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