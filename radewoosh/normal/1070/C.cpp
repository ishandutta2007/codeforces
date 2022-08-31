# include <bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
#define sim template <class c
#define dor >debug & operator<< (
#define ris return *this
#define eni(r) sim> typename enable_if<sizeof(dud<c>(0)) r 1, debug &>::type operator<< (c i) {
sim> struct rge {c b, e;};
sim> rge<c> range(c i, c j) {return rge<c>{i, j};}
sim> auto dud(c * x) -> decltype(cerr << *x, 2);
sim> char dud(...);
struct debug {
#ifdef LOCAL
~debug() {cerr << endl;}
eni(==) ris << range(begin(i), end(i));}
eni(!=) cerr << i; ris;}
sim dor rge<c> x) {
	cerr << "[";
	for (c it = x.b; it != x.e; ++it)
		*this << ", " + 2 * (x.b == it) << *it;
	ris << "]";
}
sim, class b dor pair <c,b> x) {ris << "(" << x.first << ", " << x.second << ")";}
#else
sim dor const c&) {ris;}
#endif
};
#define imie(r) "[" #r ": " << (r) << "] "
#define imask(r) "[" #r ": " << bitset<8 * sizeof(r)>(r) << "] "
#define arr(a, i) "[" #a imie(i) << ": " << a[i] << "] " 
#define arr2(a, i, j) "[" #a imie(i) imie(j) << ": " << a[i][j] << "] " 
#define debug debug() << __FUNCTION__ << "#" << __LINE__ << ": "
const int MN = 1 << 20;
#define remove __remove__retho
vector <pair <int, int> > add[MN], remove[MN];
using ll = long long;
pair <ll, ll> tree[MN * 2]; //ile, koszt
void put(int val, int cou) {
	int pos = val + MN;
	while (pos > 0) {
		tree[pos].first += cou;
		tree[pos].second += cou * 1ll * val;
		pos /= 2;
	}
}
ll get(int cou) {
	int node = 1;
	ll ans = 0;
	while (node < MN) {
		if (tree[node * 2].first >= cou)
			node *= 2;
		else {
			ans += tree[node * 2].second;
			cou -= tree[node * 2].first;
			node = 2 * node + 1;
		}
	}
	int left = node - MN;
	debug << imie(left);
	ans += left * 1ll * cou;
	return ans;
}
int main() {
	int n, k, m;
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 0; i < m; ++i) {
		int l, r, p, c;
		scanf("%d%d%d%d", &l, &r, &c, &p);
		add[l].emplace_back(p, c);
		remove[r].emplace_back(p, c);
	}
	ll ans = 0;
	ll in = 0;
	for (int i = 1; i <= n; ++i) {
		for (auto x : add[i]) {
			put(x.first, x.second);
			in += x.second;
		}
		ans += get(min((ll)k, in));
		for (auto x : remove[i]) {
			put(x.first, -x.second);
			in -= x.second;
		}
	}
	printf("%lld\n", ans);
}