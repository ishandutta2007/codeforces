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

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N);
	vector<int>place(N + 1);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		place[v[i]] = i;
	}
	vector<int>bob(N+1, 0);
	bob[N] = 1;
	for (int i = N - 1; i >= 1; i--) {
		int box = 0;
		for (int j = place[i];j < N; j += i) {
			box |= bob[v[j]];
		}
		for (int j = place[i]; j >= 0; j -= i) {
			box |= bob[v[j]];
		}
		bob[i] = box ^ 1;
	}
	for (int i = 0; i < N; i++) {
		if (bob[v[i]])cout << 'B';
		else cout << 'A';
	}
	cout << endl;
	return 0;
}