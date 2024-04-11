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
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}


typedef double T;
struct PT {
	pair<T, T> pt;
	int id;
	PT() {}
	PT(T m, T c, int id = -1): pt(m, c), id(id) {}
};
bool complee(const pair<T, T>& a, const pair<T, T>& b) {return a.F * b.S <= a.S * b.F;}
struct CHT {  // maintains min envelope

	vector<PT> info;

	vector<int> pts;   // stack of points on which ans changes
	vector<int> st; // stack of envelope
	int ptr;
	CHT(): ptr(0) {}

	void insert(PT x) { // add in desc. order of slope
		if (st.empty()) {
			info.push_back(x);
			st.push_back(sz(info) - 1);
			info.emplace_back(0, 1);
			pts.push_back(sz(info) - 1); // +ve queries
			return;
		}
		pair<T, T> now(x.pt.S - info[st.back()].pt.S, info[st.back()].pt.F - x.pt.F); //+ve denom as desc slope

		if (complee(now, info[pts.back()].pt)) {
			pts.pop_back(); st.pop_back();
			if (ptr == pts.size()) --ptr;
			insert(x);
		} else {
			info.push_back(x);
			st.push_back(sz(info) - 1);
			info.emplace_back(now.F, now.S);
			pts.push_back(sz(info) - 1);
		}
	}
	pair<T, int> query(T x) {
		pair<T, T> yo(x, 1);
		if (ptr >= sz(pts))
			ptr = sz(pts) - 1;
		
		while (ptr < sz(pts) - 1 and 
			info[st[ptr + 1]].pt.F*x + info[st[ptr + 1]].pt.S < info[st[ptr]].pt.F*x + info[st[ptr]].pt.S)
			ptr++;

		return {info[st[ptr]].pt.F * x + info[st[ptr]].pt.S, info[st[ptr]].id};
	}
};

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, k; cin >> n >> k;
	vector<double> t(n + 1); FOR (i, 1, n) cin >> t[i];
	vector<double> p(n + 1); FOR (i, 1, n) p[i] = p[i - 1] + t[i];
	vector<double> pt(n + 1); FOR (i, 1, n) pt[i] = pt[i - 1] + (p[i] + .0L) / t[i];
	vector<double> T(n + 1); FOR (i, 1, n) T[i] = T[i - 1] + (1 + .0L) / t[i];

	double st = 0, en = 1e15;

	while (1) {
		double mid = (st + en) / 2;
		vector<double> dp(n + 1);
		vector<int> par(n + 1);
		CHT cht;
		cht.insert(PT(0, 0, 0));
		FOR (i, 1, n) {
			auto it = cht.query(T[i]);
			dp[i] = it.F + mid + pt[i];
			par[i] = it.S;
			cht.insert(PT(-p[i], dp[i] - pt[i] + p[i]*T[i], i));
		}
		int ctr = 0;
		int id = n;
		while (id) id = par[id], ++ctr;
		if (ctr < k) en = mid;
		else if (ctr > k) st = mid;
		else {
			cout << fixed << setprecision(10) << dp[n] - k*mid << "\n";
			FOR (i, 0, sz(cht.pts) - 2)assert(complee(cht.info[cht.pts[i]].pt,cht.info[cht.pts[i+1]].pt));
			return 0;
		}
	}


	return 0;
}