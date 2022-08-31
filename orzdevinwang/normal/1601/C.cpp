#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1 << 22, mod = 998244353;
int n, m, a[N], b[N];
int arr[N], atot;
vi cn[N];
int mp[N];
template < int N > struct fenwt {
	using F = long long ;
	F a[N + 1];
	void add (int x, F w) {
		for (; x <= atot + 1; x += x & -x) a[x] += w;
	}
	F query (int x) {
		F ret = 0;
		for (; x; x -= x & -x) ret += a[x];
		return ret;
	}
	F get (int l, int r) {
		if(l > r) return 0;
		return query (r) - query (l - 1);
	}
	void clear () {
		L(i, 1, atot + 1) a[i] = 0; 
	}
} ;
fenwt < N > S;

int mn[N], sum[N];
void upd (int x) {
	mn[x] = min (mn[x << 1], sum[x << 1] + mn[x << 1 | 1]);
	sum[x] = sum[x << 1] + sum[x << 1 | 1];
}
void add (int x, int L, int R, int p, int w) {
	if(L == R) return sum[x] += w, mn[x] = min(sum[x], 0), void ();
	int mid = (L + R) >> 1;
	if(p <= mid) add (x << 1, L, mid, p, w);
	else add (x << 1 | 1, mid + 1, R, p, w);
	upd (x);
}
void Main () {
	atot = 0;
	cin >> n >> m;
	L(i, 1, n) cin >> a[i], arr[++atot] = a[i];
	L(i, 1, m) cin >> b[i], arr[++atot] = b[i];
	sort(arr + 1, arr + atot + 1);
	atot = unique(arr + 1, arr + atot + 1) - arr - 1;
	L(i, 1, n) a[i] = lower_bound(arr + 1, arr + atot + 1, a[i]) - arr;
	L(i, 1, m) b[i] = lower_bound(arr + 1, arr + atot + 1, b[i]) - arr;
	L(i, 1, m) mp[b[i]] += 1;
	L(i, 1, n) cn[a[i]].push_back(i); 
	ll ns = 0;
	R(i, n, 1) {
		S.add (a[i], 1);
		ns += S.query (a[i] - 1);
	}
	int smaller = 0;
	L(i, 1, n) add (1, 1, n, i, 1);
	L(i, 1, atot) {
		for (const int &t : cn[i - 1]) 
			add (1, 1, n, t, -1), smaller += 1; //, cout << t << ' ' << -1 << '\n';
		for (const int &t : cn[i]) 
			add (1, 1, n, t, -1); //, cout << t << ' ' << -1 << '\n';
		ns += (ll) (smaller + mn[1]) * mp[i];
	} 
	cout << ns << '\n';
	S.clear ();
	L(i, 1, atot) mp[i] = 0, cn[i].clear ();
	L(i, 0, n * 4) mn[i] = sum[i] = 0; 
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}