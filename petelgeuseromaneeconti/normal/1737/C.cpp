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
int T,n;
int tx,ty;
struct vec{
	int x,y;
	bool operator<(const vec&rhs){
		return tie(x,y)<tie(rhs.x,rhs.y);
	}
}a[N];
bool solve(){
	bool found=0;
	rep(i,1,3)if(a[i].x%2==tx%2&&a[i].y%2==ty%2){
		found=1;
	}
	if(!found)return 0;
	rep(i,1,3)if(a[i].x==tx&&a[i].y==ty){
		return 1;
	}
	while(1){
		sort(a+1,a+3+1);
		if(a[2].x==a[1].x&&a[2].y==a[1].y+1&&a[3].x==a[1].x+1&&a[3].y==a[1].y)break;
		rep(i,1,n){
			int t=a[i].y;
			a[i].y=a[i].x;
			a[i].x=n+1-t;
		}
		int t=ty;
		ty=tx;
		tx=n+1-t;
	}
	if(a[1].x==1&&a[1].y==1)return tx==1||ty==1;
	return 1;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n);
		rep(i,1,3){
			rd(a[i].x),rd(a[i].y);
		}
		rd(tx),rd(ty);
		puts(solve()?"YES":"NO");
	}
	return 0;
}