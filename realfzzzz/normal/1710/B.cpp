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
int n,m,x[maxn],p[maxn],n2,x2[maxn];
const ll inf=9e18;
ll a[maxn],k[maxn],b[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		m=read();
		for(int i=1;i<=n;i++){
			x2[i]=x[i]=read();
			p[i]=read();
		}
		sort(x2+1,x2+n+1);
		n2=unique(x2+1,x2+n+1)-x2-1;
		for(int i=1;i<=n2;i++) k[i]=b[i]=0;
		for(int i=1;i<=n;i++){
			int xx=lower_bound(x2+1,x2+n2+1,x[i]-p[i])-x2;
			k[xx]++;
			b[xx]+=p[i]-x[i];
			xx=lower_bound(x2+1,x2+n2+1,x[i])-x2;
			k[xx+1]-=2;
			b[xx+1]+=x[i]*2;
			xx=upper_bound(x2+1,x2+n2+1,x[i]+p[i])-x2-1;
			k[xx+1]++;
			b[xx+1]-=p[i]+x[i];
		}
		for(int i=1;i<=n2;i++){
			k[i]+=k[i-1];
			b[i]+=b[i-1];
			a[i]=k[i]*x2[i]+b[i];
		}
		ll d=-9e18,s=-9e18;
		for(int i=1;i<=n2;i++) if(a[i]>m){
			d=max(d,a[i]-m-x2[i]);
			s=max(s,a[i]-m+x2[i]);
		}
		for(int i=1;i<=n;i++)
			printf("%d",p[i]-x[i]>=d&&p[i]+x[i]>=s);
		printf("\n");
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}