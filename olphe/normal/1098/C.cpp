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

long long int N, M, K, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	if (M < N * 2 - 1) {
		cout << "No" << endl;
		return 0;
	}
	if (M > N*(N + 1) / 2) {
		cout << "No" << endl;
		return 0;
	}
	L = 0;
	R = N +10;
	int div = MOD;
	vector<int>ret;
	while (R - L > 1) {
		int mid = (R + L + 1) / 2;
	//	cout << L << " " << R << " " << mid << endl;
		vector<int>ans(N + 1);
		vector<int>v(N + 1, 1);
		v[N] = 0;
		vector<vector<int>>box(N + 1);
		K = N * (N + 1) / 2;
		for (int i = 1; i < N; i++) {
			ans[i] = i;
			box[i].push_back(i);
		}
		int nx = 1;
		if (mid == 1)nx = N;
		for (int i = N - 1; i >= 1; i--) {
			//cout << K << " " << M << endl;
			if (ans[i] <= nx)break;
			if (K - ans[i] + nx >= M) {
				K -= ans[i] - nx;
				v[ans[i]]--;
				ans[i] = box[nx].back();
				box[i].pop_back();
				box[nx + 1].push_back(i + 1);
				v[box[nx].back()]++;
				if (v[box[nx].back()] == mid) {
					box[nx].pop_back();
					if(box[nx].empty())nx++;
				}
			}
			else {
				ans[i] -= K - M;
				K = M;
			}
			if (K == M)break;
		}
		if (K == M) {
			R = mid;
			if (div > mid) {
				div = mid;
				ret = ans;
			}
		}
		else {
			L = mid;
		}
	}
	//cout << div << endl;
	cout << "Yes\n";
	for (int i = 1; i < N; i++) {
		cout << ret[i] << " ";
	}
	cout << endl;
	return 0;
}