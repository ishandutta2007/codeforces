#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL P=500000;
LL n,m,l,r,k;

bool check(LL t){
	LL tot=n+t,rest=m%tot;
	if (!rest) rest=tot;
	LL mn=max(0LL,t-(n-k)),mx=min(k,t);
	if (k+mx>=rest&&k+mn-(mn>0)<=rest) return 1;
	return 0;
}

LL calc(LL num){
	LL l=0,r=n;
	if (num) r=min(r,m/num-n);
	if (m-2*k>0){
		if (!num) return -1;
		l=max(l,(m-2*k+num-1)/num-n);
	}
	if (m-k-n*num>=0){
		l=max(l,(m-k-n*num+num)/(num+1));
	}
	if (m-k>=0){
		if (num) r=min(r,(m-k)/num-n);
	}
	else return -1;
	if (m-n*(num-1)-2*k+1>=0){
		r=min(r,(m-n*(num-1)-2*k+1)/(num+1));
	}
	else return -1;
	if (l>r) return -1;
	return r;
}

int main(){
	scanf("%lld%lld%lld%lld",&n,&l,&r,&m);
	k=r<l?r-l+1+n:r-l+1;
	if (n<=P){
		for (LL i=n;~i;--i){
			if (check(i)){
				printf("%lld\n",i);
				return 0;
			}
		}
		puts("-1");
	}
	else{
		LL ans=-1;
		for (LL i=m/n;~i;--i){
			ans=max(ans,calc(i));
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}