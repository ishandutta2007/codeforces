#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 2e6 + 7;
int n, m, a[N];
char s[N], t[N]; 
void Main () {
	cin >> (s + 1) >> (t + 1), n = strlen(s + 1), m = strlen(t + 1);
	if(n < m) return cout << "NO\n", void ();
	if((n - m) % 2 == 1) {
		--n;
		L(i, 1, n) s[i] = s[i + 1];
	}
	int now = 1, i = 1;
	while(i <= n) {
		if(now <= m && s[i] == t[now]) ++now;
		else ++i;
		++i;
	}
	if(now == m + 1) cout << "YES\n";
	else cout << "NO\n";
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	int T;
	cin >> T;
	while (T--) Main (); 
	return 0;
}