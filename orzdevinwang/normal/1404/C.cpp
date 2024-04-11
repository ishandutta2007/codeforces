#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++)
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 3e5 + 7;
int n, m, a[N];
vi orz[N * 4]; 
void build (int x, int l, int r) {
	if(l == r) return orz[x].push_back(a[l]), void();
	int mid = (l + r) >> 1, p = 0, now = 0;
	build(x * 2, l, mid), build(x * 2 + 1, mid + 1, r);
	vi &a = orz[x * 2], &b = orz[x * 2 + 1];
	L(i, 0, sz(a) - 1) {
		while(p < sz(b) && b[p] <= a[i] + i - 1) orz[x].push_back(max(b[p] - i, now)), ++p;
		orz[x].push_back(a[i]), now = a[i];
	}
	while(p < sz(b)) orz[x].push_back(max(b[p] - sz(a), now)), ++p;
}
int ns;
void query (int x, int L, int R, int l, int r) {
	if(l <= L && R <= r) 
		return ns += upper_bound(orz[x].begin(), orz[x].end(), ns) - orz[x].begin(), void();
	int mid = (L + R) >> 1;
	if(l <= mid) 
		query(x * 2, L, mid, l, r); 
	if(r > mid) 
		query(x * 2 + 1, mid + 1, R, l, r);
} 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);  
	cin >> n >> m;
	L(i, 1, n) cin >> a[i]; 
	L(i, 1, n) a[i] = a[i] > i ? 1e9 : i - a[i];
	build (1, 1, n);
	while(m--) {
		int l, r;
		cin >> l >> r, ++l, r = n - r, ns = 0, query(1, 1, n, l, r), cout << ns << "\n";
	}
	return 0;
}