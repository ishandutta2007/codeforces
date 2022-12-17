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
const int maxn=2e5+5;
int n;
ll a[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++) a[i]=read();
		sort(a+1,a+n+1);
		ll s=0;
		for(int i=1;i<=n;i++) s+=a[i];
		if(s+a[1]*(n-2)>0||s+a[n]*(n-2)<0){
			printf("INF\n");
			continue;
		}
		ll ans=-9e18,s2=0;
		for(int i=2;i<=n;i++) s2+=a[1]*a[i];
		for(int i=1;i<n;i++){
			ans=max(ans,s2-a[i]*(s+a[1]*(n-i-1)+a[n]*(i-1)));
			s2+=a[i+1]*(a[n]-a[1]);
		}
		printf("%lld\n",ans);
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}