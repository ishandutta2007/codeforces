#include <iostream>
 
using namespace std;
 
long long m = 998244353;
long long powmod(long long n, int k){
	long long res = 1;
	while(k){
		if(k % 2){
			res *= n;
			res %= m;
		}
		n = (n * n) % m;
		k /= 2;
	}
	return res;
}

int main(){
	int n, m;
	cin >> n >> m;
	cout << powmod(2, n+m);
}