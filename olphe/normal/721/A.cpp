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
#include "ctime"

using namespace std;

//const long long int MOD = 1000000007;
const long long  int MOD = 998244353;

//long long int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	string s;
	cin >> s;
	vector<int>ans;
	int cnt = 0;
	for (auto i : s) {
		if (i == 'B')cnt++;
		else if (cnt) {
			ans.push_back(cnt);
			cnt = 0;
		}
	}
	if (cnt)ans.push_back(cnt);
	cout << ans.size() << endl;
	for (auto i : ans)cout << i << " ";
	cout << endl;
	return 0;
}