#include <iostream>
using namespace std;

#define forn(i,n) for(int i = 0; i < n; i++)

typedef long long ll;

ll pow(ll b,ll p) {
	ll r = 1;
	forn(i,p)r *= b;
	return r;
}

int main()
{
	ll n, k; cin >> n >> k;
	ll fc = 0, tc = 0;
	while(n % 5 == 0) {
		n /= 5;
		fc++;
	}
	while(n % 2 == 0) {
		n /= 2;
		tc++;
	}
	cout << n * pow(5,max(k,fc)) * pow(2,max(k,tc)) << '\n';
	return 0;
}