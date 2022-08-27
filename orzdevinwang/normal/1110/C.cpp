#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7; 
int q, n;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> q;
	while (q--) {
		cin >> n;
		int x = 1;
		while (x <= n) x <<= 1;
		x -= 1;
		if(x == n) {
			int ret = n, ns = 1e9;
			L(i, 2, sqrt (ret)) if(ret % i == 0) {
				while (ret % i == 0) ret /= i, ns = min(ns, i);
			}
			ns = min(ns, ret);
			cout << n / ns << "\n";
				
			
		}
		else {
			cout << x << "\n";
		}
	}
	return 0;
}