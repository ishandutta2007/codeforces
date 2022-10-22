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
constexpr double EPS = 1e-9;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	while (N--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a > b)swap(a, b);
		vector<int>box(b*a);
		for (int i = 0; i < a*b; i++) {
			box[i] = i % a != ((i%b) % a);
		}
		vector<long long int>ans;
		auto bag = box;
		for (int i = 1; i < a*b; i++)bag[i] += bag[i - 1];
		while (c--) {
			cin >> L >> R;
			L--;
			long long int ret = 0;
			ret += R / b / a * bag.back();
			ret -= L / a / b * bag.back();
			ret += bag[R % (a*b)];
			ret -= bag[L % (a*b)];
			ans.push_back(ret);
		}
		for (auto i : ans)cout << i << " ";
		cout << endl;
	}
}