#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int >
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long 
using namespace std;
const int N = 1e6 + 7;
ll inf = 1e9 + 7;
int n, p, b[N];
ll a[N];
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n ;
	L(i, 0, n - 1) {
		cin >> b[i];
	}
	L(i, 0, n - 1) {
		if(b[i] > b[(i + n - 1) % n]) {
			int lst = (i + n - 1) % n;
			a[i] = b[i];
			a[lst] = b[lst] + (ll) a[i] * inf;
			for(int j = (lst + n - 1) % n; j != i; j = (j + n - 1) % n) 
				a[j] = a[(j + 1) % n] + b[j];
			cout << "YES\n";
			L(c, 0, n - 1) cout << a[c] << ' ';
			cout << '\n';
			return 0; 
		}
	}
	if(b[0] == 0) {
		cout << "YES\n";
		L(i, 1, n) cout << 1 << ' ';
		cout << '\n';
		return 0;
	}
	cout << "NO\n";
	return 0;
}