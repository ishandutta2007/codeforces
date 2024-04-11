#include <bits/stdc++.h>
using namespace std;

#define cerr cout
#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
string to_string(string s) { return '"' + s + '"';}
string to_string(char s) { return string(1, s);}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A> string to_string(A);
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)


struct ST {
#define mid ((l+r)>>1)
  int n;
  vector<int> T;
  ST(int n): n(n), T(4 * n + 10) {}

  void build(int no, int l, int r, vector<int> &arr) {
    if (l == r) {T[no] = arr[l - 1]; return;}

    build(no << 1, l, mid, arr);
    build(no << 1 | 1, mid + 1, r, arr);
    T[no] = max(T[no << 1], T[no << 1 | 1]);
  }
  void upd(int no, int l, int r, int pos, int val) {
    if (l == r) {/*FUCK*/ T[no] = val; return;}
    if (pos <= mid) upd(no << 1, l, mid, pos, val);
    else upd(no << 1 | 1, mid + 1, r, pos, val);

    T[no] = max(T[no << 1], T[no << 1 | 1]);
  }

  int qry(int no, int l, int r, int u, int v) {
    if (l >= u and r <= v)return T[no];
    if (v <= mid) return qry(no << 1, l, mid, u, v);
    else if (u >= mid + 1) return qry(no << 1 | 1, mid + 1, r, u, v);

    return max(qry(no << 1, l, mid, u, v), qry(no << 1 | 1, mid + 1, r, u, v));
  }

#undef mid
};



int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, k; cin >> n >> k;
	vector<vi> a(n);
	FOR (i, 0, n - 1) {
		a[i].resize(k);
		for (int &j: a[i]) cin >> j;
	}
	vector<ST> T(1 << k, n);
	vi b(n);
	FOR (mask, 0, (1 << k) - 1) {
		FOR (i, 0, n - 1) {
			b[i] = 0;
			FOR (j, 0, k - 1) {
				b[i] += ((mask & (1 << j)) ? a[i][j] : -a[i][j]);
			}
		}
		T[mask].build(1, 1, n, b);
	}
	b.resize(k);
	vi c(1 << k); int SAB = (1 << k) - 1;
	int q; cin >> q; while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int ind; cin >> ind;
			FOR (i, 0, k - 1) cin >> b[i];
			FOR (mask, 0, (1 << k) - 1) {
				int val = 0;
				FOR (j, 0, k - 1) {
					val += ((mask & (1 << j)) ? b[j] : -b[j]);
				}
				T[mask].upd(1, 1, n, ind, val);
			}
		} else {
			int l, r; cin >> l >> r;
			FOR (mask, 0, (1 << k) - 1) {
				c[mask] = T[mask].qry(1, 1, n, l, r);
			}
			int ans = 0;
			FOR (mask, 0, (1 << k) - 1) {
				ans = max(ans, c[mask] + c[mask ^ SAB]);
			}
			cout << ans << "\n";
		}
	}
	
	return 0;
}