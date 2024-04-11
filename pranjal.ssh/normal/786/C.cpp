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
template <class T> void dbs(string str, T t) {cout << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]\n";}

const int N = 1e5 + 10;
int a[N], prv[N], pos[N], ans[N];
vi q[N];
int s[4*N];

#define mid ((l + r) >> 1)
#define L (no << 1)
#define R (no << 1 | 1)
void upd(int no, int l, int r, int pos, int val) {
	if (l == r) return void(s[no] = val);
	if (pos <= mid) upd(L, l, mid, pos, val);
	else upd(R, mid + 1, r, pos, val);
	s[no] = s[L] + s[R];
}
int qry(int no, int l, int r, int k) {
	if (l == r) return s[no] <= k;
	if (s[R] <= k) return r - mid + qry(L, l, mid, k - s[R]);
	return qry(R, mid + 1, r, k);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	FOR (i, 1, n) {
		cin >> a[i];
		prv[i] = pos[a[i]];
		pos[a[i]] = i;
	}
	FOR (i, 1, n) {
		if (pos[a[i]] == i) {
			upd(1, 1, n, i, 1);
		}
		q[n].push_back(i);
	}

	NFOR (i, n, 1) {
		for (int it: q[i]) {
			ans[it]++;
			int x = qry(1, 1, n, it) - (n - i);
			q[i - x].push_back(it);
		}
		if (prv[i])
			upd(1, 1, n, prv[i], 1);
		upd(1, 1, n, i, 0);
	}
	FOR (i, 1, n) cout << ans[i] << "\n";

	return 0;
}