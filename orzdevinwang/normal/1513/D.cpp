#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define pii pair<int, int>
#define db double
#define x first
#define y second
#define mkp make_pair
#define sz(a) ((int) (a).size())
#define vi vector<int>
using namespace std;
const int N = 2e5 + 7, M = N * 20, inf = 1e9 + 7;

ll ns;

int f[N];
int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
int mk(int l, int r) {
	int cnt = 0;
	while(find(l) <= r) l = find(l), f[l] = find(l + 1), ++cnt;
	return cnt;
}

int n, m, p[N], a[N], s[N], v[N], top, sv, lef[N], rig[N];

int rmain() {
	cin >> n >> m, ns = 0;
	int all = n - 1;
	L(i, 1, n) cin >> a[i], f[i] = i, p[i] = i;

	top = 0;
	L(i, 1, n) {
		++top, s[top] = i, v[top] = a[i];
		L(j, 1, top) v[j] = __gcd(v[j], a[i]);
		sv = 0;
		L(j, 1, top) 
			if(!sv || v[j] != v[sv]) 
				++sv, v[sv] = v[j], s[sv] = s[j];
		top = sv, lef[i] = s[top];
	}

	top = 0;
	R(i, n, 1) {
		++top, s[top] = i, v[top] = a[i];
		L(j, 1, top) v[j] = __gcd(v[j], a[i]);
		sv = 0;
		L(j, 1, top) 
			if(!sv || v[j] != v[sv]) 
				++sv, v[sv] = v[j], s[sv] = s[j];
		top = sv, rig[i] = s[top] - 1;
	}

	sort(p + 1, p + n + 1, [&] (int x, int y) {
		return a[x] < a[y];
	});
	L(i, 1, n) if(lef[p[i]] <= rig[p[i]]) {
		if(a[p[i]] > m) break;
		int t = mk(lef[p[i]], rig[p[i]]);
		ns += (ll) t * a[p[i]], all -= t;
	}
	ns += (ll) all * m;
	cout << ns << "\n";
	return 0;
}
		
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while(T--) rmain();
	return 0;
}