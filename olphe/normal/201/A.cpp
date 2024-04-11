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


long long int N;
long long int ans;
long long int H, W;
long long int K;


int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	if (N == 3) {
		cout << "5\n";
		return 0;
	}
	for (int i = 1; i < 100; i+=2) {
		if ((i*i + 1) / 2 >= N) {
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}