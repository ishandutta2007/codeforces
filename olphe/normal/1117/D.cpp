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

void Solve(vector<vector<long long int>>&v, vector<long long int>&box, long long int num) {
	if (!num)return;
	vector<vector<vector<long long int>>>mat(65, vector<vector<long long int>>(M, vector<long long int>(M)));
	mat[0] = v;
	for (int i = 1; i < 65; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < M; k++) {
				for (int l = 0; l < M; l++) {
					mat[i][j][k] += mat[i - 1][j][l] * mat[i - 1][l][k];
					mat[i][j][k] %= MOD;
				}
			}
		}
	}
	vector<vector<long long int>>ret(M, vector<long long int>(M,-1));
	for (int i = 0; i < 65; i++) {
		if (num & 1) {
		//	cout << i << endl;
			if (ret[0][0] == -1) {
				ret = mat[i];
				num /= 2;
				continue;
			}
			auto bag = ret;
			for (int j = 0; j < M; j++) {
				for (int k = 0; k < M; k++) {
					ret[j][k] = 0;
					for (int l = 0; l < M; l++) {
						ret[j][k] += bag[j][l] * mat[i][l][k];
						ret[j][k] %= MOD;
					}
				}
			}
		}
		num /= 2;
		if (!num)break;
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
	//		cout << ret[i][j] << " ";
		}
	//	cout << endl;
	}
	//cout << "box" << endl;
	//for (auto i : box)cout << i << endl;
	//cout << endl;
	auto bag = box;
	for (int i = 0; i < M; i++) {
		box[i] = 0;
		for (int j = 0; j < M; j++) {
			box[i] += bag[j] * ret[i][j];
			box[i] %= MOD;
		}
	}
	reverse(box.begin(), box.end());
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<vector<long long int>>v(M, vector<long long int>(M));
	v[0][0] = 1;
	v[0][M - 1] = 1;
	for (int i = 1; i < M; i++)v[i][i - 1] = 1;
	vector<long long int>box(M, 1);
	L = max(0LL, N - M + 1);
	Solve(v, box, L);
	//cout << N - L << endl;
	cout << box[N - L] << endl;
	return 0;
}