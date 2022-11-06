#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#ifndef print
#define print(...)
#endif
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }


template<typename T>
class ST
{
	std::vector<std::vector<T> > table;
	T (*Union)(T, T b);
public:
	ST(std::vector<T>& a, T (*u)(T, T));
	T query(int l , int r);
};
template<typename T>
ST<T>::ST(std::vector<T>& a, T (*u)(T, T)) {
	Union = u;
	int n = a.size();
	int k = log2(n);
	table.resize(n, std::vector<T> (k + 1));
	for (int i = 0; i < n; ++i)
		table[i][0] = a[i];
	for (int j = 1; j <= k; ++j)
		for (int i = 0; i < (n + 1 - (1 << j)); ++i)
			table[i][j] = Union(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
}
template<typename T>
T ST<T>::query(int l, int r)
{
	int m = log2(r - l + 1);
	return this->Union(table[l][m], table[r - (1 << m) + 1][m]);
}
std::vector<int> a;
int p[200006];
int mas[200006];

int ans(int i, int n, ST<int>& mi) {
	int val = (a[i] - 1) / 2;
	if (mi.query(i, i + n) > val) return -1; 
	int s = 1, e = n;
	while (s < e) {
		int m = (s + e) / 2;
		if (mi.query(i, i + m) <= val) {
			e = m;
		} else {
			s = m + 1;
		}
	}
	return s;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n;
	cin >> n;
	a.resize(2 * n);
	memset(mas, -1, sizeof(mas));
	for (int i = 0; i < n; ++i) { 
		cin >> a[i];
		a[i + n] = a[i];
	}
	ST<int> mi(a, [](int a, int b) {
		return min(a, b);
	});
	ST<int> ma(a, [](int a, int b) {
		return max(a, b);
	});
	for (int i = 0; i < n; ++i) p[i] = i;
	sort(p, p + n, [](int i, int j) {
		return a[i] > a[j];
	});
	for (int op = 0; op < n; ++op) {
		int i = p[op];
		int s = 1, e = n;
		while (s < e) {
			int m = (s + e) >> 1;
			if (ma.query(i, i + m) > a[i]) {
				e = m;
			} else {
				s = m + 1;
			}
			// print(s, e);
		}
		if (s == n) {
			print(i);
			mas[i] = ans(i, n, mi);
		} else {
			print(i, s);
			int an = ans(i, s - 1, mi);
			if (an == -1 && mas[(i + s) % n] != -1)
				an = s + mas[(i + s) % n];
			mas[i] = an;
		}
		print(i, mas[i]);
	}
	for (int i = 0; i < n; ++i) {
		if (mas[i] == -2) mas[i] = -1; 
		cout << mas[i] << " ";
	}
}