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

	cin >> N;
	string s, t;
	vector<int>flag(26, 0);
	int cand = 26;
	for (int i = 0; i < N; i++) {
		cin >> s >> t;
		vector<int>box(26,0);
		if (s == "!") {
			if (cand == 1) {
				M++;
			}
			for (auto j : t) {
				box[j - 'a'] = 1;
			}
			for (int j = 0; j < 26; j++) {
				if (box[j] != 1) {
					box[j] = -1;
				}
				if (flag[j]==0 && box[j] == -1) {
					cand--;
					flag[j] = -1;
				}
			}
		}
		else if(s=="."){
			for (auto j : t) {
				box[j - 'a'] = -1;
			}
			for (int j = 0; j < 26; j++) {
				if (flag[j]==0 && box[j] == -1) {
					cand--;
					flag[j] = -1;
				}
			}
		}
		else {
			if (cand == 1) {
				if (i != N - 1) {
					M++;
				}
			}
			if (flag[t[0] - 'a'] == 0) {
				flag[t[0] - 'a'] = -1;
				cand--;
			}
		}
	}
	cout << M << endl;
	return 0;
}