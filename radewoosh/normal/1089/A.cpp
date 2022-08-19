#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include <bits/stdc++.h>
using namespace std;
#define sim template <class c
#define mor > muu & operator<<(
#define ris return *this
#define R22(r) sim> typename enable_if<1 r sizeof(dud<c>(0)),muu&>::type operator<<(c g) {
sim> struct rge {c b, e;};
sim> rge<c> range(c i, c j) {return rge<c>{i, j};}
sim> auto dud(c*r)->decltype(cerr << *r);
sim> char dud(...);
struct muu {
	#ifdef LOCAL
	stringstream a;
	~muu() {cerr << a.str() << endl;}
	R22(<) a << boolalpha << g; ris;}
	R22(==) ris << range(begin(g), end(g));}
	sim mor rge<c> u) {
		a << "[";
		for (c i = u.b; i != u.e; ++i)
			*this << ", " + 2 * (i == u.b) << *i;
		ris << "]";
	}
	sim, class m mor pair<m,c> r) {ris << "(" << r.first << ", " << r.second << ")";}
	#else
	sim mor const c &){ris;}
	#endif
	muu & operator()(){ris;}
};
#define imie(r) "[" #r ": " << (r) << "] "
#define debug (muu() << __FUNCTION__ << "#" << __LINE__ << ": " )
const int nax = 201;
using pii = pair <int, int>;
vector <pii> gen_won(int to) {
	vector <pii> ans;
	for (int i = 0; i <= to - 2; ++i)
		ans.emplace_back(to, i);
	for (int i = to - 1; i < nax; ++i)
		ans.emplace_back(i + 2, i);
	return ans;
}
vector <pii> gen_lost(int to) {
	auto ans = gen_won(to);
	for (auto &x : ans)
		swap(x.first, x.second);
	return ans;
}
vector <pii> dp[4][4][nax][nax];
int main() {
	for (int s1 = 0; s1 < 3; ++s1)
		for (int s2 = 0; s2 < 3; ++s2) {
			int to = (s1 + s2 == 4 ? 15 : 25);
			vector <pii> won = gen_won(to), lost = gen_lost(to);
			debug << imie(won) imie(lost) imie(s1) imie(s2);
			for (int a = 0; a < nax; ++a)
				for (int b = 0; b < nax; ++b)
					if (!dp[s1][s2][a][b].empty() || (s1 == 0 && s2 == 0 && a == 0 && b == 0)) {
						for (pii m : won) {
							int a2 = a + m.first;
							int b2 = b + m.second;
							if (a2 < nax && b2 < nax && dp[s1 + 1][s2][a2][b2].empty()) {
								dp[s1 + 1][s2][a2][b2] = dp[s1][s2][a][b];
								dp[s1 + 1][s2][a2][b2].push_back(m);
							}
						}
						for (pii m : lost) {
							int a2 = a + m.first;
							int b2 = b + m.second;
							if (a2 < nax && b2 < nax && dp[s1][s2 + 1][a2][b2].empty()) {
								dp[s1][s2 + 1][a2][b2] = dp[s1][s2][a][b];
								dp[s1][s2 + 1][a2][b2].push_back(m);
							}
						}
					}
		}
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		for (int x = 0; x < 4; ++x)
			for (int y = 0; y < 4; ++y)
				debug << imie(x) imie(y) imie(dp[x][y][a][b]);
		vector <pii> reses = {{3, 0}, {3, 1}, {3, 2}, {2, 3}, {1, 3}, {0, 3}};
		bool any = false;
		for (pii x : reses) {
			if (dp[x.first][x.second][a][b].size()) {
				printf("%d:%d\n", x.first, x.second);
				for (pii c : dp[x.first][x.second][a][b])
					printf("%d:%d ", c.first, c.second);
				printf("\n");
				any = true;
				break;
			}
		}
		if (!any)
			printf("Impossible\n");
	}
}