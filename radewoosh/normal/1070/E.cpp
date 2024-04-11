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
using ll = long long;
#ifdef LOCAL
const int MN = 1 << 4;
#else
const int MN = 1 << 18;
#endif
pair <int, ll> tree[MN * 2];
void add(int pos, int val) {
	debug << imie(pos) imie(val);
	pos += MN;
	while (pos > 0) {
		tree[pos].first++;
		tree[pos].second += val;
		pos /= 2;
	}
}
void clear(int n) {
	for (int i = MN; i > 0; i /= 2)
		for (int k = 0; k <= n; ++k)
			tree[i + k] = make_pair(0, 0ll);
}
ll first_sum(int cou) {
	debug << imie(cou);
	int node = 1;
	long long ans = 0;
	while (node < MN) {
		debug << arr(tree, node * 2) arr(tree, node * 2 + 1);
		if (tree[node * 2].first > cou)
			node *= 2;
		else {
			ans += tree[node * 2].second;
			cou -= tree[node * 2].first;
			node = 2 * node + 1;
		}
	}
	if (cou > 0) {
		debug << imie(cou);
		assert(cou == 1);
		ans += tree[node].second;
	}
	debug << imie(ans);
	return ans;
}
int how_many(int m, long long t) {
	int tasks = 0;
	long long dur = 0;
	int node = 1;
	while (node < MN) {
		int left_tasks = tasks + tree[node * 2].first;
		long long left_dur = dur + tree[node * 2].second;
		int with_break = (left_tasks - 1) / m * m;
		long long total_dur = left_dur + first_sum(with_break);
		debug << imie(node) imie(left_dur) imie(with_break) imie(total_dur);
		if (total_dur <= t) {
			tasks += tree[node * 2].first;
			dur += tree[node * 2].second;
			node = 2 * node + 1;
		}
		else {
			node *= 2;
		}
	}
	debug << imie(m) imie(t) imie(tasks);
	return tasks;
}
void solve() {
	int n, m;
	ll t;
	scanf("%d%d%lld", &n, &m, &t);
	map <int, vector <int> > poses;
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		poses[x].push_back(i);
	}
	pair <int, ll> ans = make_pair(0, t);
	for (auto & pos : poses) {
		if (pos.first > t)
			break;
		for (int x : pos.second)
			add(x, pos.first);
		int tasks = how_many(m, t);
		ans = max(ans, make_pair(tasks, (ll)pos.first));
	}
	printf("%d %lld\n", ans.first, ans.second);
	clear(n);
}
int main() {
	int c;
	scanf("%d", &c);
	while (c--) {
		solve();
	}
}
/*
add#41: [pos: 2] [val: 3] 
add#41: [pos: 5] [val: 3] 
add#41: [pos: 8] [val: 3] 
add#41: [pos: 10] [val: 3] 
first_sum#55: [cou: 2] 
first_sum#59: [tree[node * 2: 2] : (2, 6)] [tree[node * 2 + 1: 3] : (2, 6)] 
first_sum#59: [tree[node * 2: 6] : (2, 6)] [tree[node * 2 + 1: 7] : (0, 0)] 
first_sum#59: [tree[node * 2: 12] : (1, 3)] [tree[node * 2 + 1: 13] : (1, 3)] 
first_sum#59: [tree[node * 2: 24] : (1, 3)] [tree[node * 2 + 1: 25] : (0, 0)] 
first_sum#73: [ans: 6] 
how_many#85: [node: 1] [left_dur: 6] [with_break: 2] [total_dur: 12] 
first_sum#55: [cou: 4] 
first_sum#59: [tree[node * 2: 2] : (2, 6)] [tree[node * 2 + 1: 3] : (2, 6)] 
first_sum#59: [tree[node * 2: 6] : (2, 6)] [tree[node * 2 + 1: 7] : (0, 0)] 
first_sum#59: [tree[node * 2: 14] : (0, 0)] [tree[node * 2 + 1: 15] : (0, 0)] 
first_sum#59: [tree[node * 2: 30] : (0, 0)] [tree[node * 2 + 1: 31] : (0, 0)] 
first_sum#73: [ans: 12] 
how_many#85: [node: 3] [left_dur: 12] [with_break: 4] [total_dur: 24] 
first_sum#55: [cou: 4] 
first_sum#59: [tree[node * 2: 2] : (2, 6)] [tree[node * 2 + 1: 3] : (2, 6)] 
first_sum#59: [tree[node * 2: 6] : (2, 6)] [tree[node * 2 + 1: 7] : (0, 0)] 
first_sum#59: [tree[node * 2: 14] : (0, 0)] [tree[node * 2 + 1: 15] : (0, 0)] 
first_sum#59: [tree[node * 2: 30] : (0, 0)] [tree[node * 2 + 1: 31] : (0, 0)] 
first_sum#73: [ans: 12] 
how_many#85: [node: 7] [left_dur: 12] [with_break: 4] [total_dur: 24] 
first_sum#55: [cou: 4] 
first_sum#59: [tree[node * 2: 2] : (2, 6)] [tree[node * 2 + 1: 3] : (2, 6)] 
first_sum#59: [tree[node * 2: 6] : (2, 6)] [tree[node * 2 + 1: 7] : (0, 0)] 
first_sum#59: [tree[node * 2: 14] : (0, 0)] [tree[node * 2 + 1: 15] : (0, 0)] 
first_sum#59: [tree[node * 2: 30] : (0, 0)] [tree[node * 2 + 1: 31] : (0, 0)] 
first_sum#73: [ans: 12] 
how_many#85: [node: 15] [left_dur: 12] [with_break: 4] [total_dur: 24] 
how_many#95: [m: 1] [t: 29] [tasks: 4] 
add#41: [pos: 1] [val: 4] 
add#41: [pos: 6] [val: 4] 
first_sum#55: [cou: 4] 
first_sum#59: [tree[node * 2: 2] : (4, 14)] [tree[node * 2 + 1: 3] : (2, 6)] 
first_sum#59: [tree[node * 2: 6] : (2, 6)] [tree[node * 2 + 1: 7] : (0, 0)] 
first_sum#59: [tree[node * 2: 12] : (1, 3)] [tree[node * 2 + 1: 13] : (1, 3)] 
first_sum#59: [tree[node * 2: 24] : (1, 3)] [tree[node * 2 + 1: 25] : (0, 0)] 
first_sum#73: [ans: 14] 
how_many#85: [node: 1] [left_dur: 14] [with_break: 4] [total_dur: 28] 
first_sum#55: [cou: 6] 
first_sum#59: [tree[node * 2: 2] : (4, 14)] [tree[node * 2 + 1: 3] : (2, 6)] 
first_sum#59: [tree[node * 2: 6] : (2, 6)] [tree[node * 2 + 1: 7] : (0, 0)] 
first_sum#59: [tree[node * 2: 14] : (0, 0)] [tree[node * 2 + 1: 15] : (0, 0)] 
first_sum#59: [tree[node * 2: 30] : (0, 0)] [tree[node * 2 + 1: 31] : (0, 0)] 
first_sum#73: [ans: 20] 
how_many#85: [node: 3] [left_dur: 20] [with_break: 6] [total_dur: 40] 
first_sum#55: [cou: 5] 
first_sum#59: [tree[node * 2: 2] : (4, 14)] [tree[node * 2 + 1: 3] : (2, 6)] 
first_sum#59: [tree[node * 2: 6] : (2, 6)] [tree[node * 2 + 1: 7] : (0, 0)] 
first_sum#59: [tree[node * 2: 12] : (1, 3)] [tree[node * 2 + 1: 13] : (1, 3)] 
first_sum#59: [tree[node * 2: 26] : (1, 3)] [tree[node * 2 + 1: 27] : (0, 0)] 
first_sum#73: [ans: 17] 
how_many#85: [node: 6] [left_dur: 17] [with_break: 5] [total_dur: 34] 
first_sum#55: [cou: 5] 
first_sum#59: [tree[node * 2: 2] : (4, 14)] [tree[node * 2 + 1: 3] : (2, 6)] 
first_sum#59: [tree[node * 2: 6] : (2, 6)] [tree[node * 2 + 1: 7] : (0, 0)] 
first_sum#59: [tree[node * 2: 12] : (1, 3)] [tree[node * 2 + 1: 13] : (1, 3)] 
first_sum#59: [tree[node * 2: 26] : (1, 3)] [tree[node * 2 + 1: 27] : (0, 0)] 
first_sum#73: [ans: 17] 
how_many#85: [node: 12] [left_dur: 17] [with_break: 5] [total_dur: 34] 
how_many#95: [m: 1] [t: 29] [tasks: 4] 
add#41: [pos: 4] [val: 5] 
add#41: [pos: 9] [val: 5] 
first_sum#55: [cou: 5] 
first_sum#59: [tree[node * 2: 2] : (5, 19)] [tree[node * 2 + 1: 3] : (3, 11)] 
first_sum#59: [tree[node * 2: 6] : (3, 11)] [tree[node * 2 + 1: 7] : (0, 0)] 
first_sum#59: [tree[node * 2: 12] : (2, 8)] [tree[node * 2 + 1: 13] : (1, 3)] 
first_sum#59: [tree[node * 2: 24] : (1, 3)] [tree[node * 2 + 1: 25] : (1, 5)] 
first_sum#73: [ans: 19] 
how_many#85: [node: 1] [left_dur: 19] [with_break: 5] [total_dur: 38] 
first_sum#55: [cou: 2] 
first_sum#59: [tree[node * 2: 2] : (5, 19)] [tree[node * 2 + 1: 3] : (3, 11)] 
first_sum#59: [tree[node * 2: 4] : (2, 7)] [tree[node * 2 + 1: 5] : (3, 12)] 
first_sum#59: [tree[node * 2: 10] : (2, 8)] [tree[node * 2 + 1: 11] : (1, 4)] 
first_sum#59: [tree[node * 2: 20] : (1, 5)] [tree[node * 2 + 1: 21] : (1, 3)] 
first_sum#73: [ans: 7] 
how_many#85: [node: 2] [left_dur: 7] [with_break: 2] [total_dur: 14] 
first_sum#55: [cou: 4] 
first_sum#59: [tree[node * 2: 2] : (5, 19)] [tree[node * 2 + 1: 3] : (3, 11)] 
first_sum#59: [tree[node * 2: 4] : (2, 7)] [tree[node * 2 + 1: 5] : (3, 12)] 
first_sum#59: [tree[node * 2: 10] : (2, 8)] [tree[node * 2 + 1: 11] : (1, 4)] 
first_sum#59: [tree[node * 2: 22] : (1, 4)] [tree[node * 2 + 1: 23] : (0, 0)] 
first_sum#73: [ans: 15] 
how_many#85: [node: 5] [left_dur: 15] [with_break: 4] [total_dur: 30] 
first_sum#55: [cou: 3] 
first_sum#59: [tree[node * 2: 2] : (5, 19)] [tree[node * 2 + 1: 3] : (3, 11)] 
first_sum#59: [tree[node * 2: 4] : (2, 7)] [tree[node * 2 + 1: 5] : (3, 12)] 
first_sum#59: [tree[node * 2: 10] : (2, 8)] [tree[node * 2 + 1: 11] : (1, 4)] 
first_sum#59: [tree[node * 2: 20] : (1, 5)] [tree[node * 2 + 1: 21] : (1, 3)] 
first_sum#73: [ans: 12] 
how_many#85: [node: 10] [left_dur: 12] [with_break: 3] [total_dur: 24] 
how_many#95: [m: 1] [t: 29] [tasks: 3] 
add#41: [pos: 0] [val: 6] 
first_sum#55: [cou: 6] 
first_sum#59: [tree[node * 2: 2] : (6, 25)] [tree[node * 2 + 1: 3] : (3, 11)] 
first_sum#59: [tree[node * 2: 6] : (3, 11)] [tree[node * 2 + 1: 7] : (0, 0)] 
first_sum#59: [tree[node * 2: 12] : (2, 8)] [tree[node * 2 + 1: 13] : (1, 3)] 
first_sum#59: [tree[node * 2: 24] : (1, 3)] [tree[node * 2 + 1: 25] : (1, 5)] 
first_sum#73: [ans: 25] 
how_many#85: [node: 1] [left_dur: 25] [with_break: 6] [total_dur: 50] 
first_sum#55: [cou: 3] 
first_sum#59: [tree[node * 2: 2] : (6, 25)] [tree[node * 2 + 1: 3] : (3, 11)] 
first_sum#59: [tree[node * 2: 4] : (3, 13)] [tree[node * 2 + 1: 5] : (3, 12)] 
first_sum#59: [tree[node * 2: 10] : (2, 8)] [tree[node * 2 + 1: 11] : (1, 4)] 
first_sum#59: [tree[node * 2: 20] : (1, 5)] [tree[node * 2 + 1: 21] : (1, 3)] 
first_sum#73: [ans: 13] 
how_many#85: [node: 2] [left_dur: 13] [with_break: 3] [total_dur: 26] 
first_sum#55: [cou: 5] 
first_sum#59: [tree[node * 2: 2] : (6, 25)] [tree[node * 2 + 1: 3] : (3, 11)] 
first_sum#59: [tree[node * 2: 4] : (3, 13)] [tree[node * 2 + 1: 5] : (3, 12)] 
first_sum#59: [tree[node * 2: 10] : (2, 8)] [tree[node * 2 + 1: 11] : (1, 4)] 
first_sum#59: [tree[node * 2: 22] : (1, 4)] [tree[node * 2 + 1: 23] : (0, 0)] 
first_sum#73: [ans: 21] 
how_many#85: [node: 5] [left_dur: 21] [with_break: 5] [total_dur: 42] 
first_sum#55: [cou: 4] 
first_sum#59: [tree[node * 2: 2] : (6, 25)] [tree[node * 2 + 1: 3] : (3, 11)] 
first_sum#59: [tree[node * 2: 4] : (3, 13)] [tree[node * 2 + 1: 5] : (3, 12)] 
first_sum#59: [tree[node * 2: 10] : (2, 8)] [tree[node * 2 + 1: 11] : (1, 4)] 
first_sum#59: [tree[node * 2: 20] : (1, 5)] [tree[node * 2 + 1: 21] : (1, 3)] 
first_sum#73: [ans: 18] 
how_many#85: [node: 10] [left_dur: 18] [with_break: 4] [total_dur: 36] 
how_many#95: [m: 1] [t: 29] [tasks: 3] 
add#41: [pos: 3] [val: 7] 
add#41: [pos: 7] [val: 7] 
first_sum#55: [cou: 8] 
first_sum#59: [tree[node * 2: 2] : (8, 39)] [tree[node * 2 + 1: 3] : (3, 11)] 
first_sum#59: [tree[node * 2: 6] : (3, 11)] [tree[node * 2 + 1: 7] : (0, 0)] 
first_sum#59: [tree[node * 2: 12] : (2, 8)] [tree[node * 2 + 1: 13] : (1, 3)] 
first_sum#59: [tree[node * 2: 24] : (1, 3)] [tree[node * 2 + 1: 25] : (1, 5)] 
first_sum#73: [ans: 39] 
how_many#85: [node: 1] [left_dur: 39] [with_break: 8] [total_dur: 78] 
first_sum#55: [cou: 4] 
first_sum#59: [tree[node * 2: 2] : (8, 39)] [tree[node * 2 + 1: 3] : (3, 11)] 
first_sum#59: [tree[node * 2: 4] : (4, 20)] [tree[node * 2 + 1: 5] : (4, 19)] 
first_sum#59: [tree[node * 2: 10] : (2, 8)] [tree[node * 2 + 1: 11] : (2, 11)] 
first_sum#59: [tree[node * 2: 20] : (1, 5)] [tree[node * 2 + 1: 21] : (1, 3)] 
first_sum#73: [ans: 20] 
how_many#85: [node: 2] [left_dur: 20] [with_break: 4] [total_dur: 40] 
first_sum#55: [cou: 2] 
first_sum#59: [tree[node * 2: 2] : (8, 39)] [tree[node * 2 + 1: 3] : (3, 11)] 
first_sum#59: [tree[node * 2: 4] : (4, 20)] [tree[node * 2 + 1: 5] : (4, 19)] 
first_sum#59: [tree[node * 2: 8] : (2, 10)] [tree[node * 2 + 1: 9] : (2, 10)] 
first_sum#59: [tree[node * 2: 18] : (1, 3)] [tree[node * 2 + 1: 19] : (1, 7)] 
first_sum#73: [ans: 10] 
how_many#85: [node: 4] [left_dur: 10] [with_break: 2] [total_dur: 20] 
first_sum#55: [cou: 3] 
first_sum#59: [tree[node * 2: 2] : (8, 39)] [tree[node * 2 + 1: 3] : (3, 11)] 
first_sum#59: [tree[node * 2: 4] : (4, 20)] [tree[node * 2 + 1: 5] : (4, 19)] 
first_sum#59: [tree[node * 2: 8] : (2, 10)] [tree[node * 2 + 1: 9] : (2, 10)] 
first_sum#59: [tree[node * 2: 18] : (1, 3)] [tree[node * 2 + 1: 19] : (1, 7)] 
first_sum#73: [ans: 13] 
how_many#85: [node: 9] [left_dur: 13] [with_break: 3] [total_dur: 26] 
how_many#95: [m: 1] [t: 29] [tasks: 3] 
add#41: [pos: 0] [val: 1] 
add#41: [pos: 1] [val: 1] 
add#41: [pos: 2] [val: 1] 
add#41: [pos: 3] [val: 1] 
add#41: [pos: 4] [val: 1] 
add#41: [pos: 5] [val: 1] 
add#41: [pos: 6] [val: 1] 
first_sum#55: [cou: 7] 
first_sum#59: [tree[node * 2: 2] : (7, 7)] [tree[node * 2 + 1: 3] : (0, 0)] 
first_sum#59: [tree[node * 2: 6] : (0, 0)] [tree[node * 2 + 1: 7] : (0, 0)] 
first_sum#59: [tree[node * 2: 14] : (0, 0)] [tree[node * 2 + 1: 15] : (0, 0)] 
first_sum#59: [tree[node * 2: 30] : (0, 0)] [tree[node * 2 + 1: 31] : (0, 0)] 
first_sum#73: [ans: 7] 
how_many#85: [node: 1] [left_dur: 7] [with_break: 7] [total_dur: 14] 
first_sum#55: [cou: 4] 
first_sum#59: [tree[node * 2: 2] : (7, 7)] [tree[node * 2 + 1: 3] : (0, 0)] 
first_sum#59: [tree[node * 2: 4] : (4, 4)] [tree[node * 2 + 1: 5] : (3, 3)] 
first_sum#59: [tree[node * 2: 10] : (2, 2)] [tree[node * 2 + 1: 11] : (1, 1)] 
first_sum#59: [tree[node * 2: 20] : (1, 1)] [tree[node * 2 + 1: 21] : (1, 1)] 
first_sum#73: [ans: 4] 
how_many#85: [node: 2] [left_dur: 4] [with_break: 4] [total_dur: 8] 
first_sum#55: [cou: 2] 
first_sum#59: [tree[node * 2: 2] : (7, 7)] [tree[node * 2 + 1: 3] : (0, 0)] 
first_sum#59: [tree[node * 2: 4] : (4, 4)] [tree[node * 2 + 1: 5] : (3, 3)] 
first_sum#59: [tree[node * 2: 8] : (2, 2)] [tree[node * 2 + 1: 9] : (2, 2)] 
first_sum#59: [tree[node * 2: 18] : (1, 1)] [tree[node * 2 + 1: 19] : (1, 1)] 
first_sum#73: [ans: 2] 
how_many#85: [node: 4] [left_dur: 2] [with_break: 2] [total_dur: 4] 
first_sum#55: [cou: 3] 
first_sum#59: [tree[node * 2: 2] : (7, 7)] [tree[node * 2 + 1: 3] : (0, 0)] 
first_sum#59: [tree[node * 2: 4] : (4, 4)] [tree[node * 2 + 1: 5] : (3, 3)] 
first_sum#59: [tree[node * 2: 8] : (2, 2)] [tree[node * 2 + 1: 9] : (2, 2)] 
first_sum#59: [tree[node * 2: 18] : (1, 1)] [tree[node * 2 + 1: 19] : (1, 1)] 
first_sum#73: [ans: 3] 
how_many#85: [node: 9] [left_dur: 3] [with_break: 3] [total_dur: 6] 
how_many#95: [m: 1] [t: 5] [tasks: 2] 
add#41: [pos: 0] [val: 2] 
first_sum#55: [cou: 0] 
first_sum#59: [tree[node * 2: 2] : (1, 2)] [tree[node * 2 + 1: 3] : (0, 0)] 
first_sum#59: [tree[node * 2: 4] : (1, 2)] [tree[node * 2 + 1: 5] : (0, 0)] 
first_sum#59: [tree[node * 2: 8] : (1, 2)] [tree[node * 2 + 1: 9] : (0, 0)] 
first_sum#59: [tree[node * 2: 16] : (1, 2)] [tree[node * 2 + 1: 17] : (0, 0)] 
first_sum#73: [ans: 0] 
how_many#85: [node: 1] [left_dur: 2] [with_break: 0] [total_dur: 2] 
first_sum#55: [cou: 0] 
first_sum#59: [tree[node * 2: 2] : (1, 2)] [tree[node * 2 + 1: 3] : (0, 0)] 
first_sum#59: [tree[node * 2: 4] : (1, 2)] [tree[node * 2 + 1: 5] : (0, 0)] 
first_sum#59: [tree[node * 2: 8] : (1, 2)] [tree[node * 2 + 1: 9] : (0, 0)] 
first_sum#59: [tree[node * 2: 16] : (1, 2)] [tree[node * 2 + 1: 17] : (0, 0)] 
first_sum#73: [ans: 0] 
how_many#85: [node: 3] [left_dur: 2] [with_break: 0] [total_dur: 2] 
first_sum#55: [cou: 0] 
first_sum#59: [tree[node * 2: 2] : (1, 2)] [tree[node * 2 + 1: 3] : (0, 0)] 
first_sum#59: [tree[node * 2: 4] : (1, 2)] [tree[node * 2 + 1: 5] : (0, 0)] 
first_sum#59: [tree[node * 2: 8] : (1, 2)] [tree[node * 2 + 1: 9] : (0, 0)] 
first_sum#59: [tree[node * 2: 16] : (1, 2)] [tree[node * 2 + 1: 17] : (0, 0)] 
first_sum#73: [ans: 0] 
how_many#85: [node: 7] [left_dur: 2] [with_break: 0] [total_dur: 2] 
first_sum#55: [cou: 0] 
first_sum#59: [tree[node * 2: 2] : (1, 2)] [tree[node * 2 + 1: 3] : (0, 0)] 
first_sum#59: [tree[node * 2: 4] : (1, 2)] [tree[node * 2 + 1: 5] : (0, 0)] 
first_sum#59: [tree[node * 2: 8] : (1, 2)] [tree[node * 2 + 1: 9] : (0, 0)] 
first_sum#59: [tree[node * 2: 16] : (1, 2)] [tree[node * 2 + 1: 17] : (0, 0)] 
first_sum#73: [ans: 0] 
how_many#85: [node: 15] [left_dur: 2] [with_break: 0] [total_dur: 2] 
how_many#95: [m: 2] [t: 18] [tasks: 1] 
add#41: [pos: 1] [val: 3] 
add#41: [pos: 2] [val: 3] 
first_sum#55: [cou: 2] 
first_sum#59: [tree[node * 2: 2] : (3, 8)] [tree[node * 2 + 1: 3] : (0, 0)] 
first_sum#59: [tree[node * 2: 4] : (3, 8)] [tree[node * 2 + 1: 5] : (0, 0)] 
first_sum#59: [tree[node * 2: 8] : (2, 5)] [tree[node * 2 + 1: 9] : (1, 3)] 
first_sum#59: [tree[node * 2: 18] : (1, 3)] [tree[node * 2 + 1: 19] : (0, 0)] 
first_sum#73: [ans: 5] 
how_many#85: [node: 1] [left_dur: 8] [with_break: 2] [total_dur: 13] 
first_sum#55: [cou: 2] 
first_sum#59: [tree[node * 2: 2] : (3, 8)] [tree[node * 2 + 1: 3] : (0, 0)] 
first_sum#59: [tree[node * 2: 4] : (3, 8)] [tree[node * 2 + 1: 5] : (0, 0)] 
first_sum#59: [tree[node * 2: 8] : (2, 5)] [tree[node * 2 + 1: 9] : (1, 3)] 
first_sum#59: [tree[node * 2: 18] : (1, 3)] [tree[node * 2 + 1: 19] : (0, 0)] 
first_sum#73: [ans: 5] 
how_many#85: [node: 3] [left_dur: 8] [with_break: 2] [total_dur: 13] 
first_sum#55: [cou: 2] 
first_sum#59: [tree[node * 2: 2] : (3, 8)] [tree[node * 2 + 1: 3] : (0, 0)] 
first_sum#59: [tree[node * 2: 4] : (3, 8)] [tree[node * 2 + 1: 5] : (0, 0)] 
first_sum#59: [tree[node * 2: 8] : (2, 5)] [tree[node * 2 + 1: 9] : (1, 3)] 
first_sum#59: [tree[node * 2: 18] : (1, 3)] [tree[node * 2 + 1: 19] : (0, 0)] 
first_sum#73: [ans: 5] 
how_many#85: [node: 7] [left_dur: 8] [with_break: 2] [total_dur: 13] 
first_sum#55: [cou: 2] 
first_sum#59: [tree[node * 2: 2] : (3, 8)] [tree[node * 2 + 1: 3] : (0, 0)] 
first_sum#59: [tree[node * 2: 4] : (3, 8)] [tree[node * 2 + 1: 5] : (0, 0)] 
first_sum#59: [tree[node * 2: 8] : (2, 5)] [tree[node * 2 + 1: 9] : (1, 3)] 
first_sum#59: [tree[node * 2: 18] : (1, 3)] [tree[node * 2 + 1: 19] : (0, 0)] 
first_sum#73: [ans: 5] 
how_many#85: [node: 15] [left_dur: 8] [with_break: 2] [total_dur: 13] 
how_many#95: [m: 2] [t: 18] [tasks: 3] 
add#41: [pos: 4] [val: 5] 
first_sum#55: [cou: 4] 
first_sum#59: [tree[node * 2: 2] : (4, 13)] [tree[node * 2 + 1: 3] : (0, 0)] 
first_sum#59: [tree[node * 2: 6] : (0, 0)] [tree[node * 2 + 1: 7] : (0, 0)] 
first_sum#59: [tree[node * 2: 14] : (0, 0)] [tree[node * 2 + 1: 15] : (0, 0)] 
first_sum#59: [tree[node * 2: 30] : (0, 0)] [tree[node * 2 + 1: 31] : (0, 0)] 
first_sum#73: [ans: 13] 
how_many#85: [node: 1] [left_dur: 13] [with_break: 4] [total_dur: 26] 
first_sum#55: [cou: 2] 
first_sum#59: [tree[node * 2: 2] : (4, 13)] [tree[node * 2 + 1: 3] : (0, 0)] 
first_sum#59: [tree[node * 2: 4] : (3, 8)] [tree[node * 2 + 1: 5] : (1, 5)] 
first_sum#59: [tree[node * 2: 8] : (2, 5)] [tree[node * 2 + 1: 9] : (1, 3)] 
first_sum#59: [tree[node * 2: 18] : (1, 3)] [tree[node * 2 + 1: 19] : (0, 0)] 
first_sum#73: [ans: 5] 
how_many#85: [node: 2] [left_dur: 8] [with_break: 2] [total_dur: 13] 
first_sum#55: [cou: 4] 
first_sum#59: [tree[node * 2: 2] : (4, 13)] [tree[node * 2 + 1: 3] : (0, 0)] 
first_sum#59: [tree[node * 2: 6] : (0, 0)] [tree[node * 2 + 1: 7] : (0, 0)] 
first_sum#59: [tree[node * 2: 14] : (0, 0)] [tree[node * 2 + 1: 15] : (0, 0)] 
first_sum#59: [tree[node * 2: 30] : (0, 0)] [tree[node * 2 + 1: 31] : (0, 0)] 
first_sum#73: [ans: 13] 
how_many#85: [node: 5] [left_dur: 13] [with_break: 4] [total_dur: 26] 
first_sum#55: [cou: 4] 
first_sum#59: [tree[node * 2: 2] : (4, 13)] [tree[node * 2 + 1: 3] : (0, 0)] 
first_sum#59: [tree[node * 2: 6] : (0, 0)] [tree[node * 2 + 1: 7] : (0, 0)] 
first_sum#59: [tree[node * 2: 14] : (0, 0)] [tree[node * 2 + 1: 15] : (0, 0)] 
first_sum#59: [tree[node * 2: 30] : (0, 0)] [tree[node * 2 + 1: 31] : (0, 0)] 
first_sum#73: [ans: 13] 
how_many#85: [node: 10] [left_dur: 13] [with_break: 4] [total_dur: 26] 
how_many#95: [m: 2] [t: 18] [tasks: 3] 
add#41: [pos: 3] [val: 7] 
first_sum#55: [cou: 4] 
first_sum#59: [tree[node * 2: 2] : (5, 20)] [tree[node * 2 + 1: 3] : (0, 0)] 
first_sum#59: [tree[node * 2: 4] : (4, 15)] [tree[node * 2 + 1: 5] : (1, 5)] 
first_sum#59: [tree[node * 2: 10] : (1, 5)] [tree[node * 2 + 1: 11] : (0, 0)] 
first_sum#59: [tree[node * 2: 20] : (1, 5)] [tree[node * 2 + 1: 21] : (0, 0)] 
first_sum#73: [ans: 15] 
how_many#85: [node: 1] [left_dur: 20] [with_break: 4] [total_dur: 35] 
first_sum#55: [cou: 4] 
first_sum#59: [tree[node * 2: 2] : (5, 20)] [tree[node * 2 + 1: 3] : (0, 0)] 
first_sum#59: [tree[node * 2: 4] : (4, 15)] [tree[node * 2 + 1: 5] : (1, 5)] 
first_sum#59: [tree[node * 2: 10] : (1, 5)] [tree[node * 2 + 1: 11] : (0, 0)] 
first_sum#59: [tree[node * 2: 20] : (1, 5)] [tree[node * 2 + 1: 21] : (0, 0)] 
first_sum#73: [ans: 15] 
how_many#85: [node: 2] [left_dur: 15] [with_break: 4] [total_dur: 30] 
first_sum#55: [cou: 2] 
first_sum#59: [tree[node * 2: 2] : (5, 20)] [tree[node * 2 + 1: 3] : (0, 0)] 
first_sum#59: [tree[node * 2: 4] : (4, 15)] [tree[node * 2 + 1: 5] : (1, 5)] 
first_sum#59: [tree[node * 2: 8] : (2, 5)] [tree[node * 2 + 1: 9] : (2, 10)] 
first_sum#59: [tree[node * 2: 18] : (1, 3)] [tree[node * 2 + 1: 19] : (1, 7)] 
first_sum#73: [ans: 5] 
how_many#85: [node: 4] [left_dur: 5] [with_break: 2] [total_dur: 10] 
first_sum#55: [cou: 2] 
first_sum#59: [tree[node * 2: 2] : (5, 20)] [tree[node * 2 + 1: 3] : (0, 0)] 
first_sum#59: [tree[node * 2: 4] : (4, 15)] [tree[node * 2 + 1: 5] : (1, 5)] 
first_sum#59: [tree[node * 2: 8] : (2, 5)] [tree[node * 2 + 1: 9] : (2, 10)] 
first_sum#59: [tree[node * 2: 18] : (1, 3)] [tree[node * 2 + 1: 19] : (1, 7)] 
first_sum#73: [ans: 5] 
how_many#85: [node: 9] [left_dur: 8] [with_break: 2] [total_dur: 13] 
how_many#95: [m: 2] [t: 18] [tasks: 3] 
* 
*/