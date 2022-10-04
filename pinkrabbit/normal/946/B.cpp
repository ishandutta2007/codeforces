#include<bits/stdc++.h>
#define ll long long

ll a,b;

int main(){
	scanf("%lld%lld",&a,&b);
	while(a!=0&&b!=0){
		if(a>=b+b) a=a%(b+b);
		else if(b>=a+a) b=b%(a+a);
		else break;
	}
	printf("%lld %lld",a,b);
	return 0;
}