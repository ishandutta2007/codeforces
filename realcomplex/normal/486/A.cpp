#include <iostream>
using namespace std;

typedef long long ll;

int main() {
	ll n;
	cin >> n;
	ll sk = n / 2;
	if(n % 2 == 1){
		sk -= n;
	}
	cout << sk;
	return 0;
}