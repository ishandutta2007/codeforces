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

long long int N, M, K, W, H, L, R;
long long int ans;



int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	long long int num[200000] = {};
	long long int box[200000] = {};
	for (int i = 0; i < N; i++) {
		cin >> num[i];
		num[i] = num[i] * MOD + i;
	}
	sort(num, num + N);
	for (int i = 0; i < N; i++) {
		cin >> box[i];
		box[i] = box[i] * MOD + i;
	}
	sort(box, box + N);
	reverse(box, box + N);
	long long int ret[200000] = {};
	for (int i = 0; i < N; i++) {
		ret[box[i]%MOD] = num[i] / MOD;
	}
	for (int i = 0; i < N; i++) {
		if (i)cout << " ";
		cout << ret[i];
	}
	cout << endl;
	return 0;
}