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
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr long double EPS = 1e-8;

long long int N, M, K, L, R, H, W;
//int N, M, K, L, R, H, W;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while (K--) {
		cin >> N >> M;
		vector<int>v(1 << N);
		for (int i = 1; i < 1 << N; i++)cin >> v[i];
		int cnt = 0;
		vector<int>sum(1 << N, 1);
		vector<int>fsum(1 << M, 1);
		for (int i = (1 << (N - 1))-1; i > 0; i--)sum[i] += sum[i * 2] + sum[i * 2 + 1];
		for (int i = (1 << (M - 1))-1; i > 0; i--)fsum[i] += fsum[i * 2] + fsum[i * 2 + 1];
		while (fsum.size() < sum.size())fsum.push_back(0);
		vector<int>ans;
		for (int i = 1; i < 1 << M; i++) {
			bool flag = true;
			while (flag) {
				int cnt = i;
				while (cnt < (1 << N) && v[cnt]) {
					flag &= sum[cnt] > fsum[cnt];
					if (cnt * 2 >= v.size())break;
					if (v[cnt * 2] > v[cnt * 2 + 1]) {
						cnt *= 2;
					}
					else {
						cnt = cnt * 2 + 1;
					}
				}
				if (flag) {
					ans.push_back(i);
					cnt = i;
					while (cnt < (1 << N) && v[cnt]) {
						v[cnt] = 0;
						sum[cnt]--;
						if (cnt * 2 >= v.size())break;
						if (v[cnt * 2] > v[cnt * 2 + 1]) {
							cnt *= 2;
						}
						else {
							cnt = cnt * 2 + 1;
						}
						v[cnt / 2] = v[cnt];
					}
				}
				//for (auto j : v)cout << j << " ";
				//cout << endl;
			}
		}
		cout << accumulate(v.begin(), v.end(), 0LL) << endl;
		for (auto i : ans)cout << i << " ";
		cout << endl;
	}
}