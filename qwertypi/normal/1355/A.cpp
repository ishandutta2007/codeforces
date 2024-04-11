#include <bits/stdc++.h>
#define int long long
using namespace std;

int f(int x){
	set<int> digits;
	while(x){
		digits.insert(x % 10);
		x /= 10;
	}
	
	return (*digits.begin()) * (*--digits.end());
}

int pow_10[19];
int32_t main(){
	pow_10[0] = 1;
	for(int i = 0; i < 18; i++){
		pow_10[i + 1] = pow_10[i] * 10;
	}
	int t;
	cin >> t;
	while(t--){
		long long n, k;
		cin >> n >> k;
		k--;
		int nn = 0;
		while(k != 0 && nn != n){
			nn = n;
			k--; n += f(nn);
		}
		if(k == 0 || nn == n){
			cout << n << endl;
			continue;
		}
	}
}