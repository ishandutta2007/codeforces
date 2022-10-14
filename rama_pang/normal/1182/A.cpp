#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
	ll n;
	cin >> n;
	if (n==0){
		cout << 0 << endl;
		return 0;
	}
	if (n&1){
		cout << 0 << endl;
	} else{
		n = n/2;
		ll k=pow(2,n);
		cout << k << endl;
	}
	
}