#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cout << str << " : " << t << endl;}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]"; cout << endl;}

vector<int> L, R;
inline int make() {
	L.emplace_back(); R.emplace_back();
	return sz(L) - 1;
}
const int N = 2e5 + 10;
int a[N];
int mp[101];

ii upd(int nox, int noy, int l, int r, int u, int v) {
	// pr(nox,noy,l,r,u,v);
	int mid = (l + r) >> 1;
	if (l >= u and r <= v) {
		if (!nox) return {0, noy};
		if (!noy) return {0, nox};
		ii ll = upd(L[nox], L[noy], l, mid, u, v);
		ii rr = upd(R[nox], R[noy], mid + 1, r, u, v);
		L[nox] = ll.F, L[noy] = ll.S;
		R[nox] = rr.F, R[noy] = rr.S;
		return {0, noy};
	}
	if (l > v or r < u) return {nox, noy};
	if (!nox) return {0, noy};

	ii ll = upd(L[nox], L[noy], l, mid, u, v);
	ii rr = upd(R[nox], R[noy], mid + 1, r, u, v);
	if ((ll.S or rr.S) and !noy) noy = make();
	L[nox] = ll.F, L[noy] = ll.S;
	R[nox] = rr.F, R[noy] = rr.S;
	if (L[nox] == 0 and R[nox] == 0) nox = 0;
	
	return {nox, noy};
}

void dfs(int val, int no, int l, int r) {
	// pr(val,no,l,r);
	int mid = (l + r) >> 1;
	if (!no) return;
	if (l == r) {
		a[l] = val;
		return;
	}
	dfs(val, L[no], l, mid);
	dfs(val, R[no], mid + 1, r);

}

int add(int no, int l, int r, int pos) {
	int mid = ((l + r) >> 1);
	if (pos < l or pos > r) return no;
	if (!no) no = make();
	if (l == r) return no;
	int ll = add(L[no], l, mid, pos);
	int rr = add(R[no], mid + 1, r, pos);
	L[no] = ll, R[no] = rr;
	// pr(no,l,r,pos,ll,rr);
	return no;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	make();
	int n; cin >> n;
	L.reserve(1e6), R.reserve(1e6);
	FOR (i, 1, n) {
		cin >> a[i];
		mp[a[i]] = add(mp[a[i]], 1, n, i);
	}


	int q; cin >> q; while (q--) {
		int l, r, x, y; cin >> l >> r >> x >> y;
		if (x ^ y) {
			ii yo = upd(mp[x], mp[y], 1, n, l, r);
			mp[x] = yo.F, mp[y] = yo.S;
		}
	}

	FOR (i, 1, 100) {
		dfs(i, mp[i], 1, n);
	}
	FOR (i, 1, n) {
		cout << a[i] << " ";
	}

	return 0;
}