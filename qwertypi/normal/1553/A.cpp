#include <bits/stdc++.h>
 
#define int long long
using namespace std;
 
int powmod(int a, int b, int p){
	int res = 1;
	while(b){
		if(b % 2){
			res = (res * a) % p;
		}
		b /= 2;
		a = (a * a) % p;
	}
	return res;
}
 
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << (n + 1) / 10 << endl;
	}
}