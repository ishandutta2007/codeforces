#include "iostream"
#include "vector"
#include "algorithm"

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

	cin >> N >> M;
	vector<string>s(N);
	for (auto& i : s)cin >> i;
	for (int i = 0; i < M; i++) {
		cin >> K;
		vector<int>box(256);
		for (int j = 0; j < N; j++) {
			box[s[j][i]] ++;
		}
		H += K * (*max_element(box.begin(), box.end()));
	}
	cout << H << endl;
	return 0;
}