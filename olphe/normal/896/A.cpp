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
#include "cmath"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

string s = { "What are you doing at the end of the world? Are you busy? Will you save us?" };
string t = { "What are you doing while sending " };
string u = { "? Are you busy? Will you send " };
string v = { "?" };

long long int length[55] = {};

char search(int n, long long int p) {
	if (!n) {
		return s[p];
	}
	if (p < t.size()) {
		return t[p];
	}
	if (p < t.size() + length[n - 1]) {
		return search(n - 1, p - t.size());
	}
	if (p < t.size() + length[n - 1] + u.size()) {
		return u[p - t.size() - length[n - 1]];
	}
	if (p < t.size() + length[n - 1] + u.size() + length[n - 1]) {
		return search(n - 1, p - t.size() - length[n - 1] - u.size());
	}
	return v[p - t.size() - length[n - 1] - u.size() - length[n - 1]];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	t.push_back('"');
	u = '"' + u;
	u.push_back('"');
	v = '"' + v;
	cin >> N;
	length[0] = s.size();
	for (int i = 1; i <= 54; i++) {
		length[i] = t.size() + length[i - 1] + u.size() + length[i - 1] + v.size();
		if (length[i] > 1000000000000000000) {
			break;
		}
	}
	string ans;
	for (int i = 0; i < N; i++) {
		cin >> M >> K;
		K--;
		if (M > 53) {
			if (M*t.size() > K) {
				ans.push_back(t[K%t.size()]);
			}
			else {
				ans.push_back(search(53, K - (M-53)*t.size()));
			}
		}
		else {
			if (length[M] <= K) {
				ans.push_back('.');
			}
			else {
				ans.push_back(search(M, K));
			}
		}
	}
	cout << ans << endl;
	return 0;
}