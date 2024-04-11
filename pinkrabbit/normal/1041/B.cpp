#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL a,b,x,y;
int main(){
	scanf("%lld%lld%lld%lld",&a,&b,&x,&y);
	LL d = __gcd(x,y);
	x/=d, y/=d;
	printf("%lld",min(a/x,b/y));
	return 0;
}