#include "bits/stdc++.h"
using namespace std;
int m , b;
long long ans;
long long get(int x){
	return (1LL * x * (x + 1LL)) / 2;
}
int main(){
	cin >> m >> b;
	for(int y = 0 ; y <= b ; ++y){
		int x = m * (b - y);
		ans = max(ans , (y + 1LL) * get(x) + (x + 1LL) * get(y));
	}
	printf("%lld\n" , ans);
}