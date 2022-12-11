#include <iostream>
using namespace std;
typedef long long ll;
int main() {
	ll n,k;
	cin >> n >> k;
	ll p,ne;
	ne = (n / 2) + (n % 2);
	if(k <= ne){
		cout << 1 + ((k - 1) * 2);
	}
	else{
		cout << ((k - ne)) * 2;
	}
	return 0;
}