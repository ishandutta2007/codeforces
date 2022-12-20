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
const int maxn=1e5+5;
int n,a[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++) a[i]=read();
		if(n==3){
			printf("%d\n",a[2]%2==0?a[2]/2:-1);
			continue;
		}
		bool flag=0;
		for(int i=2;i<n;i++) flag|=a[i]>1;
		if(flag){
			ll ans=0;
			for(int i=2;i<n;i++) ans+=(a[i]+1)/2;
			printf("%lld\n",ans);
		}
		else printf("-1\n");
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}