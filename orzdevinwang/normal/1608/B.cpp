#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e5 + 7;
int n, a, b, p[N];
void Main () {
	cin >> n >> a >> b;
	bool swp = false;
	if(a < b) swp = true, swap (a, b); 
	if(a - b > 1) return cout << "-1\n", void ();
	int cnt = a + b + 2;
	if(cnt > n) return cout << "-1\n", void ();
	cnt -= 1;
	int tot = 0;
	if(a == b) {
		for (int u = 1; u <= cnt; u += 2) p[u] = ++tot;
		for (int u = 2; u <= cnt; u += 2) p[u] = ++tot;
		L(i, cnt + 1, n) p[i] = ++tot;
	}
	else {
		R(i, n, cnt + 1) p[i] = ++tot;
		for (int u = 1; u <= cnt; u += 2) p[u] = ++tot;
		for (int u = 2; u <= cnt; u += 2) p[u] = ++tot;
	}
	if(swp) {
		L(i, 1, n) p[i] = n - p[i] + 1;
	}
	L(i, 1, n) cout << p[i] << ' ';
	cout << '\n'; 
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	int t;
	cin >> t;
	while (t--) Main ();
	return 0;
}