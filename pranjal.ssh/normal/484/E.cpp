#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #include <sys/resource.h>

using namespace std;
using namespace __gnu_pbds;

#define INF 1000000007

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef vector<vector<pair<int, int> > > vvii;


#define TRACE

#ifdef TRACE
template<class T, class U>
ostream& operator<<(ostream& out, const pair<T, U>& a) {out << "[" << a.first << " " << a.second << "]"; return out;}
template<class T>
ostream& operator<<(ostream& out, const vector<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
template<class T>
ostream& operator<<(ostream& out, const set<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
template<class T>
ostream& operator<<(ostream& out, const multiset<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
template<class T, class U>
ostream& operator<<(ostream& out, const map<T, U>& a) {for (auto &it : a)out << it.first << " -> " << it.second << " | "; return out;}
template<class T, class U>
ostream& operator<<(ostream& out, const multimap<T, U>& a) {for (auto &it : a)out << it.first << " -> " << it.second << " | "; return out;}

#define pra(a,n) cerr<<#a<<" : ";for(int i=0;i<n;++i)cerr<<a[i]<<" ";cerr<<endl;
#define praa(a,n,m) cerr<<#a<<" : "<<endl;for(int i=0;i<n;++i){for(int j=0;j<m;++j)cerr<<a[i][j]<<" ";cerr<<endl;}
#define pr(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
#else
#define pr(...)
#define pra(a,n)
#define praa(a,n,m)
#endif

#define inc_stack_limit const rlim_t kStackSize = 64 * 1024 * 1024;struct rlimit rl;rl.rlim_cur = kStackSize;setrlimit(RLIMIT_STACK, &rl);
#define all(x) (x).begin(), (x).end()
#define nall(x) (x).rbegin(), (x).rend()
#define sz(a) int((a).size())
#define pres(s,x) (s.find(x)!=s.end())
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define NFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)

inline int add(int a, int b, int m = INF) {a += b; if (a >= m)a -= m; return a;}
inline int sub(int a, int b, int m = INF) {a -= b; if (a < 0)a += m; return a;}
inline int mul(int a, int b, int m = INF) {return (int)(((ll)a * (ll)b) % m);}

const int N = 1e5 + 10;

int h[N];
vi sh;

template <typename node>
struct PST {
	#define  mid ((l + r) >> 1)

	vector <node> T;
	vector <int> ll, rr;

	PST(int versions) : T(versions + 5) , ll(versions + 5), rr(versions + 5){}	
	// if versions are known beforehand keep them 1...n else manage from outside

	void make_node() {
		T.pb(node()); ll.pb(0); rr.pb(0);
	}

	void link(int no, int pno) {
		T[no] = T[pno], ll[no] = ll[pno], rr[no] = rr[pno];
	}

	void upd(int no, int pno, int l, int r, int index) {
		if (l == r) { 
			T[no].prefix = T[no].suffix = T[no].overall = T[no].full = 1;
		}
		else if (index <= mid) {
			int temp = ll[pno];
			make_node(), ll[no] = sz(T) - 1;
			rr[no] = rr[pno];
			upd(ll[no], temp, l, mid, index);
			T[no] = node::merge(T[ll[no]], T[rr[no]]);
		}
		else {
			int temp = rr[pno];
			make_node(), rr[no] = sz(T) - 1;			
			ll[no] = ll[pno];
			upd(rr[no], temp, mid + 1, r, index);
			T[no] = node::merge(T[ll[no]], T[rr[no]]);
		}
	}

	void debug(int no, int l, int r) {
		pr(no, l, r, T[no].overall, T[no].prefix, T[no].suffix, T[no].full);
		if (l == r) return;
		debug(ll[no], l, mid);
		debug(rr[no], mid + 1, r);
	}

	node qry(int no, int l, int r, int ql, int qr) {
		if (l >= ql and r <= qr) return T[no];

		if (ql > mid) return qry(rr[no], mid + 1, r, ql, qr);
		if (qr <= mid) return qry(ll[no], l, mid, ql, qr);

		return node::merge(qry(ll[no], l, mid, ql, qr), qry(rr[no], mid + 1, r, ql, qr));

	}
	#undef mid
};

struct node {
	int prefix, suffix, overall;
	bool full;
	node () : prefix(0), suffix(0), overall(0), full(0) {}

	static node merge(const node& x, const node& y) {
		node ans;
		ans.prefix = x.prefix, ans.suffix = y.suffix;

		if(x.full) 
			ans.prefix = max(ans.prefix, x.prefix + y.prefix);
		if(y.full)
			ans.suffix = max(ans.suffix, x.suffix + y.suffix);

		ans.overall = max({x.overall, y.overall, x.suffix + y.prefix});
		ans.full = x.full & y.full;

		return ans;
	}
};

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	FOR (i, 1, n) cin >> h[i], sh.pb(h[i]);
	sort(all(sh)), sh.erase(unique(all(sh)), sh.end());

	vi loc[sz(sh)];
	FOR (i, 1, n) loc[lower_bound(all(sh), h[i]) - sh.begin()].pb(i);

	PST<node> T(sz(sh));
	
	FOR (i, 0, sz(sh) - 1) {
		T.link(i + 1, i);
		for(auto it : loc[sz(sh) - 1 - i])
			T.upd(i + 1, i + 1, 1, n, it);
	}
	
	TCASE {
		int l, r, w;
		cin >> l >> r >> w;

		int st = 0;
		int en = sz(sh) - 1;
		while (1) {
			if (st == en) break;
			int mid = (st + en + 1) / 2;
			if (T.qry(sz(sh) - mid, 1, n, l, r).overall >= w)
				st = mid;
			else
				en = mid - 1;
		}
		cout << sh[st] << "\n";
	}

	return 0;	
}