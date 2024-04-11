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
	if (N == 0) {
		cout << "zero" << endl;
		return 0;
	}
	vector<string>s(100);
	s[10] = "ten";
	s[11] = "eleven";
	s[12] = "twelve";
	s[13] = "thirteen";
	s[14] = "fourteen";
	s[15] = "fifteen";
	s[16] = "sixteen";
	s[17] = "seventeen";
	s[18] = "eighteen";
	s[19] = "nineteen";
	if (N >= 10 && N < 20) {
		cout << s[N] << endl;
		return 0;
	}
	vector<string>a(10);
	a[2] = "twenty-";
	a[3] = "thirty-";
	a[4] = "forty-";
	a[5] = "fifty-";
	a[6] = "sixty-";
	a[7] = "seventy-";
	a[8] = "eighty-";
	a[9] = "ninety-";
	string ans;
	if (N >= 20)ans += a[N / 10];
	if (N % 10 == 0) {
		ans.pop_back();
		cout << ans << endl;
		return 0;
	}
	vector<string>b(10);
	b[1] = "one";
	b[2] = "two";
	b[3] = "three";
	b[4] = "four";
	b[5] = "five";
	b[6] = "six";
	b[7] = "seven";
	b[8] = "eight";
	b[9] = "nine";
	cout << ans << b[N%10] << endl;
}