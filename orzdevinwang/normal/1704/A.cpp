#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
using namespace std;
const int N = 1e6 + 7;
int n, m, a[N];
char s[N], t[N];
void Main() {
	cin >> n >> m >> (s + 1) >> (t + 1);
	if(n == m) {
		L(i, 1, n) 
			if(s[i] != t[i]) 
				return cout << "NO\n", void ();
		cout << "YES\n";
		return ;
	}
	L(i, 1, m - 1) 
		if(s[i + n - m + 1] != t[i + 1]) 
			return cout << "NO\n", void();
	L(i, 1, n - m + 1)
		if(s[i] == t[1]) 
			return cout << "YES\n", void();
	cout << "NO\n";
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}