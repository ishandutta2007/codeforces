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

long long int N,K;
long long int num;
long long int ans;

int main() {
	cin >> N>>K;
	for (int i = 0; i < N; i++) {
		cin >> num;
		ans += num / K;
		num %= K;
		if (num)ans++;
	}
	cout << (ans+1)/2 << endl;
	return 0;
}