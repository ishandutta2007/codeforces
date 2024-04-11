#include <cstdio>
#include <algorithm>
#include <set>
#include <bitset>
#include <iostream>

typedef std::pair<int, int> pii;
const int MN = 2005;

int N, M, Q;
int cnt[MN];
std::bitset<2000> bits[MN], prefix[2001];
std::set<pii> st;
int lnk[MN], ok[MN];
std::set<int> Ans;

inline void chk(int u, int v) {
	if (!u) return ;
	if (ok[u]) Ans.erase(u);
	lnk[u] = v, ok[u] = 0;
	if (!v) return ;
	if ((bits[u] & bits[v]) != bits[v]) ok[u] = 1, Ans.insert(u);
}

inline void Del(int c, int p) {
	auto it = st.lower_bound(std::make_pair(c, p));
	auto lst = it, nxt = it; --lst, ++nxt;
	st.erase(it);
	chk(nxt->second, lst->second);
}

inline void Ins(int c, int p) {
	auto it = st.insert(std::make_pair(c, p)).first;
	auto lst = it, nxt = it; --lst, ++nxt;
	chk(p, lst->second);
	chk(nxt->second, p);
}

int main() {
	for (int i = 1; i <= 2000; ++i)
		prefix[i] = prefix[i - 1],
		prefix[i].set(i - 1);
	scanf("%d%d%d", &N, &M, &Q);
	st.insert(std::make_pair(-1, 0));
	st.insert(std::make_pair(M + 1, 0));
	for (int i = 1; i <= N; ++i)
		st.insert(std::make_pair(0, i));
	while (Q--) {
		int id, l, r;
		scanf("%d%d%d", &id, &l, &r);
		Del(cnt[id], id);
		bits[id] ^= prefix[l - 1];
		bits[id] ^= prefix[r];
		cnt[id] = bits[id].count();
		Ins(cnt[id], id);
		if (Ans.empty()) puts("-1");
		else {
			auto it = Ans.begin();
			int u = *it, v = lnk[u];
			int pos1 = (bits[u] & ~bits[v])._Find_first();
			int pos2 = (bits[v] & ~bits[u])._Find_first();
			if (u > v) std::swap(u, v);
			if (pos1 > pos2) std::swap(pos1, pos2);
			printf("%d %d %d %d\n", u, pos1 + 1, v, pos2 + 1);
		}
	}
	return 0;
}