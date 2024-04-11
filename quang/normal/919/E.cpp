#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int a, b, p;
long long x;
int apow[N];
vector<int> id[N];

inline int add(int u, int v) {u += v; if (u >= p) u -= p; return u;}
inline int sub(int u, int v) {u -= v; if (u < 0) u += p; return u;}
inline int mul(int u, int v) {return (long long)u * v % p;}
inline int power(int u, int v) {int res = 1; while (v) {if (v & 1) res = mul(res, u); u = mul(u, u); v >>= 1;} return res;}
inline int rev(int u) {return power(u, p - 2);}

int main() {
	cin >> a >> b >> p >> x;
	apow[0] = 1;
	id[1].push_back(0);
	for (int i = 1; i < p - 1; i++) {
		apow[i] = mul(apow[i - 1], a);
		id[apow[i]].push_back(i);
	}
	long long res = 0;
	for (int i = 1; i < p; i++) {
		int val = mul(b, rev(i));
		long long kmax = x - i >= 0 ? (x - i) / p : -(1ll << 40);
		for (int j : id[val]) {
			long long foo = 0;
			if (kmax + i - j >= 0) {
				foo += (kmax + i - j) / (p - 1) + 1;
			}
			if (i - j > 0) {
				foo -= (i - j - 1) / (p - 1) + 1;
			}
			res += max(0ll, foo);
			// if (i == 8174) {
			// 	cout << j << " " << kmax << endl;
			// 	cout << (kmax + i - j) / (p - 1) + 1 << endl;
			// 	cout << (i - j - 1) / (p - 1) + 1 << endl;
			// }
		}	
	}
	cout << res << endl;
	return 0;
}