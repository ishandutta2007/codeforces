#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;

ll choose(ll n, ll k){
	ll rtn = 1;
	for (ll i = 1; i <= k; i++)
		rtn = (rtn * (n - i + 1) / i);
	return rtn;
}

ll n;

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	cout << choose(n + 4, 5) * choose(n + 2, 3) << endl;
}