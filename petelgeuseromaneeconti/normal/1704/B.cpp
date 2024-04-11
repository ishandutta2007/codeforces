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
int T,n,x,a[N];
int main(){
	rd(T);
	while(T--){
		rd(n),rd(x);
		rep(i,1,n)rd(a[i]);
		int ans=0;
		for(int i=1,j;i<=n;i=j){
			++ans;
			j=i+1;
			int mn=a[i],mx=a[i];
			while(j<=n){
				int new_mn=min(mn,a[j]);
				int new_mx=max(mx,a[j]);
				if(new_mx-new_mn<=2*x){
					mn=new_mn;
					mx=new_mx;
					++j;
				}else break;
			}
		}
		pt(ans-1,'\n');
	}
	return 0;
}