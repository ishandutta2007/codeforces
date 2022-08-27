#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
using namespace std;

const int N = 1e6 + 7; 

int n, dp[N];
ll t[N], a[N], v;
int ord[N], tl[N], tr[N]; 

ll arr[N], atot;
int c[N], lim;
void add(int x, int w) {
	for(; x <= lim; x += x & -x) 
		c[x] = max(c[x], w);
}
void clear(int x) {
	for(; x <= lim; x += x & -x) 
		c[x] = -1e9;	
}
int query(int x) {
	int ret = -1e9;
	for(; x; x -= x & -x) ret = max(ret, c[x]);
	return ret;
}


void divide(int L, int R) {
	if(L == R) return ;
	int mid = (L + R) >> 1; 
	divide(L, mid);
	
	L(i, L, R) ord[i] = i;
	sort(ord + L, ord + R + 1, [&] (int x, int y) {
		return a[x] < a[y];
	});
	L(i, L, R) {
		int u = ord[i];
		if(u <= mid) add(tl[u], dp[u] + 1);
		else dp[u] = max(dp[u], query(tl[u]));
	} 
	L(i, L, R) clear(tl[ord[i]]);
	
	R(i, R, L) {
		int u = ord[i];
		if(u <= mid) add(tr[u], dp[u] + 1);
		else dp[u] = max(dp[u], query(tr[u]));
	} 
	L(i, L, R) clear(tr[ord[i]]);
	
	divide(mid + 1, R);
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	me(c, -0x3f);
	cin >> n >> v;
	L(i, 1, n) cin >> t[i], t[i] *= v;
	L(i, 1, n) cin >> a[i];
	L(i, 0, n) arr[i * 2 + 1] = t[i] - a[i], arr[i * 2 + 2] = t[i] + a[i];
	lim = n * 2 + 2;
	sort(arr + 1, arr + lim + 1);
	L(i, 0, n) 
		tl[i] = lower_bound(arr + 1, arr + lim + 1, t[i] - a[i]) - arr, 
		tr[i] = lower_bound(arr + 1, arr + lim + 1, t[i] + a[i]) - arr;
	
	t[0] = 0, a[0] = 0, dp[0] = 0;
	L(i, 1, n) dp[i] = -1e9;
	divide(0, n);
	int ns = 0;
	L(i, 1, n) ns = max(ns, dp[i]);
	cout << ns << '\n'; 
	return 0; 
}