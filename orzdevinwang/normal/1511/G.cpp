#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j), i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = k; i >= i##E; i--)
#define mkp make_pair
#define pii pair<int, int>
#define ll long long
#define db double
#define sz(a) a.size()
#define x first
#define y second
#define vi vector<int>
using namespace std;
const int N = 2e5 + 7;
int n, m, q, a[N], x[19][N], c[19][N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	L(i, 1, n) cin >> a[i], c[0][a[i]] ^= 1;
	L(i, 1, 18) L(j, 1, m - (1 << i) + 1) {
		c[i][j] = (c[i - 1][j] ^ c[i - 1][j + (1 << (i - 1))]);
		x[i][j] = (x[i - 1][j] ^ x[i - 1][j + (1 << (i - 1))]);
		if(c[i - 1][j + (1 << (i - 1))]) x[i][j] ^= (1 << (i - 1)); 
	}
	cin >> q;
	while(q--) {
		int l, r, ns = 0, sl;
		cin >> l >> r, ++r, sl = l;
		R(i, 18, 0) if(sl + (1 << i) <= r) {
			if(c[i][sl]) ns ^= sl - l;
			ns ^= x[i][sl], sl += (1 << i);
		}
		cout << (ns ? "A" : "B");
	}
	return 0;
}