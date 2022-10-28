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

struct node {
	int nxt[2];
	int f;
	node() {
		nxt[0] = nxt[1] = f = 0;
	}
};

vector<node> T(1);
void ins (int cur, int pos, int num) {
	++T[cur].f;
	if (pos == -1) return;
	int b = ((num >> pos) & 1);
	if (!T[cur].nxt[b]) T[cur].nxt[b] = sz(T), T.emplace_back();
	ins(T[cur].nxt[b], pos - 1, num);
}
void del (int cur, int pos, int num) {
	--T[cur].f;
	if (pos == -1) return;
	int b = ((num >> pos) & 1);
	del(T[cur].nxt[b], pos - 1, num);
}

int qry(int cur, int pos, int num) {
	if (pos == -1) return num;
	int b = ((num >> pos) & 1);
	if (T[cur].nxt[b] && T[T[cur].nxt[b]].f) return qry(T[cur].nxt[b], pos - 1, num & ((~0) ^ (1 << pos)));
	return qry(T[cur].nxt[!b], pos - 1, num | (1 << pos));
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	vi a(n);
	FOR (i, 0, n - 1) cin >> a[i];
	sort(all(a));
	n = unique(all(a)) - a.begin();
	a.resize(n);

	FOR (i, 1, n - 1) ins(0, 30, a[i]);
	
	set<pair<int, int>> st;
	set<int> vis;
	st.insert({qry(0, 30, a[0]), a[0]});
	vis.insert(a[0]);
	ll ans = 0;
	FOR (_, 1, n - 1) {
		auto it = *st.begin();
		st.erase(st.begin());
		it.F ^= it.S; swap(it.F, it.S);
		if (vis.count(it.S)) {
			st.insert({qry(0, 30, it.F), it.F});
			--_;
			continue;
		}
		vis.insert(it.S);
		del(0, 30, it.S);
		ans += (it.F ^ it.S);
		st.insert({qry(0, 30, it.F), it.F});
		st.insert({qry(0, 30, it.S), it.S});
	}
	cout << ans;

	return 0;
}