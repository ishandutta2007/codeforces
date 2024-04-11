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
char ch,ss[1<<17],*A=ss,*B=ss;
inline char gc(){
	return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
}
template <typename _Tp> inline void rd(_Tp &x);
template <typename _Tp> inline void wr(_Tp x);
template <typename _Tp> inline _Tp mx(_Tp x,_Tp y);
template <typename _Tp> inline _Tp mn(_Tp x,_Tp y);
int n,tp,s[65];
ll a[100001],x;
bool qwq[100001][65];
int f[100001],to[200001],ne[200001];
int cnt,lt[65],ans=-1;
bool v[100001];
int q1[100001],s1,q2[100001],s2,d[100001];
int fa[100001];
bool qqq[100001];
inline void link(int x,int y,int k){
	to[k]=y;
	ne[k]=f[x];
	f[x]=k;
}
inline void bfs(int begin){
	memset(v,0,sizeof(v));
	memset(fa,0,sizeof(fa));
	memset(d,0,sizeof(d));
	q1[s1=1]=begin;
	v[begin]=1;
	d[begin]=0;
	bool ok=1;
	while(s1){
		s2=0;
		for(int i=1;i<=s1;i++){
			x=q1[i];
			memset(qqq,0,sizeof(qqq));
			for(int k=f[x];k;k=ne[k]){
				if(to[k]==fa[x]) continue;
				if(qqq[to[k]]) continue;
				if(v[to[k]]){
					tp=d[x]+d[to[k]]+1;
					if(ans==-1||ans>tp) ans=tp;
					ok=0;
				}
				v[to[k]]=1;
				d[to[k]]=d[x]+1;
				q2[++s2]=to[k];
				fa[to[k]]=x;
				qqq[to[k]]=1;
			}
		}
		if(!ok) return;
		s1=s2;
		for(int i=1;i<=s2;i++)
		q1[i]=q2[i];
	}
}
int main(){
	rd(n);
	for(int i=1;i<=n;i++){
		rd(a[i]);
		x=a[i];
		tp=1;
		while(x){
			if(x&1){
				qwq[i][tp]=1;
				s[tp]++;
				if(s[tp]>=3){
					wr(3);
					return 0;
				}
			}
			x>>=1,tp++;
		}
	}
	for(int i=1;i<=n;i++){
		x=a[i];
		for(int j=1;j<=64;j++){
			if(qwq[i][j]){
				if(lt[j]){
					link(i,lt[j],++cnt);
					link(lt[j],i,++cnt);
				}
				else lt[j]=i;
			}
		}
	}
	for(int i=1;i<=n;i++)
	if(f[i]) bfs(i);
	wr(ans);
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