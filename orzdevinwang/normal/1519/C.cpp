#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++) 
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 2e5 + 7;
int n, m, k, g[N], q[N];
vector < ll > a[N];
ll ns[N];
void Main() {
	cin >> n;
	L(i, 1, n) cin >> g[i];
	L(i, 1, n) cin >> q[i], a[g[i]].push_back(q[i]);
	L(c, 1, n) sort(a[c].begin(), a[c].end()), reverse(a[c].begin(), a[c].end());
	L(i, 1, n) {
		L(j, 1, sz(a[i]) - 1) a[i][j] += a[i][j - 1];
		L(j, 1, sz(a[i])) ns[j] += a[i][sz(a[i]) / j * j - 1];
	}
	L(i, 1, n) cout << ns[i] << " ";
	cout << "\n";
	L(i, 1, n) a[i].clear(), ns[i] = 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--) Main();
	return 0;
}