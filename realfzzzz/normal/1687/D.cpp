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
const int m=2e6+5;
int n,pre[m],suc[m];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	int a1=read();
	for(int i=1;i<=n;i++){
		int a=i==1?a1:read();
		pre[a]=suc[a]=a;
	}
	suc[m-1]=m;
	for(int i=2;i<m;i++) if(!pre[i]) pre[i]=pre[i-1];
	for(int i=m-2;i>0;i--) if(!suc[i]) suc[i]=suc[i+1];
	for(int i=1;i<m;i++){
		ll l=0,r=9e18;
		int l2=a1;
		while(l2<m){
			int x,r2;
			x=sqrt(1ll*i*i+i+l2-a1);
			r2=pre[min(1ll*(x+1)*(x+1)-1ll*i*i-i+a1-1,m-1ll)];
			l=max(l,1ll*x*x-l2);
			r=min(r,1ll*x*x+x-r2);
			l2=suc[r2+1];
		}
		if(l<=r){
			printf("%lld\n",l);
			break;
		}
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}