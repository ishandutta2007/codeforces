#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;

//constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr long double EPS = 1e-8;

struct Manachan
{
	vector< int > radius;

	void build(const string &s)
	{
		radius.resize(s.size());

		int i = 0, j = 0;
		while (i < s.size()) {
			while (i - j >= 0 && i + j < s.size() && s[i - j] == s[i + j]) {
				++j;
			}
			radius[i] = j;
			int k = 1;
			while (i - k >= 0 && i + k < s.size() && k + radius[i - k] < j) {
				radius[i + k] = radius[i - k];
				++k;
			}
			i += k;
			j -= k;
		}
	}

	int operator[](const int k) const
	{
		return (radius[k]);
	}

	size_t size()
	{
		return (radius.size());
	}
};

string func(const string &s) {
	string t = s;
	reverse(t.begin(), t.end());
	int num = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == t[i])num++;
		else break;
	}
	string u;
	u.push_back('#');
	for (auto i : s) {
		u.push_back(i);
		u.push_back('#');
	}
	Manachan mana;
	mana.build(u);
	int st = 0, ans = 0, se = 0;;
	for (int i = 1; i + 1 < u.size(); i++) {
		if (i & 1) {
			int box = mana[i] - 1;
			if (num >= i / 2 - box / 2||num>= (int)s.size() - (i / 2 + box / 2) - 1) {
				int cse = min((i / 2 - box / 2), (int)s.size() - (i / 2 + box / 2) - 1);
				if (box + cse*2 > ans) {
					ans = box + cse*2;
					se = cse;
					st = i;
				}
			}
		}
		else {
			int box = mana[i] - 1;
			if (num >= i / 2 - box / 2 || num >= (int)s.size() - (i / 2 + box / 2)) {
				int cse = min((i / 2 - box / 2), (int)s.size() - (i / 2 + box / 2));
				if (box + cse*2 > ans) {
					ans = box + cse*2;
					se = cse;
					st = i;
				}
			}
		}
	}
	//cout << u << endl;
	int box = mana[st] - 1;
	string ret;
	for (int i = 0; i < se; i++)ret.push_back(s[i]);
	for (int i = st - box + 1; i <= st + box - 1; i += 2)ret.push_back(u[i]);
	for (int i = s.size()-se; i < s.size(); i++)ret.push_back(s[i]);
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int K;
	cin >> K;
	while (K--) {
		string s;
		cin >> s;
		auto ret = func(s);
		reverse(s.begin(), s.end());
		auto box = func(s);
		if (ret.size() >= box.size())cout << ret << "\n";
		else {
			reverse(box.begin(), box.end());
			cout << box << "\n";
		}
	}
}