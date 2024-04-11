#include<bits/stdc++.h>
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#define DD(...) D(#__VA_ARGS__ "="),debug_helper::debug(__VA_ARGS__),D("\n")
#include"/home/xay5421/debug.hpp"
#else
#define D(...) ((void)0)
#define DD(...) ((void)0)
#endif
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
using namespace std;
const int N=1000005;
int T,n,a[N],b[N];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n);
		int s=0;
		long long ans=0;
		rep(i,1,n)rd(a[i]),s+=a[i],ans+=1LL*(n-2)*a[i]*a[i];
		rep(i,1,n)rd(b[i]),s+=b[i],ans+=1LL*(n-2)*b[i]*b[i];
		bitset<20005>bag;
		bag.reset();
		bag.set(0);
		rep(i,1,n){
			bag=(bag<<a[i])|(bag<<b[i]);
		}
		int i=(s+1)/2;
		while(!bag[i])--i;
		printf("%lld\n",ans+1LL*i*i+1LL*(s-i)*(s-i));
	}
	return 0;
}