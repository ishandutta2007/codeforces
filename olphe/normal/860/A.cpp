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
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	N = s.size();
	vector<string>ret;
	int box = 0;
	for (int i = 0; i < N; i++) {
		if (s[i] == 'a' || s[i] == 'i' || s[i] == 'u' || s[i] == 'e' || s[i] == 'o') {
			box = 0;
		}
		else {
			box++;
		}
		if (box >= 3) {
			if (s[i] == s[i - 1] && s[i] == s[i - 2])continue;
			string t;
			for (int j = L; j < i; j++) {
				t.push_back(s[j]);
			}
			ret.push_back(t);
			L = i;
			box = 1;
		}
	}
	string t;
	for (int i = L; i < N; i++) {
		t.push_back(s[i]);
	}
	ret.push_back(t);
	for (auto i : ret) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}