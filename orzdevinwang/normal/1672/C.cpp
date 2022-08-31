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
int n, m, a[N], na, b[N], nb;
char s[N], t[N];
void Main () {
	int ls = 1e9;
	int rs = 0;
	cin >> n;
	L(i, 1, n) 
		cin >> a[i];
	L(i, 1, n - 1) 
		if(a[i] == a[i + 1]) {
			ls = min(ls, i);
			rs = max(rs, i);
		}
	if(rs <= ls) {
		cout << 0 << '\n';
		return ;
	}
	cout << max(rs - ls - 1, 1) << '\n'; 
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}