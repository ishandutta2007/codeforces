#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i) 
#define R(i, j, k) for(int i = (j); i >= (k); --i) 
#define ll long long 
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a)) 
using namespace std;
const int N = 1e6 + 7;
int n;
int G[1000][1000]; 
void ins (int x, int y) {
//	L(i, 1, 100) 
//		L(j, 1, 100) 
//			if(i == x || j == y || (i - j) == x - y)
//			 	G[i][j] = 1;
} 
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n; 
	cout << n - (n + 1) / 3 << '\n';
	bool op = false;
	if(n % 3 == 0) op = true, --n;
	int t = (n + 2) / 3, xt = n / 3;
	L(i, 1, t) {
		cout << i << ' ' << t - i + 1 << '\n';
		ins(i, t - i + 1);
	}
	L(i, 1, xt) {
		cout << t + i << ' ' << t + xt - i + 1 << '\n'; 
		ins(t + i, t + xt - i + 1);
	}
	if(op) cout << n + 1 << ' ' << n + 1 << '\n', ins(n + 1, n + 1), ++n;
//	L(i, 1, n) 
//		L(j, 1, n) 
//			assert(G[i][j]);
	return 0;
}
/*
x.....


*/