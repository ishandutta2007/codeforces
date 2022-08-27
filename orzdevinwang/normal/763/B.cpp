#include<bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); i++)
#define R(i, j, k) for (int i = (j); i >= (k); i--) 
#define sz(a) ((int) (a).size())
#define ll long long 
#define vi vector < int > 
using namespace std;
const int N = 5e5 + 7;
int n;
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	cout << "YES\n";
	while (n--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << (a & 1) + (b & 1) * 2 + 1 << '\n';
	}
	return 0;
}