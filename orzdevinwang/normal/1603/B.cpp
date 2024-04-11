#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define ull unsigned long long 
using namespace std;
const int N = 1 << 20;
ll x, y;
void Main () {
	cin >> x >> y;
	if(x > y) 
		cout << x + y << '\n';
	else {
		cout << x * (y / x) + (y % x) / 2 << '\n';
//		ll n = x * (y / x) + (y % x) / 2;
//		assert (n % x == y % n);
	}
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	int T;
	cin >> T ;
	while (T--) Main (); 
	return 0;
}