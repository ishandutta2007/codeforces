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
const int N=5005;
int T,n,a[N],sum[N][N];
int main(){
	rd(T);
	while(T--){
		rd(n);
		rep(i,0,n+1)rep(j,0,n+1)sum[i][j]=0;
		rep(i,1,n)rd(a[i]),sum[i][a[i]]+=1;
		rep(i,1,n)rep(j,1,n)sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
		LL ans=0;
		rep(i,1,n)rep(j,i+1,n){
			ans+=1LL*sum[i-1][a[j]]*(sum[n][a[i]]-sum[j][a[i]]);
		}
		pt(ans,'\n');
	}
	return 0;
}