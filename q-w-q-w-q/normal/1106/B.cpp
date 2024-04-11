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
#define pos(x) lower_bound(c+1,c+1+k,x)-c
ll n,a[100001],c[100001],m,x,y;
bool ok,l[100001],ly[100001];
ll ans;
struct p{
	ll x,y,id;
	friend bool operator<(p i,p j){
		return i.y!=j.y?i.y>j.y:i.x>j.x;
	}
}qwq;
priority_queue<p>q;
int main(){
	rd(n),rd(m);
	for(int i=1;i<=n;i++)
	rd(a[i]);
	for(int i=1;i<=n;i++)
	rd(c[i]);
	for(int i=1;i<=n;i++){
		qwq.x=a[i];
		qwq.y=c[i];
		qwq.id=i;
		q.push(qwq);
		l[i]=1;
	}
	ok=1;
	while(m--){
		if(!ok){
			wr(0),_e;
			continue;
		}
		rd(x);
		rd(y);
		ans=0;
		if(y<a[x]){
			ans+=c[x]*y;
			a[x]-=y;
			ly[x]=1;
			y=0;
		}
		else{
			ans+=a[x]*c[x];
			y-=a[x];
			a[x]=l[x]=0;
		}
		while(y&&(!q.empty())){
			qwq=q.top();
			q.pop();
			if(l[qwq.id]==0) continue;
			if(ly[qwq.id]){
				ly[qwq.id]=0;
				qwq.x=a[qwq.id];
				q.push(qwq);
				continue;
			}
			if(y<qwq.x){
				ans+=y*qwq.y;
				a[qwq.id]-=y;
				qwq.x-=y;
				y=0;
				q.push(qwq);
			}
			else{
				l[qwq.id]=0;
				a[qwq.id]=0;
				ans+=qwq.x*qwq.y;
				y-=qwq.x;
			}
		}
		if(y) wr(0),_e,ok=0;
		else wr(ans),_e;
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