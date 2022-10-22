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
#include "iomanip"
#include "random"

using namespace std;

const long long int MOD = 1000000007;
const long double EPS = 0.00000001;
const long double PI = 3.1415926535897932384626433;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>ans;
	for (int i = max(0,(int)N-100); i <=N; i++) {
		int box = i;
		int bag = i;
		while (box) {
			bag += box % 10;
			box /= 10;
		}
		if (bag == N) {
			ans.push_back(i);
		}
	}
	cout << ans.size() << endl;
	for (auto i : ans) {
		cout << i << endl;
	}
	return 0;
}