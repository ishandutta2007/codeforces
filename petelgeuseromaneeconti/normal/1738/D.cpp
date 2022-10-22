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
int T,n,a[N],val[N],deg[N];
vector<int>e[N];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n);
		rep(i,1,n)val[i]=0,deg[i]=0,e[i].clear();
		int ret=0;
		rep(i,1,n){
			rd(a[i]);
			if(a[i]>=1&&a[i]<=n)val[a[i]]=1,e[a[i]].push_back(i),++deg[i];
			if(a[i]>i)ret=max(ret,i);
		}
		deque<int>que;
		rep(i,1,n)if(!deg[i]){
			if(val[i])que.push_back(i);else que.push_front(i);
		}
		vector<int>seq;
		while(!que.empty()){
			int u=que.front();
			que.pop_front();
			seq.pb(u);
			each(x,e[u])if(!--deg[x]){
				if(val[x])que.push_back(x);else que.push_front(x);
			}
		}
		printf("%d\n",ret);
		each(x,seq)printf("%d ",x);
		puts("");
	}
	return 0;
}