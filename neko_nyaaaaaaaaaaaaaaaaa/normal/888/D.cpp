#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
ll factorial(ll n) {
    ll ans = 1;
    ll i = 2;
    while (i <= n) {
        ans *= i;
        i++;
    }
    return ans;
}
 
long long tohop(long long n, long long t) {
	long long ans = 1;
	long long m = factorial(t);
	while (t--) {
		ans *= n;
		n--;
	}
	return ans/m;
}
 
int main() {
	
	vector<ll> a = {0, 1, 2, 9};
	long long n, k;
	cin >> n >> k;
	ll ans = 1;
	k--;
	while (k) {
		ans += a[k]*tohop(n, k+1);
		k--;
	}
	cout << ans;
	
	return 0;
}