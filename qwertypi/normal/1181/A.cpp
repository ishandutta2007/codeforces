#include <iostream>

using namespace std;
typedef long long ll;
int main(){
	ll a, b, c;
	cin >> a >> b >> c;
	ll cnt = (a + b) / c;
	ll res = 0;
	if(a % c + b % c >= c){
		res = min(c - a % c, c - b % c);
	}
	cout << cnt << ' ' << res;
	return 0;
}