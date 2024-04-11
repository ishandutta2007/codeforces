#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
#define ld long double
#define i128 __int128 
using namespace std;
const int N = 1e6 + 7;
int n, all;
int sum;
int qry(int x) {
	cout << "? " << x << endl;
	int w;
	cin >> w;
	return w;
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> n;
	int l = 1, r = 1e7;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(qry(mid) == 1) sum = mid, r = mid - 1;
		else l = mid + 1;
	}
	sum -= n - 1;
	int ns = sum + n - 1;
	L(i, 2, n) {
//		int emp = i - ns - 1;
//		int ls = sum + (n - i);
		int km = (sum + n - 1) / i; 
		int w = qry(km);
		if(w) ns = min(ns, w * km);
	} 
	cout << "! " << ns << '\n';
	return 0;
}