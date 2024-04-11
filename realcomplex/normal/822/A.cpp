#include <iostream>
using namespace std;

typedef long long ll;

int main() {
	
	ll a,b;
	cin >> a >> b;
	ll sk = 1;
	for(ll i = 2;i<=min(a,b);i++){
		sk *= i;
	}
	cout << sk;
	return 0;
}