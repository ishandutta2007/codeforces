#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
const int N = 1e5 + 5;
typedef long long ll;
int n, q, fa[N], du[N]; ll t[N], su[N];
multiset <ll> s[N], mi, ma;
ll flow(int i) { return t[i] / (du[i] + 2); }
ll sum(int i) { return t[i] - (du[i] + 1) * flow(i) + su[i]; }
void era(int i) {
	if(!s[i].empty()) {
		mi.erase(mi.find(*s[i].begin() + flow(i)));
		ma.erase(ma.find(*s[i].rbegin() + flow(i)));
	}
}
void ins(int i) {
	if(!s[i].empty()) {
		mi.insert(*s[i].begin() + flow(i));
		ma.insert(*s[i].rbegin() + flow(i));
	}
}
void rmv(int i, int ty = 1) {
	int f = fa[i]; era(f), s[f].erase(s[f].find(sum(i))); if(ty) su[f] -= flow(i);
}
void add(int i, int ty = 1) {
	int f = fa[i]; s[f].insert(sum(i)); if(ty) su[f] += flow(i); ins(f);
}
int main() {
	cin >> n >> q;
	rep(i, 1, n) scanf("%lld", &t[i]);
	rep(i, 1, n) scanf("%d", &fa[i]), du[fa[i]]++;
	rep(i, 1, n) su[fa[i]] += flow(i); 
	rep(i, 1, n) s[fa[i]].insert(sum(i));
	rep(i, 1, n) ins(i);
	for(int op, x, y; q--;) {
		scanf("%d", &op);
		if(op == 1) {
			scanf("%d%d", &x, &y);
			int a = fa[x], b = fa[a];
			rmv(b, 0), rmv(a), rmv(x), du[a]--, ins(a), add(a), add(b, 0);
			a = fa[x] = y, b = fa[a];
			rmv(b, 0), rmv(a), era(a), du[a]++, add(x), add(a), add(b, 0);
		}
	 	if(op == 2) scanf("%d", &x), printf("%lld\n", sum(x) + flow(fa[x]));
		if(op == 3) printf("%lld %lld\n", *mi.begin(), *ma.rbegin());
	}
	return 0;
}