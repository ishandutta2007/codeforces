#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
using namespace std;
const int N = 2e6 + 7, mod = 998244353;
int n, m, v[N];
void Main () {
	cin >> n >> m;
	L(i, 1, n) cin >> v[i];
	L(i, n - m + 1, n) 
		if(v[i] > 0) 
			return cout << 0 << '\n', void ();
	int ns = 1;
	L(i, 1, m) ns = (ll) ns * i % mod; 
	L(i, 1, n - m) {
		if(v[i] == 0) {
			ns = (ll) ns * (m + 1) % mod;
		} else if(v[i] == -1) {
			ns = (ll) ns * (i + m) % mod;
		} else if(v[i] >= i) {
			ns = 0;
		}
	}
	cout << ns << '\n';
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);	
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}