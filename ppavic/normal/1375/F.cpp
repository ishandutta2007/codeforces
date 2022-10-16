#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

ll a, b, c;
int tko = 1;

int main(){
	scanf("%lld%lld%lld", &a, &b, &c);
	printf("First\n");
	if(b == max(a, max(b, c)))
		tko = 2;
	if(c == max(a, max(b, c)))
		tko = 3;
	ll x = 3 * max(a, max(b, c)) - (a + b + c);
	printf("%lld\n", x);
	fflush(stdout);
	int kome; scanf("%d", &kome);
	if(kome == 1) a += x;
	if(kome == 2) b += x;
	if(kome == 3) c += x;
	if(tko != kome){
		if(tko == 3 && kome == 1){
			printf("%lld\n", c - b);
		}
		if(tko == 3 && kome == 2){
			printf("%lld\n", c - a);
		}
		if(tko == 2 && kome == 1){
			printf("%lld\n", b - c);
		}	
		if(tko == 2 && kome == 3){
			printf("%lld\n", b - a);
		}
		if(tko == 1 && kome == 2){
			printf("%lld\n", a - c);
		}	
		if(tko == 1 && kome == 3){
			printf("%lld\n", a - b);
		}
		fflush(stdout);
	}
	else{
		x = 3 * max(a, max(b, c)) - (a + b + c);
		printf("%lld\n", x);
		fflush(stdout);
		int kome; scanf("%d", &kome);
		if(kome == 1) a += x;
		if(kome == 2) b += x;
		if(kome == 3) c += x;
		if(tko == 3 && kome == 1){
			printf("%lld\n", c - b);
		}
		if(tko == 3 && kome == 2){
			printf("%lld\n", c - a);
		}
		if(tko == 2 && kome == 1){
			printf("%lld\n", b - c);
		}	
		if(tko == 2 && kome == 3){
			printf("%lld\n", b - a);
		}
		if(tko == 1 && kome == 2){
			printf("%lld\n", a - c);
		}	
		if(tko == 1 && kome == 3){
			printf("%lld\n", a - b);
		}
		fflush(stdout);
		
	}
	
}