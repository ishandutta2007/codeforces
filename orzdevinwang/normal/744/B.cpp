#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int >
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long 
#define rs(x) resize(x)
using namespace std;
const int N = 2007;
int n, f[N], ns[N]; 
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n; 
	L(i, 1, n) f[i] = 1e9;
	L(w, 0, 9) {
		vi A, B;
		L(i, 1, n) if(!(i >> w & 1)) {
			A.emplace_back(i);
		} else B.emplace_back(i);
		if(sz(A)) {
			cout << sz(A) << '\n';
			for(const int &u : A) cout << u << ' ';
			cout << endl;
			L(i, 1, n) cin >> ns[i];
			for(const int &u : B) f[u] = min(f[u], ns[u]);
		}
		
		if(sz(B)) {
			cout << sz(B) << '\n';
			for(const int &u : B) cout << u << ' ';
			cout << endl; 
			L(i, 1, n) cin >> ns[i];
			for(const int &u : A) f[u] = min(f[u], ns[u]);
		}
	}
	cout << -1 << '\n';
	L(i, 1, n) cout << f[i] << ' ';
	cout << endl;
	return 0;
}