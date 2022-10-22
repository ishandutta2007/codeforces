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

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

struct RollingHash {
	unsigned long long int mod61 = (1LL << 61) - 1;
	unsigned long long int Mul61(unsigned long long int a, unsigned long long int b) {
		unsigned long long int au = a >> 31;
		unsigned long long int ad = a ^ (au << 31);
		unsigned long long int bu = b >> 31;
		unsigned long long int bd = b ^ (bu << 31);
		unsigned long long int ret = au * bu * 2;
		ret += ad * bd;
		unsigned long long int mid = ad * bu + au * bd;
		unsigned long long int midu = mid >> 30;
		unsigned long long int midd = mid & ((1 << 30) - 1);
		ret += midu + (midd << 31);
		return ret;
	}
	unsigned long long int CalcMod61(unsigned long long int num) {
		return num % mod61;
	}
	int num;
	vector<unsigned long long int>h;
	vector<unsigned long long int>by;
	RollingHash(string s, unsigned int base = 10007) {
		num = s.size();
		h.resize(s.size() + 1);
		by.resize(s.size() + 1, 1);
		for (int i = 1; i <= num; i++) {
			by[i] = CalcMod61(Mul61(by[i - 1], base));
			h[i] = CalcMod61(Mul61(h[i - 1], base) + s[i - 1]);
		}
	}
	unsigned long long int Get(int l, int r) {
		return CalcMod61(h[r] + mod61 * 4 - Mul61(h[l], by[r - l]));
	}
};

void Solve() {
	cin >> K;
	map<string, vector<string>>mp;
	for (int i = 0; i < K; i++) {
		string s;
		cin >> s;
		auto t = s;
		sort(t.begin(), t.end());
		mp[t].push_back(s);
	}
	long long int ans = 0;
	for (auto& i : mp) {
		sort(i.second.begin(), i.second.end());
		ans += i.second.size() * (K - i.second.size()) * 1337;
	}
	ans /= 2;
	vector<int>lst(333333, -1);
	int cnt = 0;
	for (auto &i : mp) {
		cnt++;
		if (i.second.size() <= 3000) {
			for (int j = 0; j < i.second.size(); j++) {
				for (int k = j + 1; k < i.second.size(); k++) {
					int add = 1;
					int l = MOD;
					int r = -MOD;
					for (int p = 0; p < i.first.size(); p++) {
						if (i.second[k][p] != i.second[j][p]) {
							l = min(l, p);
							r = max(r, p);
						}
					}
					for (int p = l + 1; p <= r; p++) {
						if (i.second[j][p] < i.second[j][p - 1]) {
							add = 2;
							break;
						}
					}
					ans += add;
				}
			}
		}
		else {
			map<pair<unsigned long long int, unsigned long long int>, int>box;
			for (int j = 0; j < i.second.size(); j++) {
				cnt++;
				ans += j * 2;
				RollingHash rh(i.second[j]);
				for (int p = 0; p < i.first.size(); p++) {
					for (int q = 0; p + q < i.first.size(); q++) {
						auto a = rh.Get(0, p);
						auto b = rh.Get(i.first.size() - q, i.first.size());
						if (box.find({ a,b }) != box.end()) {
							if (lst[box[{a, b}]] != cnt) {
								ans--;
								lst[box[{a, b}]] = cnt;
							}
						}
					}
				}
				for (int p = 0; p < i.first.size(); p++) {
					int q = p;
					while (q + 1 < i.first.size() && i.second[j][q] <= i.second[j][q+1]) {
						q++;
						box[{rh.Get(0, p), rh.Get(q + 1, i.first.size())}] = j;
					}
				}
			}
		}
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	//cin >> T;
	while (T--) {
		Solve();
	}
}