// 040C 033F
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = (1 << 12) + 7, _B = (1 << 8) + 7;
int n, q, B, cB, a[N], mp[N], l[N], r[N], tot, ns[1 << 17];
struct node {
	vi p, vc[_B];
	int getid (int l, int r) {
		auto cl = lower_bound (p.begin(), p.end(), l), cr = upper_bound (p.begin(), p.end(), r);
		if(cl == p.end() || cr == p.begin()) 
			return 0;
		return vc[cl - p.begin()][cr - p.begin() - 1];
	}
} ;
int wl[1 << 22], wr[1 << 22], ztp;
int nw (int x, int y) { 
	if(!x || !y) return x + y;
	return ++ztp, wl[ztp] = x, wr[ztp] = y, ++tot; 
}
node emp (int x) { 
	node r;
	r.p.push_back(x), r.vc[0].resize(1), r.vc[0][0] = x;
	return r; 
}
node build (int l, int r) {
	if(l == r) return emp (mp[l]);
	int mid = (l + r) >> 1;
	node u = build (l, mid), v = build (mid + 1, r), ns;
	L(i, 0, sz(u.p) - 1) ns.p.push_back(u.p[i]);
	L(i, 0, sz(v.p) - 1) ns.p.push_back(v.p[i]);
	sort(ns.p.begin(), ns.p.end());
	L(i, 0, sz(ns.p) - 1) ns.vc[i].resize(r - l + 1);
	L(i, 0, sz(ns.p) - 1) L(j, i, sz(ns.p) - 1) 
		ns.vc[i][j] = nw (u.getid(ns.p[i], ns.p[j]), v.getid(ns.p[i], ns.p[j]));
	return ns;
}

vector < node > S; 

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> q, B = sqrt (q), B += B * B != q, B = min(B, n), tot = n;
	L(i, 1, n) cin >> a[i], mp[a[i]] = i;
	cB = (n + B - 1) / B;
	L(i, 0, cB - 1) {
		l[i] = i * B + 1, r[i] = min((i + 1) * B, n);
		S.push_back(build (l[i], r[i]));
	}
	L(t, 1, q) {
		int l, r;
		cin >> l >> r;
		L(i, 0, cB - 1) ns[t] = nw (ns[t], S[i].getid(l, r));
	}
	cout << tot << "\n";
	L(i, 1, ztp) cout << wl[i] << ' ' << wr[i] << '\n';
	L(t, 1, q) cout << ns[t] << ' ';
	return 0;
}