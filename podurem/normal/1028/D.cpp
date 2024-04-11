#include <bits/stdc++.h>
#define err(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
typedef long long ll;

using namespace std;

const int dd = (int)2e5 + 7;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, p, k = 0;
	cin >> n;
	int B = 0, S = 308983067;
	string s;
	int ans = 1;
	set<int> P;
	while (n--) {
		cin >> s >> p;
		if (s[1] == 'D') {
			if (p > B && p < S) ++k;
			P.insert(p);
		} else {
			if (p > S || p < B) {
				cout << "0\n";
				return 0;
			}
			if (p != B && p != S) ans = ans * 2 % ((int)1e9 + 7);
			k = 0;
			auto L = P.find(p);
			++L;
			if (L != P.end()) S = *L;
			else S = 308983067;
			--L;
			if (L != P.begin()) {
				--L;
				B = *L;
			} else B = 0;
			P.erase(p);
		}
	}
	ans = 1ll * ans * (k + 1) % ((int)1e9 + 7);
	cout << ans << "\n";
	return 0;
}