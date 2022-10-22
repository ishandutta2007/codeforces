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
const int N=200005;
int T,n,K,s[N];
vector<int>e[N];
map<int,LL>dp[N];
LL f[N][2];
LL dfs1(int k1,int k2,int K){
	if(e[k1].empty()){
		return 1LL*s[k1]*K;
	}
	if(dp[k1].count(K))return dp[k1][K];
	int w=SZ(e[k1]);
	int low=K/w;
	int upp=(K+w-1)/w;
	LL&res=dp[k1][K];
	res=1LL*s[k1]*K;
	if(low==upp){
		each(x,e[k1]){
			res+=dfs1(x,k1,low);
		}
		return res;
	}else{
		vector<LL>dt;
		each(x,e[k1]){
			f[x][0]=dfs1(x,k1,low);
			f[x][1]=dfs1(x,k1,upp);
			dt.pb(f[x][1]-f[x][0]);
			res+=f[x][0];
		}
		sort(dt.begin(),dt.end());
		reverse(dt.begin(),dt.end());
		rep(i,1,K-low*w){
			res+=dt[i-1];
		}
		return res;
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n),rd(K);
		rep(i,1,n)e[i].clear(),dp[i].clear();
		rep(i,2,n){
			int f;
			rd(f);
			e[f].pb(i);
		}
		rep(i,1,n)rd(s[i]);
		printf("%lld\n",dfs1(1,0,K));
	}
	return 0;
}