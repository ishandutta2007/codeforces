#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int 
using namespace std;
const int N = 1e6 + 7, O = 5e5;
int n, a[N], pw[N], tp;
void Main() {
	cin >> n;
	if(n <= 99) {
		cout << n % 10 << '\n';
		return ;
	}
	tp = 0;
	int ns = 1e9;
	while(n) ns = min(ns, n % 10), n /= 10;
	cout << ns << '\n';
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	pw[1] = 1;
	L(i, 2, 10) pw[i] = pw[i - 1] * 10;
	while(T--) Main();
	return 0;
}

/*
1
7 
0010110
*/