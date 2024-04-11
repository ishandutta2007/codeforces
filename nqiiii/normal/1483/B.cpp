#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
int T, n, P, a[maxn + 10];
set<int> st;
set<pair<int, int> > st2;
vector<int> ans;

void delit(int p) {
	P = p + 1;
	ans.push_back(p);
	st.erase(p);
	if (st.empty()) {
		st2.clear();
		return;
	}
	int fr, la;
	if (*st.begin() > p)
		fr = *--st.end();
	else fr = *--st.lower_bound(p);
	if (*--st.end() < p)
		la = *st.begin();
	else la = *st.lower_bound(p);
	if (__gcd(a[fr], a[p]) == 1) st2.erase(make_pair(fr, p));
	if (__gcd(a[p], a[la]) == 1) st2.erase(make_pair(p, la));
	if (__gcd(a[fr], a[la]) == 1) st2.insert(make_pair(fr, la));
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		ans.clear();
		st.clear(); st2.clear();
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			st.insert(i);
		}
		for (int i = 1; i <= n; ++i)
			if (__gcd(a[i], a[i % n + 1]) == 1)
				st2.insert(make_pair(i, i % n + 1));
		P = 1;
		while (1) {
			if (st2.empty()) break;
			auto it = st2.lower_bound(make_pair(P, 0));
			if (it != st2.end()) {
				delit(it -> second);
				continue;
			}
			delit(st2.begin() -> second);
		}
		printf("%d ", (int)ans.size());
		for (auto i: ans) printf("%d ", i);
		printf("\n");
	}
}