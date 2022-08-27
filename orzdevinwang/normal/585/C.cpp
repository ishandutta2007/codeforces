#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e5 + 7, M = 55, mod = 1e9 + 7;
ll x, y;
vector < pair < ll, char > > vc;
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> x >> y;
	while (x > 1 || y > 1) {
		if(x == y) return cout << "Impossible\n", 0;
		if(x > y) {
			ll p = (x - 1) / y;
			vc.push_back( {p, 'A'} );
			x -= y * p;
		} else if(y > x) {
			ll p = (y - 1) / x;
			vc.push_back( {p, 'B'} );
			y -= p * x;
		}
	}
	for (auto u : vc) 
		cout << u.first << u.second;
	return 0;
}