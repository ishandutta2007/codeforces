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
int m,n,a[200001],b[200001],cnt;
int f[200001],x,y,lt[200001];
ll ans;
struct p{
	int opt,id,val;
	friend bool operator<(p i,p j){
		return i.val>j.val;
	}
}q[200001];
inline int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
int main(){
	rd(m),rd(n);
	for(int i=1;i<=m;i++) rd(a[i]);
	for(int i=1;i<=n;i++) rd(b[i]);
	for(int i=1;i<=m;i++){
		rd(y);
		while(y--){
			rd(x);
			cnt++;
			ans+=a[i]+b[x];
			q[cnt].opt=x,q[cnt].id=i,q[cnt].val=a[i]+b[x];
		}
	}
	for(int i=1;i<=m;i++) f[i]=i;
	sort(q+1,q+1+cnt);
	for(int i=1;i<=cnt;i++){
		if(!lt[q[i].opt]||(x=find(q[i].id))!=(y=find(lt[q[i].opt]))){
			ans-=q[i].val;
			f[x]=y;
		}
		lt[q[i].opt]=q[i].id;
	}
	wr(ans);
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