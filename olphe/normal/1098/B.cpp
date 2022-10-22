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

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> H >> W;
	vector<string>s(H);
	for (auto &i : s)cin >> i;
	string v = "ACGT";
	auto ret = s;
	int dif = MOD;
	sort(v.begin(), v.end());
	do {
		int box = 0;
		auto bag = ret;
		for (int i = 0; i < H; i++) {
			char a = v[(i % 2) * 2], b = v[(i % 2) * 2 + 1];
			int c = 0, d = 0;
			for (int j = 0; j < W; j++) {
				if (s[i][j] != a) {
					if (j % 2 == 0)c++;
					else d++;
				}
				if (s[i][j] != b) {
					if (j % 2)c++;
					else d++;
				}
			}
			if (c > d) {
				for (int j = 0; j < W; j++) {
					if (j % 2)bag[i][j] = a;
					else bag[i][j] = b;
				}
			}
			else {
				for (int j = 0; j < W; j++) {
					if (j % 2)bag[i][j] = b;
					else bag[i][j] = a;
				}
			}
			box += min(c, d);
		}
		if (box < dif) {
			dif = box;
			ret = bag;
		}
	} while (next_permutation(v.begin(), v.end()));
//	for (auto i : ret)cout << i << endl;
	sort(v.begin(), v.end());
	do {
		int box = 0;
		auto bag = ret;
		for (int i = 0; i < W; i++) {
			char a = v[(i % 2) * 2], b = v[(i % 2) * 2 + 1];
			int c = 0, d = 0;
			for (int j = 0; j < H; j++) {
				if (s[j][i] != a) {
					if (j % 2 == 0)c++;
					else d++;
				}
				if (s[j][i] != b) {
					if (j % 2)c++;
					else d++;
				}
			}
			if (c > d) {
				for (int j = 0; j < H; j++) {
					if (j % 2)bag[j][i] = a;
					else bag[j][i] = b;
				}
			}
			else {
				for (int j = 0; j < H; j++) {
					if (j % 2)bag[j][i] = b;
					else bag[j][i] = a;
				}
			}
			box += min(c, d);
		}
		if (box < dif) {
			dif = box;
			ret = bag;
		}
	} while (next_permutation(v.begin(), v.end()));
	for (auto i : ret)cout << i << endl;
	return 0;
}