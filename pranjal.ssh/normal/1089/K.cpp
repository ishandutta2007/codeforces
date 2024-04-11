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
string to_string(char s) { return string(1, s);}
string to_string(string s) { return '"' + s + '"';}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A> string to_string(A);
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (auto it = v.begin(); it != v.end(); ++it) {if (!f)r += ", "; f = 0; r += to_string(*it);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

struct node {
	ll st, en, ff;
	node(ll st = 0, ll en = 0, ll ff = 0):st(st), en(en), ff(ff) {}
	node operator+(const node& rhs) {
		if (st == 0) return rhs;
		if (rhs.st == 0) return *this;

		if (en - rhs.st <= rhs.ff) {
			return node(st, rhs.en, ff + rhs.ff + (rhs.st - en));
		} else {
			return node(st, rhs.en + en - rhs.st - rhs.ff, ff);
		}
	}
};
vector<node> T;
const int N = 1e6 + 10;
int a[N];
#define mid ((l+r)>>1)
void upd(int no, int l, int r, int pos, int val) {
	if (l == r) {
		T[no] = node(l, l + val, 0);
		return;
	}
	if (pos <= mid) upd(2*no, l, mid, pos, val);
	else upd(2*no+1, mid+1, r, pos, val);
	T[no] = T[2*no] + T[2*no+1];
}

node qry(int no, int l, int r, int u, int v) {
	if (r < u or l > v) return node();
	if (l >= u and r <= v) return T[no];
	return qry(2*no, l, mid, u, v) + qry(2*no+1, mid+1, r, u, v);
}


int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	T.resize(4*N + 10);
	int q; cin >> q; FOR (it, 1, q) {
		char ch; cin >> ch;
		if (ch == '?') {
			ll t; cin >> t;
			cout << max(qry(1, 1, N, 1, t).en-t, 0LL) << "\n";
		} else if (ch == '+') {
			ll t, d; cin >> t >> d;
			a[it] = t;
			upd(1,1,N,t,d);
		} else {
			ll i; cin >> i;
			upd(1,1,N,a[i],0);
		}
	}

	return 0;
}