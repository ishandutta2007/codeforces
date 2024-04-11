#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
using namespace std;
const int N = 3e5 + 7;
int n, p[N];
void Main () {
	cin >> n;
	L(i, 1, n) cin >> p[i];
	L(i, 1, n) if (p[i] % 2 != i % 2) return cout << -1 << "\n", void();
	vi ns;
	auto find = [&] (int v) {
		L(i, 1, n) if(p[i] == v) return i;
		return -1;
	} ;
	auto rev = [&] (int r) {
		reverse(p + 1, p + r + 1);
		ns.push_back(r);
	} ;
	
	for(int i = n; i >= 3; i -= 2) {
		int odd = find (i), even = find (i - 1);
		if(odd < even) 
			rev(odd), rev(even - 1), odd = find (i);
		else 
			rev(odd), even = find(i - 1), rev(even - 1);
		rev(even + 1), rev(3), rev(i);
	}
	cout << sz(ns) << "\n";
	for(int x : ns) cout << x << " ";
	cout << "\n";
	L(i, 1, n) if(p[i] != i) assert (0);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}