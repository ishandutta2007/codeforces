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

const int N = 1e5 + 10;
int a[N];

const int mod = 95542721;
template<class node>
struct ST {
#define mid ((l+r)>>1)
	int n;
	vector<node> T;
	ST(int n): n(n), T(4 * n + 10) {}

	inline void resolve(int no, int l, int r) {
		T[no].lazy %= 48;
		if (T[no].lazy == 0) return;

		reverse(T[no].sum, T[no].sum + T[no].lazy);
		reverse(T[no].sum + T[no].lazy, T[no].sum + 48);
		reverse(T[no].sum, T[no].sum + 48);

		if (l != r) {
			T[no << 1].lazy += T[no].lazy ;
			T[no << 1 | 1].lazy += T[no].lazy ;
		}
		T[no].lazy = 0;
	}
	void build(int no, int l, int r) {
		if (l == r) {
			T[no].sum[0]=a[l];
			FOR (i, 1, 47) {
				T[no].sum[i] = (T[no].sum[i-1]*1LL*T[no].sum[i-1])%mod;
				T[no].sum[i] = (T[no].sum[i]*1LL*T[no].sum[i-1])%mod;
			}			
			return;
		}
		build(no << 1, l, mid), build(no << 1 | 1, mid + 1, r);
		T[no] = T[no << 1] + T[no << 1 | 1];
	}

	node qry(int no, int l, int r, int u, int v) {
		resolve(no, l, r);

		if (l >= u and r <= v)return T[no];
		if (v <= mid) {if (l != r)resolve(no << 1 | 1, mid + 1, r); return qry(no << 1, l, mid, u, v);}
		else if (u >= mid + 1) {if (l != r)resolve(no << 1, l, mid); return qry(no << 1 | 1, mid + 1, r, u, v);}

		return qry(no << 1, l, mid, u, v) + qry(no << 1 | 1, mid + 1, r, u, v);
	}

	void updr(int no, int l, int r, int u, int v) {
		resolve(no, l, r);

		if (l >= u and r <= v) {T[no].lazy++; resolve(no, l, r); return;}
		if (r < u or l > v) return;

		updr(no << 1, l, mid, u, v), updr(no << 1 | 1, mid + 1, r, u, v);
		T[no] = T[no << 1] + T[no << 1 | 1];
	}
#undef mid
};


struct node {
	int sum[48];
	int lazy;
	node(int lazy = 0): lazy(lazy) {memset(sum,0,sizeof sum);}
	node operator +(const node&rhs) {
		node ans;
		FOR (i, 0, 47) {
			ans.sum[i] = sum[i] + rhs.sum[i];
			if (ans.sum[i] >= mod) ans.sum[i] -= mod;
		}
		return ans;
	}
};

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n; FOR (i, 1, n) cin >> a[i], a[i] %= mod;
	ST<node> T(n); T.build(1, 1, n);

	int t; cin >> t; while (t--) {
		int q, l, r; cin >> q >> l >> r;
		if (q == 2) {
			T.updr(1, 1, n, l, r);
		} else {
			cout << T.qry(1, 1, n, l, r).sum[0] << "\n";
		}
	}

	return 0;
}