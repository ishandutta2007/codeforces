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
const int mod = 998244353;
template<class node>
struct ST {
#define mid ((l+r)>>1)
	int n;
	vector<node> T;
	ST(int n): n(n), T(4 * n + 10) {}

	inline void resolve(int no, int l, int r) {
		/*FUCK*/
		int a = T[no].a, b = T[no].b;
		T[no].sum = (T[no].sum*1LL*a + b*(r-l+1LL)) % mod;;
		if (l != r) {
			T[no << 1].a = (T[no << 1].a * 1LL * T[no].a) % mod;
			T[no << 1].b = (T[no << 1].b * 1LL * T[no].a + T[no].b) % mod;

			T[no << 1 | 1].a = (T[no << 1 | 1].a * 1LL * T[no].a) % mod;
			T[no << 1 | 1].b = (T[no << 1 | 1].b * 1LL * T[no].a + T[no].b) % mod;
		}
		T[no].a = 1, T[no].b = 0;
	}

	node qry(int no, int l, int r, int u, int v) {
		resolve(no, l, r);

		if (l >= u and r <= v)return T[no];
		if (v <= mid) {if (l != r)resolve(no << 1 | 1, mid + 1, r); return qry(no << 1, l, mid, u, v);}
		else if (u >= mid + 1) {if (l != r)resolve(no << 1, l, mid); return qry(no << 1 | 1, mid + 1, r, u, v);}

		return qry(no << 1, l, mid, u, v) + qry(no << 1 | 1, mid + 1, r, u, v);
	}

	void updr(int no, int l, int r, int u, int v, int val) {
		if (l > r) return;
		resolve(no, l, r);

		if (l >= u and r <= v) {
			if (val) T[no].a = 2;
			else T[no].b = 1;
			resolve(no, l, r); return;
		}
		if (r < u or l > v) return;

		updr(no << 1, l, mid, u, v, val), updr(no << 1 | 1, mid + 1, r, u, v, val);
		T[no] = T[no << 1] + T[no << 1 | 1];
	}
#undef mid
};


struct node {
	/*FUCK*/
	int sum, a, b;
	node(int sum = 0, int a = 1, int b = 0): sum(sum), a(a), b(b) {}
	node operator +(const node&rhs) {
		node ans(rhs.sum + sum);
		if (ans.sum >= mod) ans.sum -= mod;
		return ans;
	}
};

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, q; cin >> n >> q;
	vector<map<int, int>> mp(n+1);
	FOR (i, 1, n) mp[i][n+1] = n+1, mp[i][0] = 0;
	ST<node> T(n);

	while (q--) {
		int t, l, r, x; cin >> t >> l >> r;
		if (t == 1) {
			cin >> x;
			auto it = mp[x].upper_bound(l);
			--it;
			if (it->S < l) ++it;
			vector<int> rem;
			if (it->F <= l and it->S >= r) {
				T.updr(1, 1, n, l, r, 1);
				continue;
			}
			int mn = l, mx = r;
			while (it->F <= r) {
				mn = min(mn, it->F);
				mx = max(mx, it->S);
				rem.push_back(it->F);
				if (it->F < l) {
					T.updr(1, 1, n, l, min(it->S, r), 1);
					l = min(it->S, r) + 1;
				} else {
					T.updr(1, 1, n, l, it->F - 1, 0);
					T.updr(1, 1, n, it->F, min(it->S, r), 1);
					l = min(it->S, r) + 1;
				}
				++it;
			}
			if (l <= r) T.updr(1, 1, n, l, r, 0);
			for (int it : rem) mp[x].erase(it);
			mp[x][mn] = mx;
		} else {
			cout << T.qry(1, 1, n, l, r).sum << "\n";
		}
	}

	return 0;
}