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

template<class node>
struct ST {
#define mid ((l+r)>>1)
  int n;
  vector<node> T;
  ST(int n): n(n), T(4 * n + 10) {}

  void qry(int no, int l, int r, int u, int v, int val) {
    if (l >= u and r <= v) {
    	T[no].a.emplace_back(val);
    	return;
    }
    if (v <= mid) return qry(no << 1, l, mid, u, v, val);
    else if (u >= mid + 1) return qry(no << 1 | 1, mid + 1, r, u, v, val);

    qry(no << 1, l, mid, u, v, val), qry(no << 1 | 1, mid + 1, r, u, v, val);
    return;
  }

  bitset<10001> solve(int no, int l, int r) {
  	if (l != r) {
  		bitset<10001> L = solve(no<<1, l, mid);
  		bitset<10001> R = solve(no<<1|1, mid+1, r);
  		for (int it : T[no].a) {
  			L |= (L << it);
  			R |= (R << it);
  		}
  		return L | R;
  	}
  	bitset<10001> ans;
  	ans[0] = 1;
  	for (int it : T[no].a) {
  		ans |= (ans << it);
  	}
  	return ans;
  }

#undef mid
};

struct node {
  /*FUCK*/
  vector<int> a;
};

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, q;
	cin >> n >> q;
	ST<node> T(n);
	FOR (i, 0, q - 1) {
		int l, r, x;
		cin >> l >> r >> x;
		T.qry(1, 1, n, l, r, x);
	}
	auto ans = T.solve(1, 1, n);
	int sum = 0;
	FOR (i, 1, n) sum += ans[i];
	cout << sum << "\n";
	FOR (i, 1, n) if (ans[i]) cout << i << " ";

	return 0;
}