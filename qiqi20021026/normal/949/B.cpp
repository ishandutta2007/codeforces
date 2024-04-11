#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define jump(x) (((n)*2-(x))/2)

LL n,m,x;

int main(){
	scanf("%lld%lld",&n,&m);
	while (m--){
		scanf("%lld",&x);
		for (;!(x&1);x+=jump(x));
		printf("%lld\n",(x+1)/2);
	}
	
	return 0;
}