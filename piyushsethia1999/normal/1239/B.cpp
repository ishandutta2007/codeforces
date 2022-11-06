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

int cn[300005];
int l, r;
int ans(string s) {
	// print(s);
	int n = s.size();
	int ans1 = 0;
	int tocn1 = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') {
			cn[i + 1] = cn[i] + 1;
		} else
			cn[i + 1] = cn[i] - 1;
		if (cn[i + 1] == 0) ans1++;
		if (cn[i + 1] == 1) tocn1++;
	}
	l = r = 0;
	int ans2 = ans1;
	for (int i = 0; i < n; ++i) {
		if (cn[i] == 1 && s[i] == '(') {
			int j = i + 1;
			int cn2 = 0;
			while (j <= n && cn[j] > 1) {
				if (cn[j] == 2) cn2++;
				j++;
			}
			if (j > n) {
				break;
			}
			if (j <= n) {
				if (ans1 + cn2 >= ans2) {
					ans2 = ans1 + cn2;
					l = i, r = j - 1;
				}
			}
			i = j - 1;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (cn[i] == 0 && s[i] == '(') {
			int j = i + 1;
			int cn2 = 0;
			while (j <= n && cn[j] > 0) {
				if (cn[j] == 1) cn2++;
				j++;
			}
			if (j > n) {
				break;
			}
			if (j <= n) {
				if (cn2 >= ans2) {
					ans2 = cn2;
					l = i, r = j - 1;
				}
			}
			i = j - 1;
		}
	}


	// print(pair(cn, n + 1));
	// print();
	if (ans1 == 1) {
		if (tocn1 >= ans2) {
			l = 0;
			r = n - 1;
			return tocn1;
		}
		return ans2;
	}
	return ans2;
}

void test(int n, string s) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	// int n;
	// cin >> n;
	// string s;
	// cin >> s;
	int mi = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') {
			cn[i + 1] = cn[i] + 1;
		} else
			cn[i + 1] = cn[i] - 1;
		if (cn[mi] > cn[i + 1])
			mi = i + 1;
	}
	// print(cn[n]);
	if (cn[n] != 0) {
		cout << "0\n1 1";
		return;
	}
	int an = ans(s.substr(mi) + s.substr(0, mi));
	// print(l, r);
	// return an;
	cout << an << "\n";
	if (l < n - mi) {
		l += mi;
	} else {
		l -= (n - mi);
	}
	if (r < n - mi) {
		r += mi;
	} else {
		r -= (n - mi);
	}
	cout << l + 1 << " " << r + 1 << "\n";
}

int an(string& s, int n) {
    int mi = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            cn[i + 1] = cn[i] + 1;
        } else
            cn[i + 1] = cn[i] - 1;
        if (cn[mi] > cn[i + 1])
            mi = i + 1;
    }
    mi = cn[mi];
    int u = 0;
    for (int i = 0; i < n; ++i) {
        if (cn[i] == mi) {
            u++;
        } 
    }
    return u;
}

void test2(int n, string s, int ans) {
	int mi = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') {
			cn[i + 1] = cn[i] + 1;
		} else
			cn[i + 1] = cn[i] - 1;
		if (cn[mi] > cn[i + 1])
			mi = i + 1;
	}
	// int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = i; j < n; ++j) {
			swap(s[i], s[j]);
			int ans2 = an(s, n);
			swap(s[i], s[j]);
			// print(ans2);
			if (ans2 == ans) {
				print(i + 1, j + 1);
				return;
			} 
		}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n;
	string s;
	// int ans;
	cin >> n >> s;// >> ans;
	test(n, s);
	// if (test(n, s) != ans) {
	// 	print(n, s, ans, test(n, s));
	// 	test2(n, s, ans);
	// }
}