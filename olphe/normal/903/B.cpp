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
#include "iomanip"
#include "cmath"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	cin >> H >> W;
	vector<string> ans;
	while (H > 0) {
		if (H <= M) {
			ans.push_back("STRIKE");
			H -= M;
		}
		else if (N <= W) {
			ans.push_back("HEAL");
			N += K;
		}
		else {
			ans.push_back("STRIKE");
			H -= M;
		}
		N -= W;
	}
	cout << ans.size() << endl;
	for (auto i : ans) {
		cout << i << endl;
	}
	return 0;
}