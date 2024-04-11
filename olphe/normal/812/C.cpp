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

long long int s;
long long int num[100000];

int main() {
	ios::sync_with_stdio(false);

	cin >> N >> s;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	long long int l = 0;
	long long int r = N;
	while (r - l>1) {
		long long int mid = (l + r) / 2;
		long long int cost[100000] = {};
		for (int i = 0; i < N; i++)cost[i] = num[i] + (i + 1)*mid;
		stable_sort(cost, cost + N);
		long long int sum = 0;
		for (int i = 0; i < mid; i++)sum += cost[i];
		if (sum > s)r = mid - 1;
		else l = mid;
	}
	long long int cost[100000] = {};
	for (int i = 0; i < N; i++)cost[i] = num[i] + (i + 1)*r;
	stable_sort(cost, cost + N);
	long long int sum = 0;
	for (int i = 0; i < r; i++)sum += cost[i];
	if (sum <= s) {
		cout << r << " " << sum << endl;
		return 0;
	}
	for (int i = 0; i < N; i++)cost[i] = num[i] + (i + 1)*l;
	stable_sort(cost, cost + N);
	sum = 0;
	for (int i = 0; i < l; i++)sum += cost[i];
	cout << l << " " << sum << endl;
	return 0;
}