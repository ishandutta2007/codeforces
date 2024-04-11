#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
mt19937 rnd(time(0));
const int maxn=2e5+5;
int n;
ll a[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	int ans=n;
	auto chk2=[&ans](ll x){
		ll res=0;
		for(int i=1;i<=n;i++)
			if(a[i]<x) res+=x-a[i];
			else res+=min(a[i]%x,x-a[i]%x);
		ans=min(1ll*ans,res);
	};
	auto chk=[chk2](ll x){
		for(ll i=2;i*i<=x;i++) if(x%i==0){
			chk2(i);
			while(x%i==0) x/=i;
		}
		if(x>1) chk2(x);
	};
	for(int T=0;T<30;T++){
		int x=rnd()%n+1;
		chk(a[x]);
		if(a[x]>1) chk(a[x]-1);
		chk(a[x]+1);
	}
	printf("%d\n",ans);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}