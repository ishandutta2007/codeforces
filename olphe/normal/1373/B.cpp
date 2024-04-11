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
constexpr double EPS = 1e-9;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while (K--) {
		string s;
		cin >> s;
		int num = 0;
		while (1) {
			bool flag = false;
			if (s.find("01") != s.npos) {
				s = s.substr(0, s.find("01")) + s.substr(s.find("01") + 2, s.size() - s.find("01") - 2);
				flag = true;
				num++;
			}
		//	cout << s << endl;
			if (s.find("10") != s.npos) {
				s = s.substr(0, s.find("10")) + s.substr(s.find("10") + 2, s.size() - s.find("10") - 2);
				flag = true;
				num++;
			}
		//	cout << s << endl;
			if (!flag)break;
		}
		if (num & 1)cout << "DA\n";
		else cout << "NET\n";
	}
}