#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
#include "utility"
#include "string"
#include "map"
#include "unordered_map"
#include "iomanip"
#include "random"

using namespace std;
const long long int MOD = 1000000007;

long long int N, M, Q, K;
long long int num;
set<long long int>S;

int main() {
	cin >> N >> M >> Q >> K;
	if (N == 0) {
		for (int i = 0; i < K; i++) {
			cin >> num;
			if (num == 0) {
				cout << "0\n";
				return 0;
			}
		}
		cout << "inf\n";
		return 0;
	}
	if (M == 0) {
		if (abs(N) > Q) {
			cout << "0\n";
			return 0;
		}
		bool flag = false;
		for (int i = 0; i < K; i++) {
			
			cin >> num;
			if (num == 0)flag = true;
			if (num == N)N = 0;
		}
		if (N)N /= N;
		if (flag) {
			cout << N << endl;
			return 0;
		}
		cout << "inf\n";
		return 0;
	}
	if (M == 1) {
		if (abs(N) > Q) {
			cout << "0\n";
			return 0;
		}
		for (int i = 0; i < K; i++) {
			cin >> num;
			if (num == N) {
				cout << "0\n";
				return 0;
			}
		}
		cout << "inf\n";
		return 0;
	}
	if (M == -1) {
		if (abs(N) > Q) {
			cout << "0\n";
			return 0;
		}
		bool flag[2] = {};
		for (int i = 0; i < K; i++) {
			cin >> num;
			if (num == N) flag[0] = true;
			if (num == N*(-1))flag[1] = true;
		}
		if (flag[0] && flag[1]) {
			cout << "0\n";
			return 0;
		}
		cout << "inf\n";
		return 0;
	}
	while (abs(N) <= Q) {
		if (S.count(N))break;
		S.insert(N);
		N *= M;
	}
	for (int i = 0; i < K; i++) {
		cin >> num;
		if (S.count(num)) {
			S.erase(num);
		}
	}
	cout << S.size() << endl;
	return 0;
}