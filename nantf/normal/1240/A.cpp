#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=200020,mod=998244353;
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	ll x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int T,n,p[maxn],x,y,a,b;
ll k;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
bool check(int mid){
	int ab=mid/lcm(a,b),aa=mid/a-ab,bb=mid/b-ab;
//	printf("ab=%d,a=%d,b=%d,check(%d)\n",ab,aa,bb,mid);
	ll tot=0;
	FOR(i,1,ab) tot+=p[i]/100*(x+y);
	FOR(i,ab+1,ab+aa) tot+=p[i]/100*x;
	FOR(i,ab+aa+1,ab+aa+bb) tot+=p[i]/100*y;
//	printf("tot=%d\n",tot);
	return tot>=k;
}
int main(){
	T=read();
	while(T--){
		n=read();
		FOR(i,1,n) p[i]=read();
		x=read();a=read();y=read();b=read();k=read();
		if(x<y) swap(x,y),swap(a,b);
		sort(p+1,p+n+1,greater<int>());
		int l=1,r=n+1;
		while(l<r){
			int mid=(l+r)>>1;
			if(check(mid)) r=mid;
			else l=mid+1;
		}
		if(!check(l)) puts("-1");
		else printf("%d\n",l);
	}
}