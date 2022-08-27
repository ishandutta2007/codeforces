#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1 << 20;
int n, xum, a[N], p[N], q[N], v[N], mp[N];
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n;
	L(i, 0, (1 << n) - 1) cin >> a[i], p[i] = q[i] = i, mp[i] = i, v[i] = 0, xum ^= a[i];
	if(xum) return cout << "Fou\n", 0;
	L(i, 0, (1 << n) - 2) {
		int d = v[i] ^ a[i];
		v[i] ^= d, v[i + 1] ^= d;
		for (int u = i; ; ) {
			int r = mp[q[u] ^ v[u]];
			if (r == u) break ;
			swap (p[r], p[u]), swap (q[r], q[i + 1]), swap (mp[p[u]], mp[p[r]]), u = r;
		}
	}
	cout << "Shi\n";
	L(i, 0, (1 << n) - 1) cout << p[i] << ' ';
	cout << '\n';
	L(i, 0, (1 << n) - 1) cout << q[i] << ' ';
	cout << '\n';
	return 0;
}