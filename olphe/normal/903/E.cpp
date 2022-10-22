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
#include "iomanip"
#include "cmath"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	vector <string>v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	int a,  b;
	bool flag = false;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++){
			int dif = 0;
			for (int k = 0; k < K; k++) {
				if (v[i][k] != v[j][k]) {
					dif++;
				}
			}
			if (dif > 4 || dif == 1) {
				cout << -1 << endl;
				return 0;
			}
			if (dif) {
				a = i;
				b = j;
				flag = true;
			}
		}
		if (flag) {
			break;
		}
	}
	if (!flag) {
		swap(v[0][0], v[0][1]);
		cout << v[0] << endl;
		return 0;
	}
	vector<int>candidate;
	for (int i = 0; i < K; i++) {
		if (v[a][i] != v[b][i]) {
			candidate.push_back(i);
		}
	}
	for (int i = 0; i < candidate.size(); i++) {
		for (int j = i + i != 0; j < candidate.size(); j++) {
			flag = true;
			string t = v[a];
			bool two = false;
			map<char, int>m;
			for (auto k : t) {
				m[k]++;
				if (m[k] == 2) {
					two = true;
					break;
				}
			}
			swap(t[candidate[i]], t[candidate[j]]);
			for (int k = 0; k < N; k++) {
				L = -1;
				R = -1;
				for (int l = 0; l < K; l++) {
					if (t[l] != v[k][l]) {
						if (L == -1) {
							L = l;
						}
						else if (R == -1) {
							R = l;
						}
						else {
							flag = false;
							break;
						}
					}
				}
				if (L == -1 && two) {
					continue;
				}
				if (R == -1) {
					flag = false;
					break;
				}
				if (t[R] != v[k][L] || t[L] != v[k][R]) {
					flag = false;
					break;
				}
				if (!flag) {
					break;
				}
			}
			if (flag) {
				cout << t << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
	return 0;
}