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
const int N=1005;
int T,n,m,deg[N],a[N],new_a[N],que[N],he,ta;
bool ban[N];
vector<int>e[N];
void solve(){
	rd(n),rd(m);
	rep(i,1,n)rd(a[i]);
	rep(i,1,n)e[i].clear(),deg[i]=0,ban[i]=0;
	rep(i,1,m){
		int x,y;
		rd(x),rd(y);
		e[x].pb(y);
		++deg[y];
	}
	if(count(a+1,a+n+1,0)==n){puts("0");return;}
	rep(_,1,n){
		copy(a+1,a+n+1,new_a+1);
		rep(u,1,n){
			if(a[u]>0){
				each(x,e[u])new_a[x]+=1;
				new_a[u]-=1;
			}
		}
		copy(new_a+1,new_a+n+1,a+1);
		if(count(a+1,a+n+1,0)==n){
			printf("%d\n",_);
			return;
		}
	}
	he=ta=0;
	rep(i,1,n)if(!deg[i]&&!a[i]){
		que[++ta]=i;
	}
	while(he!=ta){
		int u=que[++he];
		ban[u]=1;
		each(x,e[u])if(!--deg[x]&&!a[x])que[++ta]=x;
	}
	rep(i,1,n)if(!ban[i]&&deg[i]==0){
		que[++ta]=i;
	}
	rep(i,1,n)a[i]%=P;
	while(he!=ta){
		int u=que[++he];
		each(x,e[u]){
			uad(a[x],a[u]);
			if(!ban[x]&&!--deg[x]){
				que[++ta]=x;
			}
		}
	}
	rep(i,1,n)if(SZ(e[i])==0)printf("%d\n",(a[i]+n)%P);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		solve();
	}
	return 0;
}