#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
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
template<typename T>
struct BIT1	// Point update,query
{
	vector<T> t;int n;BIT1(){n=0;}
	BIT1(int sz){ n=sz; t=vector<T>(sz+1,0);}
	void upd(int i, T val){ while(i<=n) t[i]=max(t[i], val), i+=i&-i;}
	T qry(int i){T ans=0; while(i>0) ans=max(ans, t[i]),i-=i&-i; return ans;}
};
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	vi a(m), b(m), w(m);
	vector<vi> cmp(n);
	FOR (i, 0, m - 1) {
		cin >> a[i] >> b[i] >> w[i];
		--a[i], --b[i];
		cmp[b[i]].push_back(w[i]);
	}
	vector<BIT1<int>> bt;
	FOR (i, 0, n - 1) {
		sort(all(cmp[i]));
		cmp[i].resize(unique(all(cmp[i])) - cmp[i].begin());
		bt.emplace_back(sz(cmp[i]));
	}

	int ans = 0;
	FOR (i, 0, m - 1) {
		auto it = lower_bound(all(cmp[a[i]]), w[i]);
		int now = 0;
		if (it != cmp[a[i]].begin()) {
			--it;
			now = bt[a[i]].qry(it - cmp[a[i]].begin() + 1);
		}
		it = lower_bound(all(cmp[b[i]]), w[i]);
		ans = max(ans, now + 1);
		bt[b[i]].upd(it - cmp[b[i]].begin() + 1, now + 1);
	}
	cout << ans;

	return 0;
}