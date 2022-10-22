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
template<int P>
class mod_int{
	using Z=mod_int;
private:
	static int mo(int x){return x<0?x+P:x;}
public:
	int x;
	int val()const{return x;}
	mod_int():x(0){}
	template<class T>mod_int(const T&x_):x(x_>=0&&x_<P?static_cast<int>(x_):mo(static_cast<int>(x_%P))){}
	bool operator==(const Z&rhs)const{return x==rhs.x;}
	bool operator!=(const Z&rhs)const{return x!=rhs.x;}
	Z operator-()const{return Z(x?P-x:0);}
	Z pow(long long k)const{
		Z res=1,t=*this;
		while(k){
			if(k&1)res*=t;
			if(k>>=1)t*=t;
		}
		return res;
	}
	Z&operator++(){
		x<P-1?++x:x=0;
		return *this;
	}
	Z&operator--(){
		x?--x:x=P-1;
		return *this;
	}
	Z operator++(int){
		Z ret=x;
		x<P-1?++x:x=0;
		return ret;
	}
	Z operator--(int){
		Z ret=x;
		x?--x:x=P-1;
		return ret;
	}
	Z inv()const{
#ifdef xay5421
		assert(x!=0);
#endif
		return pow(P-2);
	}
	Z&operator+=(const Z&rhs){
		(x+=rhs.x)>=P&&(x-=P);
		return *this;
	}
	Z&operator-=(const Z&rhs){
		(x-=rhs.x)<0&&(x+=P);
		return *this;
	}
	Z&operator*=(const Z&rhs){
		x=1ULL*x*rhs.x%P;
		return *this;
	}
	Z&operator/=(const Z&rhs){
		return *this*=rhs.inv();
	}
#define setO(T,o) friend T operator o(const Z&lhs,const Z&rhs){Z res=lhs;return res o##=rhs;}
	setO(Z,+)setO(Z,-)setO(Z,*)setO(Z,/)
#undef setO
};
const int P=998244353;
using Z=mod_int<P>;
const int N=1000005;
int T,n,K,a[N];
int main(){
	rd(T);
	while(T--){
		rd(n),rd(K);
		rep(i,1,n)rd(a[i]);
		bool gg=0;
		rep(i,n-K+1,n)if(a[i]>0){
			gg=1;
		}
		if(gg){puts("0");continue;}
		Z ans=1;
		rep(i,1,K){
			ans*=i;
		}
		rep(i,K+1,n){
			if(a[i-K]==0){
				ans*=min(K,i-1)+1;
			}else if(a[i-K]==-1){
				ans*=min(K,i-1)+1+i-K-1;
			}
		}
		printf("%d\n",ans.val());
	}
	return 0;
}