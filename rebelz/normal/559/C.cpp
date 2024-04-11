#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

typedef long long ll;
const ll cys=1000000007;

struct node{
	ll x,y;
	bool operator<(const node c)const{
		if(x==c.x)
			return y<c.y;
		return x<c.x;
	}
}p[2005];

ll n,m,k;
ll fac[200005],inv[200005],d[2005];

ll power(ll x,ll p){
	ll ans=1;
	for(;p;p>>=1,x=x*x%cys)
		if(p&1)
			ans=ans*x%cys;
	return ans;
}

ll C(ll x,ll y){return fac[x]*inv[y]%cys*inv[x-y]%cys;}

int main(){
	scanf("%lld%lld%lld",&n,&m,&k);
	fac[0]=1,inv[0]=1;
	for(int i=1;i<=n+m;i++)
		fac[i]=fac[i-1]*i%cys,inv[i]=power(fac[i],cys-2);
	for(int i=1;i<=k;i++)
		scanf("%lld%lld",&p[i].x,&p[i].y);
	p[++k].x=n,p[k].y=m;
	sort(p+1,p+k+1);
	for(int i=1;i<=k;i++){
		d[i]=C(p[i].x+p[i].y-2,p[i].x-1);
		for(int j=1;j<=i-1;j++)
			if(p[j].x<=p[i].x&&p[j].y<=p[i].y)
				d[i]=(d[i]-d[j]*C(p[i].x-p[j].x+p[i].y-p[j].y,p[i].x-p[j].x)%cys)%cys;
	}
	printf("%lld\n",(d[k]+cys)%cys);
	return 0;
}