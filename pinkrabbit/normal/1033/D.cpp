#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define F2(i,a,b) for(int i=(a);i<(b);++i)
#define dF2(i,a,b) for(int i=(a);i>(b);--i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
using namespace std;
#define LL long long
#define ld double
#define mod 998244353

int n,m,q,k;
LL a[505]; int b[505], e[505], d;
LL c[505], f[505], g[505];

LL sq(LL x){
	LL y=sqrt(x);
	while(y*y<x) ++y;
	while(y*y>x) --y;
	return y;
}
LL sq3(LL x){
	LL y=pow(x,1/3.);
	while(y*y*y<x) ++y;
	while(y*y*y>x) --y;
	return y;
}

map<LL,int> mp;

int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%lld",a+i);
	sort(a+1,a+n+1);
	F(i,1,n) if(!d||a[i]!=a[d]) a[++d]=a[i], e[d]=1; else ++e[d];
	n=d;
	F(i,1,n){
		LL y=sq(a[i]);
		if(y*y!=a[i]){
			LL z=sq3(a[i]);
			if(z*z*z!=a[i]) b[i]=1; // pq
			else b[i]=3, c[i]=z; // p^3
		}
		else{
			LL z=sq(y);
			if(z*z==y) b[i]=2, c[i]=z; // p^4
			else b[i]=0, c[i]=y; // p^2
		}
	}
	F(i,1,n) if(b[i]==1){
		F(j,1,n) if(j!=i){
			LL y=__gcd(a[i],a[j]);
			if(y>1){
				f[i]=y;
				g[i]=a[i]/y;
				break;
			}
		}
	}
	int Ans=1;
	F(i,1,n){
		if(b[i]==0) mp[c[i]]+=2*e[i];
		if(b[i]==2) mp[c[i]]+=4*e[i];
		if(b[i]==3) mp[c[i]]+=3*e[i];
		if(b[i]==1){
			if(f[i]) mp[f[i]]+=e[i], mp[g[i]]+=e[i];
			else Ans=(LL)Ans*(e[i]+1)*(e[i]+1)%mod;
		}
	}
	for(map<LL,int>::iterator it=mp.begin();it!=mp.end();++it)
		Ans=(LL)Ans*(it->second+1)%mod;
	printf("%d\n",Ans);
	return 0;
}