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

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	N = s.size();
	vector<vector<int>>box(26);
	for (int i = 0; i < N; i++) {
		box[s[i] - 'a'].push_back(i);
	}
	int ans = 0;
	for (int i = 0; i < 26; i++) {
		int add = 0;
		for (int j = 1; j < N; j++) {
			vector<int>bag(26);
			int fig = 0;
			for (int k : box[i]) {
				bag[s[(k + j) % N] - 'a']++;
			}
			for (auto k : bag) {
				if (k == 1) {
					fig++;
				}
			}
			add = max(add, fig);
		}
		ans += add;
	}
	cout << setprecision(15) << (long double)ans / (long double)N << endl;
	return 0;
}