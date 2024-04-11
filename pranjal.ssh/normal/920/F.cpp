#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cout << str << " : " << t << endl;}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]";cout<<endl;}

const int N = 3e5;
const int NN = 1e6;
ll T[4*N + 10];
bool D[4*N+10];
int d[NN + 1], a[N + 1];

#define mid ((l+r)>>1)
#define L (no<<1)
#define R (no<<1|1)

void build(int no, int l, int r) {
	if (l == r) {
		T[no] = a[l];
		D[no] = (a[l] <= 2);
		return;
	}
	build(L, l, mid), build(R, mid+1, r);
	T[no] = T[L] + T[R];
	D[no] = D[L] and D[R];
}

void upd(int no, int l, int r, int u, int v) {
	if (D[no]) return;
	if (r < u or l > v) return;
	if (l == r) {
		a[l] = d[a[l]];
		T[no] = a[l];
		D[no] = (a[l] <= 2);
		return;
	}
	upd(L, l, mid, u, v), upd(R, mid+1, r, u, v);
	T[no] = T[L] + T[R];
	D[no] = D[L] and D[R];
}


ll qry(int no, int l, int r, int u, int v) {
	if (r < u or l > v) return 0;
	if (l >= u and r <= v) return T[no];
	return qry(L, l, mid, u, v) + qry(R, mid+1, r, u, v);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	FOR (i, 1, NN) for (int j = i; j <= NN; j += i) d[j]++;

	int n, m; cin >> n >> m;
	FOR (i, 1, n) cin >> a[i];
	build(1, 1, n);

	while (m--) {
		int t, l, r; cin >> t >> l >> r;
		if (t == 1) {
			upd(1, 1, n, l, r);
		} else {
			cout << qry(1, 1, n, l, r) << "\n";
		}
	}

	return 0;
}