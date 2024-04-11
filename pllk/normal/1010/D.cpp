#include <iostream>

using namespace std;

int n;
string s[1222333];
int a[1222333], b[1222333], c[1222333];
int u[1222333];

int re[1222333];
int ch[1222333];

int calc(int x) {
	if (s[x] == "IN") return u[x] = a[x];
	if (s[x] == "AND") return u[x] = calc(a[x])&calc(b[x]);
	if (s[x] == "OR") return u[x] = calc(a[x])|calc(b[x]);
	if (s[x] == "XOR") return u[x] = calc(a[x])^calc(b[x]);
	if (s[x] == "NOT") return u[x] = 1-calc(a[x]);
}

int change(int x) {
	if (re[x]) return ch[x];
	if (x == 1) return 1;
	u[x] = 1-u[x];
	int k = c[x];
	int w = 0;
	if (s[k] == "AND") {
		int g = u[a[k]]&u[b[k]];
		if (g != u[k]) w = change(k);
	}
	if (s[k] == "OR") {
		int g = u[a[k]]|u[b[k]];
		if (g != u[k]) w = change(k);
	}
	if (s[k] == "XOR") {
		int g = u[a[k]]^u[b[k]];
		if (g != u[k]) w = change(k);
	}
	if (s[k] == "NOT") {
		int g = 1-u[a[k]];
		if (g != u[k]) w = change(k);
	}
	re[x] = 1;
	ch[x] = w;
	u[x] = 1-u[x];
	return ch[x];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		if (s[i] == "AND" || s[i] == "OR" || s[i] == "XOR") {
			cin >> a[i] >> b[i];
			c[a[i]] = i;
			c[b[i]] = i;
		}
		if (s[i] == "NOT" || s[i] == "IN") {
			cin >> a[i];
			c[a[i]] = i;
		}
	}
	int z = calc(1);
	for (int i = 1; i <= n; i++) {
		if (s[i] != "IN") continue;
		int h = change(i) ? 1-z : z;
		cout << h;
	}
	cout << "\n";
}