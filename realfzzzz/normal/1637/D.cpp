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
const int maxn=100+5;
int n,a[maxn],b[maxn];
ll f[2][maxn*maxn*2];
inline void cmin(ll& x,ll y){
	x=min(x,y);
}
const ll inf=9e18;
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++) a[i]=read();
		for(int i=1;i<=n;i++) b[i]=read();
		f[0][0]=0;
		int s=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=s+a[i]+b[i];j++) f[i%2][j]=inf;
			for(int j=0;j<=s;j++){
				ll res=f[(i-1)%2][j];
				if(res<inf){
					cmin(f[i%2][j+a[i]],res+a[i]*j+b[i]*(s-j));
					cmin(f[i%2][j+b[i]],res+b[i]*j+a[i]*(s-j));
				}
			}
			s+=a[i]+b[i];
		}
		ll ans=inf;
		for(int i=0;i<=s;i++)
			if(f[n%2][i]<inf) cmin(ans,f[n%2][i]*2);
		for(int i=1;i<=n;i++) ans+=(a[i]*a[i]+b[i]*b[i])*(n-1);
		printf("%lld\n",ans);
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}