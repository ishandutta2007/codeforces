#include <bits/stdc++.h>

struct node {
	std::string str;
	std::vector <int> loc;
};

bool operator < (const node &a, const node &b) {
	return a.str.size () > b.str.size ();
}

int N;
node n[110000];
char ans[2100000];
int asize = 0;
int anc[2100000];

int get_anc (int x) {
	if (anc[x] == x) return x;
	return anc[x] = get_anc (anc[x]);
}

int main () {
	std::ios::sync_with_stdio (0);
	std::cin.tie (0);
	std::cout.tie (0);
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> n[i].str;
		int t;
		std::cin >> t;
		for (int j = 0; j < t; ++j) {
			int l;
			std::cin >> l;
			n[i].loc.push_back (l);
		}
	}
	for (int i = 0; i < 2100000; ++i) anc[i] = i;
	std::sort (n, n + N);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < n[i].loc.size (); ++j)
			for (int k = get_anc (n[i].loc[j]) - n[i].loc[j]; ans[n[i].loc[j] + k] == 0 && k < n[i].str.size (); ++k) {
				ans[n[i].loc[j] + k] = n[i].str[k];
				anc[n[i].loc[j] + k] = n[i].loc[j] + k + 1;
				if (asize < n[i].loc[j] + k) asize = n[i].loc[j] + k;
			}
	for (int i = 1; i <= asize; ++i) 
		if (ans[i] == 0) ans[i] = 'a';
	puts (ans + 1);
	return 0;
}