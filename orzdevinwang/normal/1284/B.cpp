#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
#define uint unsigned int 
using namespace std;
const int N = 1 << 20;
int n, m, q, mx[N], mn[N], f[N];
bool ok[N];
int a[N], b[N]; 
ll cnt, ns;
int main() { 
	ios :: sync_with_stdio (false);
	cin.tie (0); cout.tie (0);
	cin >> n ;
	L(i, 1, n) {
		int l, w;
		cin >> l;
		mx[i] = -1e9, mn[i] = 1e9;
		L(j, 1, l) {
			cin >> w;
			if(w > mn[i]) ok[i] = true;
			mx[i] = max(mx[i], w);
			mn[i] = min(mn[i], w);
		}
		if(!ok[i]) a[mx[i]] += 1, b[mn[i]] += 1;
	}
	L(i, 0, N - 2) cnt += a[i], ns += b[i] * cnt;
	cout << (ll) n * n - ns << '\n';
	return 0;
}