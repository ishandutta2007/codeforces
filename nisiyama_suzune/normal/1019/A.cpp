#include <bits/stdc++.h>

const long long INF = 1E18;

int N, M;
std::vector <int> part[3100];
std::vector <int> st;

int main () {
	std::ios::sync_with_stdio (0);
	std::cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		int u, v;
		std::cin >> u >> v;
		part[u].push_back (v);
	}
	for (int i = 1; i <= M; ++i) std::sort (part[i].begin (), part[i].end (), std::greater <int> ());
	long long res = INF;
	for (int i = 1; i <= N; ++i) {
		st.clear ();
		int add = part[1].size (); long long cur = 0;
		for (int j = 2; j <= M; ++j) {
			add += std::max (0, (int) part[j].size () - i + 1);
			for (int k = 0; k < part[j].size (); ++k)
				if (k < (int) part[j].size () - i + 1) cur += part[j][part[j].size () - 1 - k];
				else st.push_back (part[j][part[j].size () - 1 - k]);
		}
		std::sort (st.begin (), st.end ());
		for (int j = add; j < i; ++j) 
			cur += st[j - add];
		res = std::min (res, cur);
	}
	std::cout << res << "\n";
}