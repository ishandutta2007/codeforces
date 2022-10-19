#include<bits/stdc++.h>

using namespace std;

#define LL long long

LL n,m,f[1000000];

LL calc(LL x){
	return x*(x+1)/2;
}

int main(){
	scanf("%lld",&n);
	for (LL i=1;i*i<=n;++i) if (n%i==0){
		f[++m]=calc(n/i-1)*i+n/i;
		if (n/i!=i) f[++m]=calc(i-1)*(n/i)+i;
	}
	sort(f+1,f+m+1);
	for (LL i=1;i<=m;++i) printf(i==m?"%lld\n":"%lld ",f[i]);
	
	return 0;
}