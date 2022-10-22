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
#include "bitset"

using namespace std;

//const long long int MOD = 998244353;
const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	cout << "1 0" << endl;
	string s;
	cin >> s;
	if (N == 1) {
		cout << "0 0 1 1" << endl;
		return 0;
	}
	string t;
	cout << "1 1" << endl;
	cin >> t;
	if (N == 2) {
		if (s == t) {
			cout << "0 0 0 1" << endl;
			return 0;
		}
		else {
			cout << "0 0 2 1" << endl;
			return 0;
		}
	}
	int nx = 2;
	int ny = 1;
	if (s == t)ny += 2;
	for (int i = 2; i < N; i++) {
		cout << nx << " " << ny << endl;
		cin >> t;
		if (i == N - 1) {
			nx *= 3;
			nx /= 2;
			ny *= 3;
			ny /= 2;
			if (t == s)ny++;
			continue;
		}
		nx *= 2;
		ny *= 2;
		if (t == s)ny++;
		else ny--;
	}
	cout << "0 0 " << nx << " " << ny << endl;
	return 0;
}