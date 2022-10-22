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

//const long long int MOD = 1000000007;
//const int MOD = 1000000007;
const int MOD = 998244353;
//const long long int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N*2 + 1);
	int cnt = 0;
	while (cnt <= N*2) {
		v[cnt] = 1;
		cnt *= 2;
		cnt++;
	}
	if (v[N]) {
		cout << 0 << endl;
		return 0;
	}
	vector<int>ans;
	if ((N & 1) == 0) {
		ans.push_back(0);
		N++;
	}
	while (!v[N]) {
		//cout << N << endl;
		int index = 1;
		while (1) {
			if (((N >> index) & 1) != ((N >> (index + 1) & 1))) {
				ans.push_back(index+1);
				N ^= (1 << (index+1)) - 1;
				N++;
				break;
			}
			index++;
		}
	}
	cout << ans.size() * 2 << endl;
	for (auto i : ans)cout << i << " ";
	cout << endl;
	return 0;
}