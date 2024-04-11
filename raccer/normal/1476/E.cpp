#include <bits/stdc++.h>
using namespace std;

string s[100010];
char buf[10];
vector <int> from[100010];
int in[100010];
int ID[1000000];
vector <int> ord;

string read() {
	scanf("%s", buf);
	return buf;
}

bool OK(string a, string b) {
	for (int i = 0; i < a.size(); i++) {
		if (b[i] == '_' || a[i] == b[i]) continue;
		return 0;
	}
	return 1;
}

int get_h(string s) {
	int H = 0;
	for (int i = 0; i < s.size(); i++) {
		H = H * 27 + (s[i] == '_' ? 26 : s[i] - 'a');
	}
	return H;
}

int main () {
	memset(ID, -1, sizeof(ID));
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		s[i] = read();
		ID[get_h(s[i])] = i;
	}
	for (int j = 0; j < m; j++) {
		string t = read();
		int x; scanf("%d", &x);
		x--;
		if (!OK(t, s[x])) {
			printf("NO\n");
			return 0;
		}
		for (int mask = 0; mask < (1 << k); mask++) {
			string cur;
			for (int i = 0; i < k; i++) {
				if (mask >> i & 1) cur.push_back(t[i]);
				else cur.push_back('_');
			}
			int v = ID[get_h(cur)];
			if (v == -1) continue;
			if (x != v) from[x].push_back(v), in[v]++;
		}
	}
	for (int i = 0; i < n; i++) {
		if (!in[i]) ord.push_back(i);
	}
	for (int it = 0; it < ord.size(); it++) {
		int x = ord[it];
		for (int i = 0; i < from[x].size(); i++) {
			int v = from[x][i];
			in[v]--;
			if (!in[v]) ord.push_back(v);
		}
	}
	if (ord.size() != n) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for (int i = 0; i < ord.size(); i++) {
		printf("%d ", ord[i] + 1);
	}
	printf("\n");
	return 0;
}