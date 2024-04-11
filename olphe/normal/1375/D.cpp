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
constexpr double EPS = 1e-9;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while (K--) {
		cin >> N;
		vector<int>v(N);
		vector<int>num(N + 1);
		for (int i = 0; i < N; i++) {
			cin >> v[i];
			num[v[i]]++;
		}
		set<int>st;
		for (int i = 0; i <= N; i++) {
			if (num[i] == 0)st.insert(i);
		}
		vector<int>ans;
		int nx = 0;
		while (1) {
			bool ed = true;
			if (*st.begin() == N) {
				for (int i = 0; i < N; i++) {
					if (v[i] != i) {
						ed = false;
						ans.push_back(i);
						int n = *st.begin();
						st.erase(n);
						num[n]++;
						num[v[i]]--;
						if (num[v[i]] == 0) {
							st.insert(v[i]);
						}
						v[i] = n;
						break;
					}
				}
			}
			else {
				int n = *st.begin();
				ans.push_back(n);
				st.erase(n);
				num[n]++;
				num[v[n]]--;
				if (num[v[n]] == 0) {
					st.insert(v[n]);
				}
				v[n] = n;
				ed = false;
			}
			if (ed)break;
		}
		//for (auto i : v)cout << i << " ";
		//cout << endl;
		cout << ans.size() << endl;
		for (auto i : ans) {
			cout << i + 1 << " ";
		}
		cout << endl;
	}

}