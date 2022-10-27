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
int n,m,lt,x,qwq,t;
int f[200001],to[400001],ne[400001];
int dfn[200001],low[200001];
int st[200001],top,cnt;
int s,l[200001],r[200001],k[200001],nw,bg[200001];
bool v[200001],in[200001],nn[200001];
int ans[200001];
int f2[200001],n2[200001],t2[200001],ii[200001];
bool lk[200001];
int head,tail,qu[200001];
inline void link(int x,int y,int k){
	to[k]=y;
	ne[k]=f[x];
	f[x]=k;
}
inline void lk2(int x,int y,int k){
	t2[k]=y;
	n2[k]=f2[x];
	f2[x]=k;
}
inline void tarjan(int i){
	dfn[i]=low[i]=++cnt;
	v[i]=in[i]=1;
	st[++top]=i;
	for(int kk=f[i];kk;kk=ne[kk]){
		if(!v[to[kk]]){
			tarjan(to[kk]);
			low[i]=mn(low[i],low[to[kk]]);
		}
		else if(in[to[kk]]) low[i]=mn(low[i],dfn[to[kk]]);
	}
	if(low[i]==dfn[i]){
		s++;
		l[s]=nw+1;
		while(1){
			x=st[top--];
			bg[x]=s;
			k[++nw]=x;
			in[x]=0;
			if(x==i) break;
		}
		r[s]=nw;
	}
}
int main(){
	rd(n);
	rd(m);
	rd(lt);
	for(int i=2;i<=n;i++){
		rd(x);
		link(lt,x,i);
		lt=x;
	}
	rd(lt);
	for(int i=2;i<=n;i++){
		rd(x);
		link(lt,x,n+i);
		lt=x;
	}
	for(int i=1;i<=n;i++)
	if(!dfn[i]) tarjan(i);
	if(s<m){
		puts("NO");
		return 0;
	}
	for(int i=1;i<=s;i++){
		for(int j=l[i];j<=r[i];j++){
			for(int q=f[k[j]];q;q=ne[q]){
				if(lk[bg[to[q]]]||bg[to[q]]==i) continue;
				lk[bg[to[q]]]=1;
				lk2(i,bg[to[q]],++t);
				ii[bg[to[q]]]++;
			}
		}
		for(int j=l[i];j<=r[i];j++)
		for(int q=f[k[j]];q;q=ne[q])
		lk[bg[to[q]]]=0;
	}
	for(int i=1;i<=s;i++)
	if(!ii[i]) qu[++tail]=i;
	while(head^tail){
		x=qu[++head];
		for(int i=l[x];i<=r[x];i++)
		ans[k[i]]=qwq;
		qwq++;
		if(qwq==26) qwq--;
		for(int q=f2[x];q;q=n2[q]){
			ii[t2[q]]--;
			if(!ii[t2[q]])
			qu[++tail]=t2[q];
		}
	}
	puts("YES");
	for(int i=1;i<=n;i++)
	putchar('a'+ans[i]);
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