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
constexpr long double EPS = 1e-12;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

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

XorShift xs;


/* debug
queue<int>Q;
vector<int>used;
vector<int>judge;

int ans = 0;

void Generate() {
	while (!Q.empty())Q.pop();
	for (int i = 0; i < N; i++) {
		judge.push_back(xs.rand() % N);
	}
	used.resize(N, 0);
	for (auto &i : used)i = 0;
	set<int>s;
	for (auto i : judge)s.insert(i);
	//for (auto i : judge)cout << i << " ";
	//cout << endl;
	//cout << s.size() << endl;
	ans = s.size();
}

bool Exist(int num) {
	Q.push(judge[num]);
	used[judge[num]]++;
	bool flag;
	if (used[judge[num]]>1)flag = true;
	else flag = false;
	if (Q.size() > K) {
		used[Q.front()]--;
		Q.pop();
	}
	return flag;
}

void Reset() {
	while (!Q.empty())Q.pop();
	for (auto &i : used)i = 0;
	return;
}

void Answer(vector<int>&v) {
	//cout << "! " << accumulate(v.begin(), v.end(), 0) << endl;
	if (ans != accumulate(v.begin(), v.end(), 0)) {
		cout << ans << " " << accumulate(v.begin(), v.end(), 0) << endl;
		for (auto i : judge)cout << i << " ";
		cout << endl;
	}
	judge.clear();
	return;
}
//*/


//*
bool Exist(int num) {
	cout << "? " << num + 1 << endl;
	char ret;
	cin >> ret;
	if (ret == 'Y')return true;
	else return false;
}

void Reset() {
	cout << "R" << endl;
	return;
}

void Answer(vector<int>&v) {
	cout << "! " << accumulate(v.begin(), v.end(), 0) << endl;
	return;
}

//*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < 100; i++)xs.rand();
	L = 1;
	while (L--) {
	//	Generate();
		vector<int>v(N, 1);
		for (int i = 0; i < N; i += K) {
			for (int j = K - 1; j >= 0; j--) {
				if (Exist(i + j)) {
					v[i + j] = 0;
				}
			}
			Reset();
		}
		for (int loop = K; loop < N; loop <<= 1) {
			for (int i = 0; i < N; i += loop * 2) {
				for (int j = 0; j < loop; j += K) {
					int lst = i + j + loop;
					int led = lst + K - 1;
					for (int k = 0; k < loop; k += K) {
						int rst = i + k;
						for (int l = 0; l < K; l++) {
							if (v[lst + l]) {
								Exist(lst + l);
							}
							else {
								Exist(led);
							}
						}
						int red = -1;
						for (int l = 0; l < K; l++) {
							if (v[rst + l]) {
								red = rst + l;
							}
						}
						if (red == -1) {
							Reset();
							continue;
						}
						red = -1;
						for (int l = 0; l < K; l++) {
							if (v[rst + l]) {
								if (Exist(rst + l)) {
									v[rst + l] = 0;
								}
							}
							else {
								Exist(led);
							}
							if (v[rst + l]) {
								red = rst + l;
							}
						}
						if (red == -1) {
							Reset();
							continue;
						}
						Exist(red);
						for (int l = 0; l < K - 1; l++) {
							if (v[lst + l]) {
								if (Exist(lst + l)) {
									v[lst + l] = 0;
								}
							}
							else {
								Exist(red);
							}
						}
					}
				}
			}
		}
		Answer(v);
	}
	return 0;
}