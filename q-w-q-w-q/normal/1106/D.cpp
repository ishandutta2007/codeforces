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
int n,m,x,y,ans[100001];
int f[100001],to[200001],ne[200001];
bool v[100001];
inline void link(int x,int y,int k){
	to[k]=y;
	ne[k]=f[x];
	f[x]=k;
}
priority_queue<int,vector<int>,greater<int> >q;
int main(){
	rd(n);
	rd(m);
	for(int i=1;i<=m;i++){
		rd(x);
		rd(y);
		link(x,y,(i<<1)-1);
		link(y,x,i<<1);
	}
	q.push(1);
	v[1]=1;
	while(!q.empty()){
		x=q.top();
		q.pop();
		ans[++ans[0]]=x;
		for(int k=f[x];k;k=ne[k]){
			y=to[k];
			if(!v[y])
			v[y]=1,q.push(y);
		}
	}
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