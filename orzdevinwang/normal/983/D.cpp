#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++) 
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) a.size()
#define vi vector<int>
using namespace std;
const int N = (1 << 20);
int n, mn[N], mx[N], ns = 1;
// mn :  
// mx :  
int l[N], r[N], sl[N], sr[N];
int arr[N], atot, pn;
set < int > col[N];
struct pr { int t, id, op; } a[N];
bool vis[N];
void upd(int id) {
	if(col[id].empty()) 
		return mx[id] = max(mx[id << 1], mx[id << 1 | 1]), mn[id] = min(mn[id << 1], mn[id << 1 | 1]), void();
	int mxs = max(mx[id << 1], mx[id << 1 | 1]), u = *col[id].rbegin();
	if(mxs > u) mx[id] = mxs; 
	else if(!vis[u] && u >= min(mn[id << 1], mn[id << 1 | 1])) mx[id] = u;
	else mx[id] = -1; 
	mn[id] = max(u, min(mn[id << 1], mn[id << 1 | 1]));
}
void add(int id, int L, int R, int x, int op) {
	if(sr[x] < L || R < sl[x]) return;
	if(sl[x] <= L && R <= sr[x]) {
		if(op == 1) col[id].insert(x); 
		if(op == -1) col[id].erase(x);
		upd(id);
		return;
	}
	int mid = (L + R) >> 1;
	add(id << 1, L, mid, x, op), add(id << 1 | 1, mid + 1, R, x, op), upd(id);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	memset(mx, -1, sizeof(mx)), cin >> n;
	L(i, 1, n) cin >> l[i] >> sl[i] >> r[i] >> sr[i];
	L(i, 1, n) arr[++atot] = l[i], arr[++atot] = r[i];
	sort(arr + 1, arr + atot + 1), atot = unique(arr + 1, arr + atot + 1) - arr - 1;
	L(i, 1, n) l[i] = lower_bound(arr + 1, arr + atot + 1, l[i]) - arr, r[i] = lower_bound(arr + 1, arr + atot + 1, r[i]) - arr - 1;
	
	atot = 0;
	L(i, 1, n) arr[++atot] = sl[i], arr[++atot] = sr[i];
	sort(arr + 1, arr + atot + 1), atot = unique(arr + 1, arr + atot + 1) - arr - 1;
	L(i, 1, n) sl[i] = lower_bound(arr + 1, arr + atot + 1, sl[i]) - arr, sr[i] = lower_bound(arr + 1, arr + atot + 1, sr[i]) - arr - 1;
	L(i, 1, n) 
		++pn, a[pn].t = l[i], a[pn].id = i, a[pn].op = 1, 
		++pn, a[pn].t = r[i] + 1, a[pn].id = i, a[pn].op = -1;
	sort(a + 1, a + pn + 1, [&] (pr a, pr b) { return a.t < b.t; });
	int o = 1;
	L(i, 1, pn) {
		while(o <= pn && a[o].t == i) add(1, 1, pn, a[o].id, a[o].op), ++o;
		while(~mx[1]) vis[mx[1]] = true, ++ns, add(1, 1, pn, mx[1], 0);
	}
	cout << ns << "\n";
	return 0;
}