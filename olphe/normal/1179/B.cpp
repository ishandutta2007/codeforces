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

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 998244353;
//const long long int MOD = 998244353;
const double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
 
	cin >> H >> W;
	if (H % 2 == 0) {
		vector<pair<int, int>>ans;
		for (int i = 0; i < H / 2; i++) {
			for (int j = 0; j < W; j++) {
				ans.push_back({ i,j });
				ans.push_back({ H - i - 1,W - 1 - j });
			}
		}
		for (auto i : ans) {
			cout << i.first + 1 << " " << i.second + 1 << "\n";
		}
	}
	else {
		vector<pair<int, int>>ans;
		for (int i = 0; i < W / 2; i++) {
			ans.push_back({ 0,i });
			ans.push_back({ 0,W - i - 1 });
		}
		if (W & 1) {
			ans.push_back({ 0,W / 2 });
		}
		for (int i = 1; i <= H / 2; i++) {
			for (int j = 0; j < W; j++) {
				ans.push_back({ H - i,W - 1 - j });
				ans.push_back({ i,j });
			}
		}
		for (auto i : ans) {
			cout << i.first + 1 << " " << i.second + 1 << "\n";
		}
	}
}