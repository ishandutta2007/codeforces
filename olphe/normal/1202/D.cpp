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
#include "cassert"
#include "functional"

using namespace std;

//constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	vector<long long int>box(100001);
	box[2] = 1;
	for (int i = 3; i <= 100000; i++){
		box[i] = box[i - 1] + i - 1;
	}
	while (K--) {
		cin >> N;
		int index = 100000;
		vector<int>num(100001);
		while (N) {
			while (N >= box[index]) {
				num[index]++;
				N -= box[index];
			}
			index--;
		}
		string s;
		s = "13";
		int to = 2;
		for (int i = 2; i <= 100000; i++) {
			if (num[i])to = i;
		}
		for (int i = 2; i <= to; i++) {
			//cout << i << " " << num[i] << endl;
			s.push_back('3');
			for (int j = 0; j < num[i]; j++)s.push_back('7');
		}
		cout << s << endl;
	}
}