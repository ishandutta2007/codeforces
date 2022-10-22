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

//constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

class XorShift {
	unsigned int x, y, z, w, t;
public:
	XorShift() {
		x = 133553533;
		y = 314867339;
		z = 664298413;
		w = 999999937;
		t = 0;
	}
	unsigned int rand() {
		t = x ^ (x << 11);
		x = y;
		y = z;
		z = w;
		w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
		return w & 0x7fffffff;
	}
};

void func(vector<long long int>&v) {
	vector<long long int>nx(N);
	for (int i = 1; i < N; i++) {
		nx[i - 1] = v[i] / 2;
	}
	nx[1] += v[0];
	for (int i = 1; i < N; i++) {
		nx[(i + 1) % N] += v[i] - v[i] / 2;
	}
	v = nx;
}

vector<long long int>v;

void Ask(int num) {
	cout << "? " << num << endl;
	cin >> M;
	//M = v[num - 1];
	//func(v);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	int p = 0;
	XorShift xs;
	v.resize(N, K);
	for (int i = 0; i < 900; i++) {
		int box = xs.rand() % N + 1;
		Ask(box);
		if (M > K) {
			p = box;
		}
	}
	for (int i = 20; i >= 0; i--) {
		if ((1 << i) * 2 <= N) {
			int nxp = p - (1 << i);
			if (nxp <= 0)nxp += N;
			Ask(nxp);
			if (M > K) {
				p = nxp;
			}
		}
	}
	p--;
	if (p <= 0)p += N;
	cout << "! " << p << endl;
}