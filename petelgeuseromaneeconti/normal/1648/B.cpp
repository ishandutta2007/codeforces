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
int T,n,c,a[N],bin[N],sum[N];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n),rd(c);
		fill(bin+1,bin+c+1,0);
		rep(i,1,n)rd(a[i]),++bin[a[i]];
		rep(i,1,c)sum[i]=sum[i-1]+bin[i];
		bool gg=0;
		rep(i,1,c)if(!bin[i]){
			rep(j,1,c/i)if(bin[j]){
				// if(have(i*j,i*j+j-1)){
				if(sum[min(c,i*j+j-1)]-sum[i*j-1]){
					gg=1;
					i=c+1;
					break;
				}
			}
		}
		puts(gg?"No":"Yes");
	}
	return 0;
}