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
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	int zero = 0;
	int five = 0;
	for (int i = 0; i < N; i++) {
		cin >> M;
		if (M)five++;
		else zero++;
	}
	if (!zero) {
		cout << -1 << endl;
		return 0;
	}
	five /= 9;
	five *= 9;
	for (int i = 0; i < five; i++) {
		cout << 5;
	}
	if (!five) {
		if(zero)cout << 0 << endl;
		else cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < zero; i++)cout << 0;
	cout << endl;
}