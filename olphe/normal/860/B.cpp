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
#include "iomanip"
#include "random"

using namespace std;

const long long int MOD = 1000000007;
const long double EPS = 0.00000001;
const long double PI = 3.1415926535897932384626433;

long long int N, M, K, H, W, L, R;

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);


	scanf("%lld", &N);
	vector<string>s(N);
	map<string, int>m;
	//cout << N << endl;
	for (int i = 0; i < N; i++) {
		char c[10];
		scanf("%s", c);
		for (int j = 0; j < 9; j++) {
			s[i].push_back(c[j]);
		}
		for (int j = 1; j <= 9; j++) {
			for (int k = 0; k + j <= 9; k++) {
				string t;
				for (int l = k; l < k + j; l++) {
					t.push_back(s[i][l]);
				}
				m[t]++;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		map<string,int>box;
		for (int j = 1; j <= 9; j++) {
			for (int k = 0; k + j <= 9; k++) {
				string t;
				for (int l = k; l < k + j; l++) {
					t.push_back(s[i][l]);
				}
				box[t]++;
			}
		}
		string ans = "1234567890";
		for (auto j : box) {
			if (j.second == m[j.first]) {
				if (ans.size() > j.first.size()) {
					ans = j.first;
				}
			}
		}
		printf("%s\n", ans.c_str());
	}
	return 0;
}