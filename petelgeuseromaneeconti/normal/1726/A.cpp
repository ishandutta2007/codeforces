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
using LL=long long;
using ULL=unsigned long long;
const int N=1000005;
int T,n,a[N];
int main(){
	rd(T);
	while(T--){
		rd(n);
		rep(i,1,n)rd(a[i]);
		int ans=0;
		rep(i,1,n){
			ans=max(ans,a[i]-a[i%n+1]);
		}
		int mx=0;
		rep(i,2,n){
			mx=max(mx,a[i]);
		}
		ans=max(ans,mx-a[1]);
		int mn=1e9;
		rep(i,1,n-1){
			mn=min(mn,a[i]);
		}
		ans=max(ans,a[n]-mn);
		printf("%d\n",ans);
	}
	return 0;
}