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
const int N=505,M=250005,INF=0X3F3F3F3F;
int T,n,m,dis[N][N],eu[M],ev[M],ew[M],id[M];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n),rd(m);
		rep(i,1,n)rep(j,1,n)dis[i][j]=INF;
		rep(i,1,n)dis[i][i]=0;
		rep(i,1,m){
			rd(eu[i]),rd(ev[i]),rd(ew[i]);
			id[i]=i;
			dis[eu[i]][ev[i]]=dis[ev[i]][eu[i]]=1;
		}
		rep(k,1,n)rep(i,1,n)if(i!=k)rep(j,1,n)if(j!=i&&j!=k)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		sort(id+1,id+m+1);
		LL ans=0X3F3F3F3F3F3F3F3FLL;
		per(_,m,1){
			int i=id[_];
			int val=min(dis[1][eu[i]]+1+dis[ev[i]][n],dis[1][ev[i]]+1+dis[eu[i]][n]);
			rep(x,1,n){
				val = min(val, dis[1][x] + dis[n][x] + min(dis[eu[i]][x], dis[ev[i]][x]) + 2);
			}
			ans=min(ans,1LL*ew[i]*val);
		}
		printf("%lld\n",ans);
	}
	return 0;
}