#include<bits/stdc++.h>

using namespace std;

#define N 300000
#define LL long long

LL n,mx,a[N],f[N];

int main(){
	scanf("%lld",&n);
	for (LL i=1;i<=n;++i){
		scanf("%lld",a+i);
		mx=max(mx,a[i]);
	}
	for (LL i=1;i<=n;++i){
		if (a[i]!=mx) break;
		if (i==n){
			if (a[i]==0){
				puts("YES");
				for (LL i=1;i<=n;++i) printf(i==n?"1\n":"1 ");
				puts("");
			}
			else puts("NO");
			return 0;
		}
	}
	for (LL i=1;i<=n;++i)
		if (a[i]==mx&&a[i-1>0?i-1:n]!=mx){
			f[i]=mx;
			for (LL j=i-1;j;--j) f[j]=f[j+1]+a[j];
			for (LL j=n;j>i;--j) f[j]=f[j+1>n?1:j+1]+a[j];
			for (LL j=1;j<=n;++j) if (i!=j) f[j]+=mx*n;
			break;
		}
	puts("YES"); for (LL i=1;i<=n;++i) printf(i==n?"%lld\n":"%lld ",f[i]);
	
	return 0;
}