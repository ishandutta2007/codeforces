#include<bits/stdc++.h>
typedef long long LL;

LL n,k;

int main(){
	scanf("%I64d%I64d",&n,&k);
	printf("%I64d\n",(k-1)/n+1);
	return 0;
}