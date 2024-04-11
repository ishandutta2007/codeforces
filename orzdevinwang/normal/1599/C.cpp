#include<bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); ++i) 
#define R(i, j, k) for (int i = (j); i >= (k); --i)  
#define ll long long
#define vi vector < int > 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 2e5 + 7;
int n;
double P;
int C(int x, int t) {
	ll ret = 1;
	L(i, 1, t) ret *= x - i + 1;
	L(i, 1, t) ret /= i;
	return ret;
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n >> P;
	L(i, 0, n) {
		double ns = 0;
		L(a, 0, 3) {
			int sum = C(i, a) * C(n - i, 3 - a);
			if(a == 1) ns += sum * 0.5;
			if(a >= 2) ns += sum;
		}
		ns /= C(n, 3);
//		cout << ns << '\n';
		if(ns >= P) 
			return cout << i << '\n', 0;
	}
	return 0;
}