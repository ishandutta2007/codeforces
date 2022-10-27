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
int tt,n,m,b,e,x,y;
int f[200001],to[1000001],ne[1000001];
bool v[200001],cut[200001];
int dfn[200001],low[200001],cnt,size[200001];
int gu[200001],gg[200001];
int q[200001],h,t;
inline void link(int x,int y,int k){
	to[k]=y;
	ne[k]=f[x];
	f[x]=k;
}
inline void tarjan(int i){
	int tp=0;
	bool qwq=1;
	v[i]=1;
	size[i]=1;
	low[i]=dfn[i]=++cnt;
	for(int k=f[i];k;k=ne[k]){
		if(v[to[k]]) low[i]=mn(low[i],dfn[to[k]]);
		else{
			tp++;
			tarjan(to[k]);
			size[i]+=size[to[k]];
			if(low[to[k]]>=dfn[i]){
				cut[i]=1;
				gu[i]+=size[to[k]];
			}
			else low[i]=mn(low[i],low[to[k]]),qwq=0;
		}
	}
	if(qwq) gg[i]=1;
}
inline bool dfs(int i){
	if(i==e) return 1;
	for(int k=f[i];k;k=ne[k]){
		if(dfn[to[k]]<dfn[i]) continue;
		if(dfs(to[k])) return 1;
	}
	return 0;
}
int main(){
	rd(tt);
	while(tt--){
		rd(n),rd(m),rd(b),rd(e);
		for(int i=1;i<=n;i++)
		gg[i]=gu[i]=cut[i]=v[i]=f[i]=0;
		cnt=0;
		for(int i=1;i<=m;i++){
			rd(x),rd(y);
			link(x,y,(i<<1)-1);
			link(y,x,i<<1);
		}
		tarjan(b);
		for(int i=1;i<=n;i++)
		if(!v[i]) tarjan(i);
		if(cut[b]==0||cut[e]==0){
			wr(0),_e;
			continue;
		}
		int qwq=0;
		for(int k=f[b];k;k=ne[k]){
			if(dfn[to[k]]<dfn[b]) continue;
			if(dfs(to[k])){
				qwq=1;
				int s=gu[b];
				if(low[to[k]]>=dfn[b]) s-=size[to[k]];
				if(gg[b]) s+=n-size[b];
				wr(1ll*s*gu[e]),_e;
				break;
			}
		}
		if(!qwq) wr(1ll*gu[b]*gu[e]),_e;
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