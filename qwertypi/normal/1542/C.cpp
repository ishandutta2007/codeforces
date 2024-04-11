#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int A[300000];
int min_B[3000];
int mod = 1000000007;
void sub(){
	int n;
	cin >> n;
	int prod = 1;
	int ans = 0;
	for(int i = 2; i <= 50; i++){
		ans += i % mod * (n / prod / (i / __gcd(i, prod)) * ((i / __gcd(i, prod)) - 1) + (n / prod % (i / __gcd(i, prod)))) % mod;
		ans %= mod;
		prod = prod / __gcd(prod, i) * i;
	}
	cout << ans << endl;
}
 
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}