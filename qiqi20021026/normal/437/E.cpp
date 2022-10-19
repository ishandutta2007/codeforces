#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 300

const LL mod=1000000007;
LL n,f[N][N],sum;
bool vis[N][N];
struct node{
	LL x,y;
	node(LL x=0,LL y=0):x(x),y(y){}
	node operator - (const node &p) const{
		return node(x-p.x,y-p.y);
	}
}a[N];

LL cross(node u,node v){
	return u.x*v.y-u.y*v.x;
}

LL dp(LL l,LL r){
	if (r-l==1) return 1;
	if (vis[l][r]) return f[l][r];
	vis[l][r]=1;
	for (LL k=l+1;k<r;++k){
		if (cross(a[r]-a[k],a[l]-a[k])*sum>0){
			f[l][r]=(f[l][r]+dp(l,k)*dp(k,r))%mod;
		}
	}
	return f[l][r];
}

int main(){
	scanf("%lld",&n);
	for (LL i=1;i<=n;++i){
		scanf("%lld%lld",&a[i].x,&a[i].y);
	}
	for (LL i=1;i<n;++i){
		sum+=cross(a[i]-a[n],a[i+1]-a[n]);
	}
	sum=sum>0?1:-1;
	printf("%lld\n",dp(1,n));
	
	return 0;
}