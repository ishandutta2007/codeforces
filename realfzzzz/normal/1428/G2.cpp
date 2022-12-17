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
const int maxn=1e6+5;
int n;
const ll inf=9e18;
ll a[6],f[maxn];
void upd(ll x,ll w){
	for(int i=maxn-1;i>=x;i--)
		if(f[i-x]>-inf) f[i]=max(f[i],f[i-x]+w);
}
void upd(ll x,ll c,ll w){
	for(int i=0;(1<<i)<c;i++){
		upd(x<<i,w<<i);
		c-=1<<i;
	}
	upd(x*c,w*c);
}
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	for(int i=0;i<=5;i++) a[i]=read();
	for(int i=1;i<maxn;i++) f[i]=-inf;
	int pw=1;
	for(int i=0;i<=5;i++){
		upd(3*pw,(n-1)*3,a[i]);
		for(int j=maxn-1;j>=0;j--)
			for(int k=1;k<10&&k*pw<=j;k++)
				f[j]=max(f[j],f[j-k*pw]+(k%3==0?a[i]*k/3:0));
		pw*=10;
	}
	int q=read();
	while(q--) printf("%lld\n",f[read()]);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}