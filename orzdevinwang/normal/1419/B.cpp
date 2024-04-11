#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = j; i <= k; i++)
#define R(i, j, k) for(int i = j; i >= k; i--) 
using namespace std;
const int N = 1e5 + 7;
int T;
long long k;
ll n;
ll get(ll x) {
	return x * (x + 1) / 2;
}
int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%lld", &k);
		n = k;
		int ans = 0;
		for(ll i = 1; i <= 31; i ++) {
			ll hh = (1LL << i) - 1;
			n -= get(hh);
			if(n < 0) {
				printf("%d\n", i - 1);
				break;
			}
		} 
	}
	return 0;
}