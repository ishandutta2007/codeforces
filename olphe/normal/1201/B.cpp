#include "iostream"
#include "vector"
#include "algorithm"
#include "numeric"

using namespace std;

//int N,M,K,L,R,H,W;
long long int N, M, K, L, R, H, W;

//constexpr long long int MOD=1000000007;
constexpr long long int MOD = 1000000007;
//constexpr int MOD=998244353;
//constexpr long long int MOD=998244353;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<long long int>v(N);
	for (auto& i : v)cin >> i;
	K = accumulate(v.begin(), v.end(),0LL);
	if (K & 1) {
		cout << "NO" << endl;
		return 0;
	}
	if (*max_element(v.begin(), v.end()) * 2 > K) {
		cout << "NO" <<endl;
		return 0;
	}
	cout << "YES" << endl;
	return 0;
}