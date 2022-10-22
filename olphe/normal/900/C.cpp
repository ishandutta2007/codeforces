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

	cin >> N;
	vector<int>v(N);
	vector<int>box(N + 1);
	set<int>s;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		if (s.upper_bound(v[i]) == s.end()) {
			box[v[i]]--;
		}
		else if (*s.upper_bound(v[i]) == *s.rbegin()) {
			box[*s.rbegin()]++;
		}
		s.insert(v[i]);
	}
	int ans = 1;
	for (int i = 2; i <= N; i++) {
		if (box[ans] < box[i]) {
			ans = i;
		}
	}
	cout << ans << endl;
	return 0;
}