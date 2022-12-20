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
const int maxn=2.5e3+5;
int n,x[maxn],y[maxn],x2[maxn],y2[maxn];
ll cross(int a,int b){
	return 1ll*x2[a]*y2[b]-1ll*x2[b]*y2[a];
}
int ord[maxn];
ll C(int n,int m){
	ll s=1;
	for(int i=1;i<=m;i++) s*=n-i+1;
	for(int i=1;i<=m;i++) s/=i;
	return s;
}
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	for(int i=1;i<=n;i++){
		x[i]=read();
		y[i]=read();
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<n;j++){
			x2[j]=x[j+(j>=i)]-x[i];
			y2[j]=y[j+(j>=i)]-y[i];
			ord[j]=j;
		}
		sort(ord+1,ord+n,[](int a,int b){
			bool d1,d2;
			d1=y2[a]?y2[a]>0:x2[a]>0;
			d2=y2[b]?y2[b]>0:x2[b]>0;
			if(d1^d2) return d1;
			return cross(a,b)>0;
		});
		int c=2;
		for(int j=1;j<n;j++){
			int u=ord[j];
			while(c!=j&&cross(u,ord[c])>=0) c=c%(n-1)+1;
			ans+=C((j-c+n-1)%(n-1),3);
		}
	}
	printf("%lld\n",C(n-1,4)*n-ans);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}