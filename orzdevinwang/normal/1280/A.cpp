#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = (1 << 20), mod = 1e9 + 7 ;
int n, x;
char s[N]; 
void Main () {
	cin >> x >> (s + 1), n = strlen(s + 1);
	int ret = n, mx = n;
	L(i, 1, x) {
		int len = mx - i;
//		cout << i << " : " << s[i] - '0' << '\n';
		L(j, 1, s[i] - '1') {
			L(k, mx + 1, min(mx + len, x)) s[k] = s[k - mx + i];
			mx = min(mx + len, x);	 
		}
		ret = (i + (ll) (ret + mod - i) * (s[i] - '0') % mod) % mod;
//		cout << "ret = " << ret << '\n';
	}
	cout << ret << '\n';
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}