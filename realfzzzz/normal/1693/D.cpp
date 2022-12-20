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
int n,a[maxn],f[maxn],g[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	int r=n;
	ll ans=0;
	for(int i=n;i>0;i--){
		f[i]=n+1;
		for(int j=i+1;j<=n;j++){
			int rf=0,rg=n+1;
			if(a[j]>a[j-1]) rf=max(rf,f[j-1]);
			if(a[j]>g[j-1]) rf=max(rf,a[j-1]);
			if(a[j]<a[j-1]) rg=min(rg,g[j-1]);
			if(a[j]<f[j-1]) rg=min(rg,a[j-1]);
			if(rf==f[j]&&rg==g[j]) break;
			f[j]=rf;
			g[j]=rg;
		}
		while(!f[r]&&g[r]>n) r--;
		ans+=r-i+1;
	}
	printf("%lld\n",ans);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}