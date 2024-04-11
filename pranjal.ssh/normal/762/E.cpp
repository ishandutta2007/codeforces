#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())

typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
typedef int __T; typedef tree<__T, null_type, less<__T>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}

template<typename T>
struct BIT1	// Point update,query
{
	vector<T> t;int n;BIT1(){n=0;}
	BIT1(int sz){ n=sz; t=vector<T>(sz+1,0);}
	void upd(int i, T val){ while(i<=n) t[i]+=val, i+=i&-i;}
	T qry(int i){T ans=0; while(i>0) ans+=t[i],i-=i&-i; return ans;}
};

struct station {
	int x, r, f;
	int left, right;
};
const int ff = 1e4;
vi F[ff + 1];


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, k; cin >> n >> k;
	vector<station> a(n);
	vi cmp;
	FOR (i, 0, n - 1) {
		cin >> a[i].x >> a[i].r >> a[i].f;
		F[a[i].f].push_back(i);
		cmp.push_back(a[i].x);
		cmp.push_back(a[i].x+a[i].r);
		cmp.push_back(a[i].x-a[i].r);
	}
	sort(all(cmp)); cmp.erase(unique(all(cmp)), cmp.end());
	FOR (i, 0, n - 1) {
		a[i].left = lower_bound(all(cmp), a[i].x - a[i].r) - cmp.begin() + 1;
		a[i].right = lower_bound(all(cmp), a[i].x + a[i].r) - cmp.begin() + 1;
		a[i].x = lower_bound(all(cmp), a[i].x) - cmp.begin() + 1;
	}

	FOR (i, 1, ff) sort(all(F[i]), [&](const int& x, const int& y) {
		return a[x].r > a[y].r;
	});

	BIT1<int> bt(sz(cmp) + 10);
	ll ans = 0;
	vector<ll> internal(ff + 1);
	FOR (diff, 0, k) {
		FOR (i, 1, ff) {
			int j = i + diff;
			if (j > ff) break;
			vi yo;
			if (diff)
				merge(all(F[i]), all(F[j]), back_inserter(yo), [&](const int& x, const int& y) {
					return a[x].r > a[y].r;
				});
			else
				yo = F[i];
			ll now = 0;	
			for (int it : yo) {
				now += bt.qry(a[it].right);
				now -= bt.qry(a[it].left - 1);
				bt.upd(a[it].x, 1);
			}
			if (diff == 0)
				internal[i] = now;
			else
				now -= internal[i] + internal[j];
			ans += now;
			for (int it : yo) {
				bt.upd(a[it].x, -1);
			}
		}
	}
	
	cout << ans << "\n";

	return 0;
}