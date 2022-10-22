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
const int P=998244353;
int ad(int k1,int k2){return k1+k2>=P?k1+k2-P:k1+k2;}
int su(int k1,int k2){return k1-k2<0?k1-k2+P:k1-k2;}
int mu(int k1,int k2){return 1ULL*k1*k2%P;}
void uad(int&k1,int k2){(k1+=k2)>=P&&(k1-=P);}
void usu(int&k1,int k2){(k1-=k2)<0&&(k1+=P);}
template<class... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<class... T>int su(int k1,T... k2){return su(k1,ad(k2...));}
template<class... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
template<class... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<class... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
const int N=100005;
int T,n,a[N],fac[N],ifac[N];
LL pre[N],suf[N];
int C(int n,int m){
	if(m<0||n<m)return 0;
	return mu(fac[n],ifac[m],ifac[n-m]);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	fac[0]=1;
	rep(i,1,N-1)fac[i]=mu(fac[i-1],i);
	ifac[N-1]=po(fac[N-1],P-2);
	per(i,N-1,1)ifac[i-1]=mu(ifac[i],i);
	rd(T);
	while(T--){
		rd(n);
		LL s=0;
		rep(i,1,n)rd(a[i]),pre[i]=pre[i-1]+a[i],s+=a[i];
		suf[n+1]=0;
		per(i,n,1)suf[i]=suf[i+1]+a[i];
		if(s==0){
			printf("%d\n",po(2,n-1));
			continue;
		}
		map<LL,int>mp1,mp2;
		rep(i,1,n)mp1[pre[i]]+=1;
		rep(i,1,n)mp2[suf[i]]+=1;
		int ans=1;
		for(auto&x:mp1){
			if(x.first*2<s){
				ans=mu(ans,C(x.second+mp2[x.first],x.second));
			}
		}
		if(s%2==0){
			int tt=mp1[s/2];
			ans=mu(ans,po(2,tt));
		}
		printf("%d\n",ans);
	}
	return 0;
}