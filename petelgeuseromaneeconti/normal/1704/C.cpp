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
const LL INFLL=0X3F3F3F3F3F3F3F3FLL;
const int N=100005;
int T,n,m,a[N];
pair<int,int>gap[N];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n),rd(m);
		rep(i,1,m)rd(a[i]);
		sort(a+1,a+m+1);
		rep(i,1,m-1){
			gap[i]=make_pair(a[i+1]-a[i]-1,2);
		}
		gap[m]=make_pair(n-a[m]+a[1]-1,2);
		sort(gap+1,gap+m+1,[&](auto lhs,auto rhs){
			return lhs.first*rhs.second>rhs.first*lhs.second;
		});
		int t=0;
		LL ans=n;
		rep(i,1,m){
			if(gap[i].second==1){
				ans-=max(0,gap[i].first-t);
				t+=1;
			}else{
				int x=gap[i].first-t*2;
				if(x>=1){
					ans-=1;
					++t;
				}
				x-=2;
				if(x>=1){
					ans-=x;
					++t;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}