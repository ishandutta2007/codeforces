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
	cin >> (s + 1);
	n = strlen(s + 1);
	if(s[n] == 'A') 
		cout << "NO\n";
	else {
		int sum = 0;
		L(i, 1, n) {
			sum += s[i] == 'A';
			sum -= s[i] == 'B';
			if(sum < 0) {
				return cout << "NO\n", void ();
			}
		}
		cout << "YES\n"; 
	}
//	cin >> (t + 1) >> (s + 1);
//	n = strlen(s + 1);
//	m = strlen(t + 1);
//	a[na = 1] = 0;
//	L(i, 1, n) {
//		if(t[i] == 'B') ++na, a[na] = 0;
//		else a[na] += 1;
//	}
//	b[nb = 1] = 0;
//	L(i, 1, n) {
//		if(s[i] == 'B') ++nb, b[nb] = 0;
//		else b[nb] += 1;
//	}
//	if(b[nb] > a[na]) {
//		cout << "NO\n";
//		return ;
//	}
//	--na, --nb;
//	int rnt = 0;
//	R(i, na, 1) {
//		if(nb > 0) {
//			if(rnt) {
//				rnt = max(rnt - a[na] + 1, 0);
//			} else if(b[nb] >= a[i]) {
//				rnt = b[nb] - a[i], --nb;
//			}
//		}
//	}
//	if(nb == 0 && !rnt) cout << "YES\n";
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}