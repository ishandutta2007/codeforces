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

int N;
list<int>P;
int ans = INT_MAX;

void Search(vector<long long int>v, int p) {
	int cnt = 0;
	for (int i = 0; i < (signed)v.size() - 1; i++) {
		if ((v[i] + p*MOD) % p) {
			long long int box[2] = { v[i] - v[i + 1],v[i] + v[i + 1] };
			v[i] = box[0];
			v[i + 1] = box[1];
			if ((v[i] + p*MOD) % p)return;
			cnt++;
		}
	}
	ans = min(ans, cnt);
}

int main() {
	cin >> N;
	vector<long long int>num(N + 1);
	for (int i = 0; i < N; i++)cin >> num[i];
	P.push_back(2);
	for (int i = 3; i <= sqrt(N); i += 2) {
		bool flag = true;
		for (auto j : P) {
			if (!(i%j)) {
				flag = false;
				break;
			}
		}
		if (flag)P.push_back(i);
	}
	for (int i = 0; i < N; i++) {
		int box = num[i];
		for (auto j : P) {
			while (box % j == 0) {
				box /= j;
			}
		}
		if (box != 1)P.push_back(box);
	}
	for (auto i : P) {
		bool flag = true;
		for (int j = 0; j < N; j++) {
			if (num[j] % i) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << "YES\n";
			cout << "0\n";
			return 0;
		}
	}


	for (int i = 0; i < N; i++) {
		num[i] %= 2;
	}
	ans = 0;
	for (int i = 0; i < N; i++) {
		if (num[i] && num[i + 1]) {
			ans++;
			i++;
		}
		else if (num[i]) {
			ans += 2;
			i++;
		}
	}
	cout << "YES\n";
	cout << ans << endl;
}