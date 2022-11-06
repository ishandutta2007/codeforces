#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main() {
	ll n, tmp;
	scanf("%llu", &n);
	ll s = 0, cs;
	for (ll i = 0; i < n; i++) {
		scanf("%llu", &tmp);
		s ^= tmp;
	}
	cs = s;
	for (ll i = 1; i < n; i++) {
		scanf("%llu", &tmp);
		cs ^= tmp;
	}
	printf("%llu\n", cs);
	for (ll i = 2; i < n; i++) {
		scanf("%llu", &tmp);
		s ^= tmp;
	}
	s ^= cs;
	printf("%llu\n", s);
}