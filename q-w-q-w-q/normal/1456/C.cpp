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
int n,k,a[500001],pos;
ll ans,sum,s[500005];
struct p{
	ll val;
	int id;
	friend bool operator<(p i,p j){
		return i.val>j.val;
	}
};
priority_queue<p>q;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) rd(a[i]);
	sort(a+1,a+1+n,greater<int>());
	for(pos=1;pos<=n&&a[pos]>=0;pos++){
		ans+=sum;
		sum+=a[pos];
	}
	k++,s[1]=sum;
	for(int i=1;i<=k;i++) q.push(p{-s[i],i});
	while(pos<=n){
		int x=q.top().id;
		q.pop();
		ans+=s[x];
		s[x]+=a[pos];
		q.push(p{-s[x],x});
		pos++;
	}
	cout<<ans;
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