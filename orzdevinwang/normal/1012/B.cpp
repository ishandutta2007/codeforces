#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1 << 20;
int n, m, q, f[N];
int find (int x) {
	return f[x] == x ? x : f[x] = find (f[x]);
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> n >> m >> q;
	L(i, 1, n + m) f[i] = i;
	while (q--) {
		int x, y;
		cin >> x >> y, y += n;
		x = find (x), y = find (y);
		if(x != y) f[x] = y;
	}
	int cnt = 0;
	L(i, 1, n + m) 
		if(find (i) == i) 
			cnt += 1;
	cout << cnt - 1 << '\n';
	return 0;
}