#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
#define uint unsigned int 
using namespace std;
const int N = 2e5 + 7;
int n, m, q;
string s[N], t[N];
int main() { 
	ios :: sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
	cin >> n >> m;
	L(i, 1, n) cin >> s[i];
	L(i, 1, m) cin >> t[i];
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		cout << s[(x - 1) % n + 1] << t[(x - 1) % m + 1] << '\n';
	} 
	return 0;
}