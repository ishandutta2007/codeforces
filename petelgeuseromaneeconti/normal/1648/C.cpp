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
const int N=200005;
int n,m,s[N],t[N],num[N];
Z fac[N],ifac[N],ret1,ret2,t1[N<<2],t2[N<<2];
void upd(int k1){
	t1[k1]=t1[k1*2]*t1[k1*2+1];
	t2[k1]=t2[k1*2]*t1[k1*2+1]+t1[k1*2]*t2[k1*2+1];
}
void add(int k1,int k2,int k3,int k4,int k5){
	if(k2==k3){
		num[k2]+=k5;
		// DD(k2,num[k2]);
		// assert(num[k2]>=0);
		if(num[k2]==0){
			t1[k1]=1,t2[k1]=0;
		}else{
			t1[k1]=ifac[num[k2]];
			t2[k1]=ifac[num[k2]-1];
		}
		return;
	}
	int mid=(k2+k3)>>1;
	if(k4<=mid)add(k1*2,k2,mid,k4,k5);
	else add(k1*2+1,mid+1,k3,k4,k5);
	upd(k1);
}
void query(int k1,int k2,int k3,int k4,int k5){
	if(k2>k5||k3<k4)return;
	if(k4<=k2&&k3<=k5){
		ret2=ret2*t1[k1]+ret1*t2[k1];
		ret1=ret1*t1[k1];
		return;
	}
	int mid=(k2+k3)>>1;
	query(k1*2,k2,mid,k4,k5);
	query(k1*2+1,mid+1,k3,k4,k5);
}
void ask(int k1,int k2,int k3,int k4,int k5){
	if(k2>k5||k3<k4)return;
	if(k4<=k2&&k3<=k5){
		ret2*=t1[k1];
		return;
	}
	int mid=(k2+k3)>>1;
	ask(k1*2,k2,mid,k4,k5);
	ask(k1*2+1,mid+1,k3,k4,k5);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	fac[0]=1;
	rep(i,1,N-1)fac[i]=fac[i-1]*i;
	ifac[N-1]=fac[N-1].inv();
	per(i,N-1,1)ifac[i-1]=ifac[i]*i;
	fill(t1+1,t1+N*4,1);
	rd(n),rd(m);
	rep(i,1,n)rd(s[i]);
	rep(i,1,m)rd(t[i]);
	rep(i,1,n)add(1,1,200000,s[i],1);
	Z ans=0;
	rep(i,1,m){	
		if(i>n){
			ans+=1;
			break;
		}
		ret1=1,ret2=0;
		if(t[i]-1>=1)query(1,1,200000,1,t[i]-1);
		ask(1,1,200000,t[i],200000);
		ans+=ret2*fac[n-i];
		if(num[t[i]]==0)break;
		add(1,1,200000,t[i],-1);
	}
	printf("%d\n",ans.val());
	return 0;
}