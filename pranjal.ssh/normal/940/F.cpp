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



struct Upd {
	int t;
	int pos, from, to;
	Upd() {}
	Upd(int t, int pos, int from, int to): t(t), pos(pos), from(from), to(to) {}
};
struct Qry {
	int t;
	int l, r;
	int ans;
	Qry() {}
	Qry(int t, int l, int r) : t(t), l(l), r(r), ans(0) {}
};

const int N = 2e5 + 10;
int f[N], nf[N];
vi a;
vector<Upd> upd;
vector<Qry> qry;
const int K = 2000;
int L = 0, R = 0, uptr = 0;

inline void update(int id) {
	auto &it = upd[id];
	if (it.pos >= L and it.pos <= R) {
		nf[f[it.from]]--;
		f[it.from]--;
		nf[f[it.from]]++;

		nf[f[it.to]]--;
		f[it.to]++;
		nf[f[it.to]]++;
	}
	a[it.pos] = it.to;
}

inline void roll_back(int id) {
	auto &it = upd[id];
	if (it.pos >= L and it.pos <= R) {
		nf[f[it.from]]--;
		f[it.from]++;
		nf[f[it.from]]++;

		nf[f[it.to]]--;
		f[it.to]--;
		nf[f[it.to]]++;
	}

	a[it.pos] = it.from;
}

inline void insert(int id) {
	nf[f[a[id]]]--;
	f[a[id]]++;
	nf[f[a[id]]]++;
}

inline void remove(int id) {
	nf[f[a[id]]]--;
	f[a[id]]--;
	nf[f[a[id]]]++;
}


inline void query(int id) {
	int &ans = qry[id].ans;
	ans = 1;
	while (nf[ans]) {
		++ans;
	}
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, q; cin >> n >> q;
	vi cmp(n); a.resize(n);
	FOR (i, 0, n - 1) cin >> a[i], cmp[i] = a[i];

	FOR (i, 0, q - 1) {
		int t, x, y; cin >> t >> x >> y;
		if (t == 1) qry.emplace_back(i, x - 1, y - 1);
		else {
			cmp.push_back(y);
			upd.emplace_back(i, x - 1, 0, y);
		}
	}


	sort(all(cmp)), cmp.resize(unique(all(cmp)) - cmp.begin());
	FOR (i, 0, n - 1) a[i] = lower_bound(all(cmp), a[i]) - cmp.begin();

	vi b = a;
	for (auto &it : upd) {
		it.from = b[it.pos];
		it.to = lower_bound(all(cmp), it.to) - cmp.begin();
		b[it.pos] = it.to;
	}

	sort(all(qry), [](const Qry& x, const Qry &y) {
		if (x.l/K != y.l/K) return x.l/K < y.l/K;
		if (x.r/K != y.r/K) return x.r/K < y.r/K;
		return x.t < y.t;
	});


	
	f[a[0]]++;
	nf[1]++;

	FOR (qid, 0, sz(qry) - 1) {
		Qry &it = qry[qid];
		while (uptr < sz(upd) and upd[uptr].t < it.t) {
			update(uptr);
			++uptr;
		}

		while (uptr >= 1 and upd[uptr-1].t > it.t) {
			--uptr;
			roll_back(uptr);
		}
		while (R < it.r) {
			++R;
			insert(R);
		}

		while (L > it.l) {
			--L;
			insert(L);
		}

		while (R > it.r) {
			remove(R);
			--R;
		}

		while (L < it.l) {
			remove(L);
			++L;
		}

		query(qid);
	}


	sort(all(qry), [](const Qry &x, const Qry &y) {
		return x.t < y.t;
	});

	for (auto it : qry) {
		cout << it.ans << "\n";
	}


	return 0;
}