#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
using namespace std;
const int N = 1e6 + 7;
int T;

int n, m, c[N], a[N], b[N]; 
void Main () {
	n = m = 0;
	int x;
	cin >> x;
	L(i, 1, x) {
		int w;
		cin >> w;
		c[i] = w;
		if(i & 1) a[++n] = w;
		else b[++m] = w;
	}
	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
	sort(c + 1, c + x + 1);
	n = 0, m = 0;
	L(i, 1, x) {
		if(i & 1) {
			if(a[++n] != c[i]) return cout << "NO\n", void();
		}
		else {
			if(b[++m] != c[i]) return cout << "NO\n", void();
		} 
	}
	cout << "YES\n";
}
int main() { 
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--) Main();
	return 0;
}