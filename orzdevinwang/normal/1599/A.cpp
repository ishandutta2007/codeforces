#include<bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); ++i) 
#define R(i, j, k) for (int i = (j); i >= (k); --i)  
#define ll long long
#define vi vector < int > 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 2e5 + 7;
int n, a[N], cf[N];
char s[N];
int rk[N];
char op[N];
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n;
	L(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	cin >> (s + 1);
	L(i, 1, n) {
		if(s[i] != s[i - 1]) { 
			rk[i] = i, op[i] = s[i];
		}
		else {
			cf[i - 1] = 1, rk[i] = 1;
			if(i % 2 == 0) op[i] = s[i] == 'L' ? 'R' : 'L';
			else op[i] = s[i];
		}
	}
	R(i, n, 1) cf[i] += cf[i + 1];
	L(i, 1, n) rk[i] += cf[i];
	L(i, 1, n) cout << a[rk[i]] << " " << op[i] << "\n";
	return 0;
}