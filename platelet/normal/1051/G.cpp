#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define mid ((l + r) / 2)

using namespace std;

const int N = 2e5 + 5, M = N * 20;
typedef long long ll;
typedef pair <int, int> P;

int n, sz, A, B, ls[M], rs[M];
ll c0[M], c1[M], c2[M];
void pu(int o) {
	c0[o] = c0[ls[o]] + c0[rs[o]];
	c1[o] = c1[ls[o]] + c1[rs[o]];
	c2[o] = c2[ls[o]] + c2[rs[o]] + c1[ls[o]] * c0[rs[o]];
}
int node(int p, int l, int r) {
	int o = ++sz;
	c0[o]++, c1[o] += p;
	if(p > mid) rs[o] = node(p, mid + 1, r);
	else if(l < r) ls[o] = node(p, l, mid);
	return o;
}
void join(int& o, int oo) {
	if(!o || !oo) { o += oo; return; }
	join(ls[o], ls[oo]), join(rs[o], rs[oo]), pu(o);
}
set <P, greater <P>> s;

int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n;
	ll as = 0;
	rep(i, 1, n) {
		scanf("%d%d", &A, &B);
		auto it = s.lower_bound({A, 1e9});
		s.insert({A, node(B, 1, 200000)});
		if(it == s.end() || A > it -> first + c0[it -> second]) it--;
		auto [l, t] = *it;
		while(it != s.begin()) {
			auto [L, T] = *--it; it++;
			if(L <= l + c0[t]) as -= c1[T] * (L - l) + c2[t] + c2[T], join(t, T), as += c2[t], s.erase({L, T});
			else break;
		}
		printf("%lld\n", as);
	}
	return 0;
}