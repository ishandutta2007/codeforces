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
int n, a[N], b[N], na, nb, sa[N], ca[N], sb[N], cb[N];
void slv(int *a, int &pn, int *s, int *c) {
	pn = 0;
	R(i, n, 1) {
		if(a[i] != s[pn]) 
			++pn, s[pn] = a[i], c[pn] = 0;
		c[pn] += 1;
	}
}
int rp[N];
void Main () {
	cin >> n;
	L(i, 1, n) rp[i] = 0;
	L(i, 1, n) 
		cin >> a[i];
	L(i, 1, n) 
		cin >> b[i];
	slv(a, na, sa, ca);
	slv(b, nb, sb, cb);
	int pos = 1;
	L(i, 1, na) {
		if(pos <= nb && sb[pos] == sa[i]) {
			rp[sa[i]] += cb[pos];	
			++pos;
		}
//		cout << rp[sa[i]] << '\n';
		rp[sa[i]] -= ca[i];
		if(rp[sa[i]] < 0) {
			cout << "NO\n";
			return ;
		}
	} 
	cout << "YES\n";
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}