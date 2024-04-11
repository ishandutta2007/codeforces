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

long long int N,K,Q;

string s;
int num[26][2501];
int sum[26][2501];
int ans[26][2501];

int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	cin >> s;
	cin >> Q;
	int box = 1;
	for (auto i : s) {
		num[i - 'a'][box]++;
		box++;
	}
	for (int i = 0; i < 26; i++) {
		for (int j = 1; j <= N; j++) {
			sum[i][j] = sum[i][j - 1] + num[i][j];
		}
	}
	//for (int i = 0; i <= N; i++)cout << sum[0][i] << endl;
	for (int i = 0; i < 26; i++) {
		for (int j = 1; j <= N; j++) {
			int r = 1;
			for (int k = 0; k < N; k++) {
				while ((r - k) - (sum[i][r] - sum[i][k]) <= j) {
					ans[i][j] = max(ans[i][j], r - k);
					if (r == N)break;
					r++;
				}
			}
		}
	}
	for (int i = 0; i < Q; i++) {
		char fav;
		cin >> box;
		cin >> fav;
		cout << ans[fav - 'a'][box] << endl;
	}
	return 0;
}