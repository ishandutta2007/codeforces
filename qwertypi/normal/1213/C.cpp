#include <iostream>
#include <numeric>
typedef long long ll;
using namespace std;

int main(){
	int q;
	cin >> q;
	while(q--){
		int digit[10];
		ll n, m;
		cin >> n >> m;
		ll d = n / m;
		for(int i=0;i<10;i++){
			digit[i] = (m * (i + 1)) % 10;
		}
		ll sum = accumulate(digit, digit + 10, 0LL);
		ll ans = accumulate(digit, digit + d % 10, sum * (d / 10));
		cout << ans << endl;
	}
}