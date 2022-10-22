#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

template<class A, unsigned int sz> ostream& operator<< (ostream& out, ar<A, sz> a) {
	out << '[';
	for (int i = 0; i < sz; ++i) {
		if (i > 0) out << ", ";
		out << a[i];
	}
	return out << ']';
}

const int MOD = 1e9 + 7;

namespace Hashing {

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> BDIST(0.1 * MOD, 0.9 * MOD);
const int base = BDIST(rng);

int ad(int a, int b) {if ((a += b) >= MOD) a -= MOD; return a;}
int sub(int a, int b) {if ((a -= b) < 0) a += MOD; return a;}
int mul(int a, int b) {return (ll)a * b % MOD;}

vector<int> pows = {1};
struct hstring {
	string s;
	vector<int> pre = {0};

	hstring(int x) {pre.reserve(x + 1);}

	void add(string& t) {
		s += t;
		for (char c : t)
			pre.push_back(ad(mul(base, pre.back()), (int)c));
	}
	void extend(int len) {
		while(pows.size() <= len)
			pows.push_back(mul(base, pows.back()));
	}
	int hash(int l, int r) {
		assert(0 <= l && l <= r && r < s.size());
		int len = r - l + 1;
		extend(len);
		return sub(pre[r + 1], mul(pows[len], pre[l]));
	}
};

}

const int mxN = 5000000;
int n;
short ans[mxN];
string s;

string read() {
	static char s[mxN + 1];
	scanf("%s", s);
	return string(s);
}

int main() {
	Hashing::pows.reserve(mxN + 1);
	s = read(); n = s.size();
	Hashing::hstring hs(mxN), hsr(mxN);
	hs.add(s);
	reverse(s.begin(), s.end());
	hsr.add(s);
	ans[0] = 1;
	for (int i = 1; i < n; ++i) {
		if (hs.hash(0, i) == hsr.hash(n - i - 1, n - 1)) {
			//cout << i << "\n";
			ans[i] = ans[(i - 1) / 2] + 1;
		}
	}
	//cout << hs.hash(0, 2) << " " << hsr.hash(4, 6) << "\n";
	printf("%d", accumulate(ans, ans + n, 0));
	return 0;
}