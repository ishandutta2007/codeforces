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

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long int sy, sx, gy, gx;
	cin >> sx >> sy;
	cin >> gx >> gy;
	cin >> N;
	string s;
	cin >> s;
	vector<long long int>sum(4);
	vector<int>v;
	for (auto i : s) {
		int num = 0;
		if (i == 'R')num = 1;
		if (i == 'D')num = 2;
		if (i == 'L')num = 3;
		sum[num]++;
		v.push_back(num);
	}
	L = 0;
	R = MOD * MOD;
	while (R - L > 1) {
		long long int mid = (R + L + 1) / 2;
		long long int loop = mid / N;
		long long int amari = mid % N;
		long long int ay = loop * (sum[0] - sum[2]);
		long long int ax = loop * (sum[1] - sum[3]);
		for (int i = 0; i < amari; i++) {
			switch (v[i]) {
			case 0:
				ay++;
				break;
			case 1:
				ax++;
				break;
			case 2:
				ay--;
				break;
			default:
				ax--;
			}
		}
		long long int ny = sy + ay;
		long long int nx = sx + ax;
		//cout << mid << " " << nx << " " << ny << endl;
		if (abs(ny - gy) + abs(nx - gx) > mid)L = mid;
		else R = mid;
	}
	if (R == MOD * MOD)R = -1;
	cout << R << endl;
	return 0;
}