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
const int N=105;
int T,n,a[N];
int solve(int cnt0,int cnt1,int who,int sum){
	if(cnt0==0&&cnt1==0){
		return sum&1?1:0;
	}
	if(who==0){ // Alice
		if(cnt0>0){
			if(!solve(cnt0-1,cnt1,who^1,sum)){
				return 0;
			}
		}
		if(cnt1>0){
			if(!solve(cnt0,cnt1-1,who^1,sum^1)){
				return 0;
			}
		}
		return 1;
	}else{
		if(cnt0>0){
			if(solve(cnt0-1,cnt1,who^1,sum)){
				return 1;
			}
		}
		if(cnt1>0){
			if(solve(cnt0,cnt1-1,who^1,sum)){
				return 1;
			}
		}
		return 0;
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n);
		int cnt[2]={0,0};
		rep(i,1,n)rd(a[i]),++cnt[a[i]&1];
		puts(solve(cnt[0]%4,cnt[1]%4,0,0)?"Bob":"Alice");
	}
	return 0;
}