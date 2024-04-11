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
const int N=100005;
int T,n,a[N],b[N],go[N];
bool vis[N];
int main(){
	rd(T);
	while(T--){
		rd(n);
		rep(i,1,n)rd(a[i]);
		rep(i,1,n)rd(b[i]),go[a[i]]=b[i];
		fill(vis+1,vis+n+1,0);
		int cur=1;
		LL ans=0;
		rep(i,1,n)if(!vis[i]){
			int x=i,sz=0;
			while(!vis[x]){
				vis[x]=1;
				++sz;
				x=go[x];
			}
			sz>>=1;
			rep(_,1,sz){
				ans+=(n-cur+1)*2-cur*2;
				++cur;
			}
		}
		pt(ans,'\n');
	}
	return 0;
}