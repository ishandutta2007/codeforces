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
list<long long int> Prime(int M) {
	list<long long int>P;
	P.push_back(2);
	P.push_back(3);
	for (int i = 5; i <= M; i += 6) {
		bool flag = true;
		for (auto j : P) {
			if (i%j == 0) {
				flag = false;
				break;
			}
		}
		if (flag)P.push_back(i);
		flag = true;
		for (auto j : P) {
			if ((i + 2) % j == 0) {
				flag = false;
				break;
			}
		}
		if (flag)P.push_back(i + 2);
	}
	return P;
}

long long int N,K;

long long int num[100001];
long long int box[100001];

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> K;
	for (int i = 0; i < N; i++)cin >> num[i];
	for (int i = 0; i < K; i++)cin >> box[i];
	if (K != 1) {
		cout << "YES\n";
		return 0;
	}
	for (int i = 0; i < N; i++) {
		if (num[i] == 0)num[i] = box[0];
	}
	for (int i = 0; i < N-1; i++) {
		if (num[i] > num[i + 1]) {
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
	return 0;
}