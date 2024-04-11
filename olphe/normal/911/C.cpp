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
#include "random"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int>v(3);
	for (int i = 0; i < 3; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	vector<int>flag(100001,0);
	for (int loop = 0; loop < 3; loop++) {
		for (int i = 1; i <= 100000; i++) {
			if (!flag[i]) {
				for (int j = i; j <= 100000; j += v[loop]) {
					flag[j] = 1;
				}
				break;
			}
		}
	}
	for (int i = 1; i <= 100000; i++) {
		if (!flag[i]) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}