#include "bits/stdc++.h"
using namespace std;
long long a , b;
int main(){
	cin >> a >> b;
	long long ans = 1;
	if(b - a > 20){
		ans = 0;
	}
	else{
		++a;
		while(a <= b){
			ans *= a % 10;
			ans %= 10;
			++a;
		}
	}
	printf("%lld\n" , ans);
}