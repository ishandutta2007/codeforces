#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
using namespace std;
int n, m;
void Main () {
	cin >> n >> m;
	if(n < m) swap(n, m);
	int S = n + m, l, r;
	if(S % 2 == 0) {
		l = n - S / 2, r = S - l;
		cout << (r - l + 2) / 2 << "\n";
		for(int i = l; i <= r; i += 2) cout << i << ' ';
		cout << '\n'; 
	} else {
		l = n - (S + 1) / 2, r = S - l;
		cout << r - l + 1 << "\n";
		L(i, l, r) cout << i << ' ';
		cout << '\n'; 
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main (); 
	return 0;
}