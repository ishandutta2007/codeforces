#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
string to_string(string s) { return '"' + s + '"';}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <class A, class B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <class A>string to_string(A v) {int f = 1; string r("{"); for (auto x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cout << endl; }
template <class Head, class... Tail> void debug_out(Head H, Tail... T) {cout << " " << to_string(H); debug_out(T...);}
#define pr(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

struct node {
	int l, r, count;
	ll sum, ans;
	node(int l = 0, int r = 0, int count = 0, ll sum = 0, ll ans = 0): l(l), r(r), count(count), sum(sum), ans(ans) {}
};


vector<node> T(1);
int n;
map<int, int> mp;
ll ans = 0;

int make_node() {
	T.emplace_back();
	return sz(T) - 1;
}



int upd(int no, int l, int r, int b) {
	T[no].count += 1;
	T[no].sum += b;
	if (l == r) {
		return no;
	}
	int m = (l + r) / 2;
	if (b <= m) {
		int bc = upd(make_node(), l, m, b);
		T[no].l = bc;
	} else {
		int bc = upd(make_node(), m + 1, r, b);
		T[no].r = bc;
	}
	return no;
}

int merge(int x, int y, int l, int r) {
	if (!x or !y) {
		return x ^ y;
	}
	int m = (l + r) / 2;
	assert(l != r);
	ans += T[T[x].r].count * T[T[y].l].sum;
	ans += T[T[y].r].count * T[T[x].l].sum;
	int bc = merge(T[x].l, T[y].l, l, m);
	T[x].l = bc;
	bc = merge(T[x].r, T[y].r, m + 1, r);
	T[x].r = bc;
	T[x].sum = T[T[x].l].sum + T[T[x].r].sum;
	T[x].count = T[T[x].l].count + T[T[x].r].count;
	return x;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	map<int, int> mp;
	mp[-1] = 0;
	mp[1e9] = 0;
	cin >> n; FOR (_, 1, n) {
		int a, b; cin >> a >> b;
		auto it = --mp.upper_bound(a);
		int c = make_node();
		c = upd(c, 1, n, b);
		int L = it->F + T[it->S].count;
		int pos = a;
		if (L >= a) {
			ans -= (a - it->F) * 1LL * b;
			c = merge(it->S, c, 1, n);
			pos = it->F;			
		}
		mp[pos] = c;
		it = --mp.upper_bound(a);
		L = it->F + T[it->S].count;
		auto it2 = it; ++it2;
		if (L >= it2->F) {
			ans -= (it2->F - it->F) * T[it2->S].sum;
			c = merge(c, it2->S, 1, n);
			mp.erase(it2->F);
		}
		mp[pos] = c;
		cout << ans << "\n";
	}

	return 0;
}