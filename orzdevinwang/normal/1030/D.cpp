#include<bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); ++i) 
#define R(i, j, k) for (int i = (j); i >= (k); --i)  
#define ll long long
#define vi vector < int > 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e5 + 7;
int n, m, k;
void print (int x, int y) {
	cout << "YES\n";
	cout << 0 << ' ' << 0 << '\n';
	cout << x << ' ' << 0 << '\n';
	cout << 0 << ' ' << y << '\n';
	return ;
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	if((ll) n * m * 2 % k != 0) return cout << "NO\n", 0 ;
	bool op = false;
	if(k % 2 == 0) {
		k /= 2, op = true;
	}
	int x, y, a = __gcd(n, k);
	if(a > 1) {
		x = n / a, y = m / (k / a); 
		if(!op) x *= 2;
		print (x, y);
	}
	else {
		x = n, y = m / k;
		if(!op) y *= 2;
		print (x, y);
	}
	return 0;
}