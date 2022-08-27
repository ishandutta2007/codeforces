#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
using namespace std;
const int N = 5e5 + 7, M = N * 20; 
int n, a[N], f[N], dp[N];
int hd[N], ch[M][2], w[M], tot;
void add (int x, int &nw, int L, int R, int p, int ww) {
	nw = ++tot;
	if(L == R) return w[nw] = ww, void ();
	ch[nw][0] = ch[x][0], ch[nw][1] = ch[x][1];
	int mid = (L + R) >> 1;
	if(p <= mid) add (ch[x][0], ch[nw][0], L, mid, p, ww);
	else add (ch[x][1], ch[nw][1], mid + 1, R, p, ww);
}
int query (int x, int L, int R, int p) {
	if(L == R) return w[x];
	int mid = (L + R) >> 1;
	if(p <= mid) return query (ch[x][0], L, mid, p);
	else return query (ch[x][1], mid + 1, R, p);
}
void Main () {
	L(i, 1, tot) ch[i][0] = ch[i][1] = 0;
	L(i, 1, n) hd[i] = 0;
	tot = 0;
	
	cin >> n;
	L(i, 1, n) cin >> a[i];
	R(i, n, 1) {
		f[i] = query (hd[i + 1], 1, n, a[i]);
		if(!f[i]) f[i] = -1;
		add (hd[f[i] + 1], hd[i], 1, n, a[i], i);
	}
//	L(i, 1, n) cout << f[i] << ' ';
//	cout << '\n';
	ll ns = 0;
	L(i, 0, n) dp[i] = 0;
	dp[0] = 1;
	L(i, 1, n) {
		dp[i] += 1;
		if(f[i] != -1) dp[f[i]] += dp[i - 1];
		ns += dp[i] - 1;
	}
	cout << ns << '\n';
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--) Main ();
	return 0;
}