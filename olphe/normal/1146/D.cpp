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

//const long long int MOD = 1000000007;
const int MOD = 1000000007;
//const int MOD = 998244353;
//const long long int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R;

int gcd(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	if (M == 1) {
		cout << (N+2) * (N + 1) / 2 << endl;
		return 0;
	}
	long long int ans = 2;
	unordered_set<int>s;
	long long int index = 2;
	s.insert(0);
	int g = gcd(M, K);
	while (s.size() < index&&index <= N) {
		auto it = s.find(index - M);
		if (it == s.end()) {
			ans += s.size();
		}
		else {
			queue<int>Q;
			Q.push(index);
			s.insert(index);
			while (!Q.empty()) {
				int cn = Q.front();
				Q.pop();
				if (cn + M <= index && s.find(cn + M) == s.end()) {
					Q.push(cn + M);
					s.insert(cn + M);
				}
				if (cn - K > 0 && s.find(cn - K) == s.end()) {
					Q.push(cn - K);
					s.insert(cn - K);
				}
			}
			s.insert(index);
			for (int i = index - K; i > 0; i -= K)s.insert(i);
			ans += s.size();
		}
		//cout << index << " " << s.size() << endl;
		if (index%g == 0) {
			if (index / g + 1 == s.size()) {
				index++;
				break;
			}
		}
		index++;
	}
	ans += (N / g+2)*(N / g + 1) / 2 * g;
	ans -= (index / g)*(index / g + 1) / 2 * g;
	ans -= (N / g+1) * (g - 1 - (N%g));
	ans -= (index / g+1) * (index%g);
	cout << ans << endl;
	return 0;
}