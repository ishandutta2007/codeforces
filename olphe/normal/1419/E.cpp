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

//constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> N;
		vector<pair<int, int>>vp;
		for (int i = 2; i*i <= N; i++) {
			if (N%i == 0) {
				int cnt = 0;
				while (N%i == 0) {
					N /= i;
					cnt++;
				}
				vp.push_back({ i,cnt });
			}
		}
		if (N > 1) {
			vp.push_back({ N,1 });
		}
		vector<int>ans;
		ans.push_back(1);
		for (int i = 0; i < vp[0].second; i++) {
			ans.push_back(ans.back()*vp[0].first);
		}
		for (int i = 1; i < vp.size(); i++) {
			auto box = ans;
			reverse(box.begin(), box.end());
			long long int by = vp[i].first;
			for (int j = 0; j < vp[i].second; j++) {
				for (auto k : box) {
					ans.push_back(k*by);
				}
				by *= vp[i].first;
				reverse(box.begin(), box.end());
			}
		}
		ans.erase(ans.begin());
		swap(ans[ans.size() - 2], ans.back());
		for (auto i : ans)cout << i << " ";
		cout << endl;
		if (ans.size() == 3 && vp.size() == 2)cout << 1 << endl;
		else cout << 0 << endl;
	}
}