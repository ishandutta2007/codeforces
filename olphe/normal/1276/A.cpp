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
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	while (N--) {
		string s;
		cin >> s;
		s = 'A' + s + 'A';
		vector<int>used(s.size());
		int num = 0;
		for (int i = 4; i < s.size(); i++) {
			if (s[i - 4] == 't'&&s[i - 3] == 'w'&&s[i - 2] == 'o'&&s[i - 1] == 'n'&&s[i] == 'e') {
				used[i - 2] = 1;
				num++;
			}
		}
		for (int i = 1; i + 1 < s.size(); i++) {
			if (s[i] == 'w') {
				int l = i - 1;
				int r = i + 1;
				while (used[l])l--;
				while (used[r])r++;
				if (s[l] == 't'&&s[r] == 'o') {
					used[i] = 1;
					num++;
				}
			}
			if (s[i] == 'n') {
				int l = i - 1;
				int r = i + 1;
				while (used[l])l--;
				while (used[r])r++;
				if (s[l] == 'o'&&s[r] == 'e') {
					used[i] = 1;
					num++;
				}
			}
		}
		cout << num << endl;
		for (int i = 0; i < s.size(); i++) {
			if (used[i])cout << i << " ";
		}
		cout << endl;
	}
}