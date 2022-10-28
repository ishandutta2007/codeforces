#include "bits/stdc++.h"
using namespace std;
long long n , a , b , p , q;
long long ans;
int main(){
	cin >> n >> a >> b >> p >> q;
	long long lcm = 1LL * a * b / __gcd(a , b);
	ans = 0;
	ans += 1LL * ((n / a) - (n / lcm)) * p;
	ans += 1LL * ((n / b) - (n / lcm)) * q;
	ans += 1LL * (n / lcm) * max(p , q);
	cout << ans;
}