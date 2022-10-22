#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<class T>void umin(T&x,const T&y){if(y<x)x=y;}
template<class T>void umax(T&x,const T&y){if(x<y)x=y;}
using LL=long long;
const int N=20000005;
int n,a[100005],f[N];
LL g[N];
bool ban[N];
int p[N/10];
void sieve(){
	ban[0]=ban[1]=1;
	for(int i=2;i<N;++i){
		if(!ban[i]){
			p[++*p]=i;
		}
		for(int j=1;j<=*p&&i*p[j]<N;++j){
			ban[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
}
int main(){
	sieve();
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);
		++f[a[i]];
	}
	rep(i,1,*p){
		per(j,(N-1)/p[i],1){
			f[j]+=f[j*p[i]];
		}
	}
	per(j,N-1,0){
		g[j]=1LL*f[j]*j;
		rep(i,1,*p){
			if(j*p[i]<N){
				umax(g[j],g[j*p[i]]+1LL*(f[j]-f[j*p[i]])*j);
			}else break;
		}
	}
	printf("%lld\n",*max_element(g,g+N));
	return 0;
}