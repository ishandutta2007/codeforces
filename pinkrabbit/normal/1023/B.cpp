#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n,k;

int main(){
	scanf("%lld%lld",&n,&k);
	if(k>=n+n) return 0*puts("0");
	if(k<=n){
		printf("%lld",(k-1)/2);
	}
	else{
		printf("%lld",n-k/2);
	}
	return 0;
}