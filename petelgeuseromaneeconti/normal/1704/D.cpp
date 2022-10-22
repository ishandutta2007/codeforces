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
int T,n,m;
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n),rd(m);
		map<__int128,vector<int> >mp;
		rep(i,1,n){
			__int128 sum=0;
			rep(j,1,m){
				LL x;
				rd(x);
				sum+=x*j;
			}
			mp[sum].pb(i);
		}
		__int128 other;
		assert(SZ(mp)==2);
		each(x,mp){
			if(SZ(x.second)==1){
			}else{
				other=x.first;
			}
		}
		each(x,mp){
			if(SZ(x.second)==1){
				pt(x.second[0],' ');
				pt(x.first-other,'\n');
			}else{
			}
		}
	}
	return 0;
}