#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10;

int first[N << 3], cur = 1;
struct Edge {int nxt, to;} e[N << 3];
void con(int x, int y) {
	e[++cur] = (Edge){first[x], y};
	first[x] = cur;
}

int n, m, v1[N << 3], v2[N << 3];
stack<int> s, t;
vector<int> a1, a2;
string s1[2], s2[2];

void dfs(int x) {
	v1[x] = 1;
	for (int i = first[x]; i; i = e[i].nxt) {
		if (v2[i]) continue;
		int v = e[i].to;
		v2[i] = v2[i ^ 1] = 1;
		t.push(v);
		if (!v1[v]) dfs(v);
		t.push(x);
	}
}

int main() {
	scanf("%d", &n), m = 2 * n;
	for (int i = 1, x, y; i <= n; i++) {
		scanf("%d%d", &x, &y);
		con(x, y), con(y, x);
	}
	for (int T = 1; T <= m; T++) {
		if (v1[T]) continue;
		dfs(T);
		if (t.size() == 2) {
			puts("-1");
			return 0;
		}
		if (t.size() == 0)
			continue;
		int k = t.size() / 2;
		vector<int> t1, t2;
		while (t.size()) {
			int x = t.top(); t.pop();
			int y = t.top(); t.pop();
			if (t1.size() < k) t1.push_back(x);
			else t2.push_back(x);
			if (t1.size() < k) t1.push_back(y);
			else t2.push_back(y);
		}
		reverse(t2.begin(), t2.end());
		for (int i : t1) a1.push_back(i);
		for (int i : t2) a2.push_back(i);
		for (int i = 1; i + 1 <= k; i += 2)
			s1[0] += "LR";
		if (k % 2 == 1) s1[0] += "U";
		for (int i = 1; i + 1 <= k; i += 2)
			s2[0] += "LR";
		if (k % 2 == 1) s2[0] += "D";
		if (k % 2 == 1) {
			if (k % 2 == 1) s1[1] += "U";
			for (int i = 1; i + 1 <= k; i += 2)
				s1[1] += "LR";
			if (k % 2 == 1) s2[1] += "D";
			for (int i = 1; i + 1 <= k; i += 2)
				s2[1] += "LR";
		}
		else {
			s1[1] += "U";
			for (int i = 2; i + 1 <= k; i += 2)
				s1[1] += "LR";
			s1[1] += "U";
			s2[1] += "D";
			for (int i = 2; i + 1 <= k; i += 2)
				s2[1] += "LR";
			s2[1] += "D";
		}
	}

	if (a1.size() != n) {
		puts("-1");
		return 0;
	}

	printf("2 %d\n\n", n);
	
	for (int i : a1) printf("%d ", i);
	puts("");
	for (int i : a2) printf("%d ", i);
	puts(""), puts("");

	for (int i = 0; i < 2; i++)
		cout << s1[i] << endl << s2[i] << endl << endl;
	return 0;
}