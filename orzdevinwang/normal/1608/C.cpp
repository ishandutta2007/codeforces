#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 5e5 + 7, mod = 998244353;
int n;
int a[N], mpa[N];
int b[N], mpb[N];
int ord[N];
bool ok[N];
void Main () {
	cin >> n;
	L(i, 1, n) cin >> a[i];
	L(i, 1, n) cin >> b[i];
	L(i, 1, n) ok[i] = false; 
	L(i, 1, n) ord[i] = i;
	sort(ord + 1, ord + n + 1, [&] (int x, int y) { return a[x] < a[y]; });
	L(i, 1, n) a[ord[i]] = i, mpa[i] = ord[i];
	sort(ord + 1, ord + n + 1, [&] (int x, int y) { return b[x] < b[y]; });
	L(i, 1, n) b[ord[i]] = i, mpb[i] = ord[i];
	int x = n, y = n;
	queue < int > q;
	q.push (mpa[n]);
	q.push (mpb[n]);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		if(ok[u]) continue ;
		ok[u] = true;
		L(i, a[u], x - 1) q.push (mpa[i]);
		x = min(x, a[u]);
		L(i, b[u], y - 1) q.push (mpb[i]);
		y = min(y, b[u]);
	}
	L(i, 1, n) if(ok[i]) cout << "1";
	else cout << "0";
	cout << "\n";
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	int t;
	cin >> t;
	while (t--) Main (); 
	return 0;
}