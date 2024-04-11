#include <bits/stdc++.h>
 
#define int int64_t
#define mod (1000000007)
using namespace std;
 
int32_t main(){
	int n;
	cin >> n;
	int l = floor(log2(n));
	cout << (1 << l) * l << endl;
	for(int i = 1; i <= l; i++){
		for(int j = 0; j < (1 << l - i); j++){
			for(int k = 0; k < (1 << i - 1); k++){
				cout << 1 + ((j << i) + k) << ' ' << 1 + ((j << i) + (1 << i - 1) + k) << endl;
			}
		}
	}
 
	for(int i = 1; i <= l; i++){
		for(int j = 0; j < (1 << l - i); j++){
			for(int k = 0; k < (1 << i - 1); k++){
				cout << n - (1 << l) + 1 + ((j << i) + k) << ' ' << n - (1 << l) + 1 + ((j << i) + (1 << i - 1) + k) << endl;
			}
		}
	}
}