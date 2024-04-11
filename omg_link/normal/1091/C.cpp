#include <stdio.h>
#include <algorithm>
#define MN 100000
typedef long long LL;
int n,m;
LL a[MN+5];
LL calc(int k){
	int l=1,r=n-(n-1)%k,len=(n-1)/k+1;
	return 1ll*(l+r)*len/2;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			a[++m]=calc(i);
			if(i*i!=n)
				a[++m]=calc(n/i);
		}
	}
	std::sort(a+1,a+1+m);
	for(int i=1;i<=m;i++)
		printf("%lld ",a[i]);
}