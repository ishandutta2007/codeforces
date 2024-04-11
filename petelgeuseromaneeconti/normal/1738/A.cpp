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
int T,n,a[N],b[N];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n);
		rep(i,1,n)rd(a[i]);
		vector<int>vec[2];
		rep(i,1,n)rd(b[i]),vec[a[i]].pb(b[i]);
		rep(o,0,1){
			sort(vec[o].begin(),vec[o].end());
		}
		if(vec[0].empty()||vec[1].empty()){
			LL s=0;
			rep(i,1,n)s+=b[i];
			pt(s,'\n');
			continue;
		}
		LL ans=0;
		rep(t,0,1){
			vector<int>V[2];
			rep(o,0,1)V[o]=vec[o];
			LL cur=0;
			int opt=t;
			int last=-1;
			vector<int>T;
			while(!V[0].empty()||!V[1].empty()){
				if(last==-1){
					cur+=V[opt][0];
					V[opt].erase(V[opt].begin());
					last=opt;
				}else{
					if(!V[opt].empty()){
						if(last==(opt^1)){
							cur+=V[opt].back()*2;
						}else{
							cur+=V[opt].back();
						}
						V[opt].pop_back();
						last=opt;
					}
				}
				opt^=1;
			}
			ans=max(ans,cur);
		}
		printf("%lld\n",ans);
	}
	return 0;
}