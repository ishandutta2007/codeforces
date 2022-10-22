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

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R

vector<vector<long long int>>mtpow(vector<vector<long long int>>&mt, long long int num) {
	vector<vector<long long int>>ret(mt.size(),vector<long long int>(mt.front().size(),-1));
	long long int bag = 1;
	while (bag <= num) {
		if (bag&num) {
			if (ret[0][0] == -1)ret = mt;
			else {
				vector<vector<long long int>>bag = ret;
				for (int i = 0; i < mt.size(); i++) {
					for (int j = 0; j < mt.size(); j++) {
						ret[i][j] = 0;
						for (int k = 0; k < mt.size(); k++) {
							ret[i][j] += mt[i][k] * bag[k][j];
							ret[i][j] %= MOD;
						}
					}
				}
			}
		}
		bag <<= 1;
		vector<vector<long long int>>bag = mt;
		for (int i = 0; i < mt.size(); i++) {
			for (int j = 0; j < mt.size(); j++) {
				mt[i][j] = 0;
				for (int k = 0; k < mt.size(); k++) {
					mt[i][j] += bag[i][k] * bag[k][j];
					mt[i][j] %= MOD;
				}
			}
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> L >> R;
	vector<int>v(10);
	for (int i = 0; i < N; i++) {
		cin >> K;
		v[K]++;
	}
	vector<vector<long long int>>mt(R, vector<long long int>(R));
	for (int i = 0; i < R; i++) {
		for (int j = 1; j < 10; j++) {
			mt[(i * 10 + j) % R][i] += v[j];
		}
	}
	auto w = mtpow(mt, M);
	cout << w[L][0] << endl;
	return 0;
}