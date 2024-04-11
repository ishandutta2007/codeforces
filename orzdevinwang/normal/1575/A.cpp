#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7;
int n, m, ord[N];
string s[N];
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	L(i, 1, n) cin >> s[i], ord[i] = i;
	L(i, 1, n) 
		L(j, 0, m - 1) 
			if(j & 1) 
				s[i][j] = 24 - (s[i][j] - 'a') + 'a';
	sort(ord + 1, ord + n + 1, [&] (int x, int y) {
		return s[x] < s[y];
	});
	L(i, 1, n) cout << ord[i] << ' ';
	cout << '\n';
		
	return 0;
}