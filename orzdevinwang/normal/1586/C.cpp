#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
using namespace std;
const int N = 1e6 + 7; 
int n, m, vis[N];
string s[N];
int can[N];
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n >> m;
	L(i, 1, n) {
		cin >> s[i];
		s[i] = "#" + s[i];
	}
	L(i, 1, n - 1) 
		L(j, 1, m - 1) 
			if(s[i][j + 1] == 'X' && s[i + 1][j] == 'X') 
				can[j + 1] = 1;
//	L(i, 1, m) cout << can[i] << ' ';
//	cout << '\n';
	L(i, 1, m) can[i] += can[i - 1];
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		if(can[r] - can[l] == 0) 
			cout << "YES\n";
		else 
			cout << "NO\n";
	}
	return 0;
}