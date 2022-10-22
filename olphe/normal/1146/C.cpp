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


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while (K--) {
		cin >> N;
		vector<int>v;
		if (N == 2) {
			cout << 1 << " " << 1 << " " << 1 << " " << 2 << endl;
			cin >> M;
			cout << -1 << " " << M << endl;
			continue;
		}
		vector<int>u;
		for (int i = 1; i < N; i += 2) {
			u.push_back(i);
		}
		cout << 1 << " " << u.size() << " " << N;
		for (auto i : u)cout << " " << i;
		cout << endl;
		u.clear();
		cin >> L;
		for (int i = 2; i < N; i += 2) {
			u.push_back(i);
		}
		cout << 1 << " " << u.size() << " " << N;
		for (auto i : u)cout << " " << i;
		cout << endl;
		cin >> R;
		int index = 0;
		if (L > R) {
			index++;
		}
		for (int i = 1; i < 7; i++) {
			vector<int>w;
			if (!index) {
				for (int j = index + (1 << i); j < N; j += 1 << (i + 1)) {
					w.push_back(j);
				}
				if (w.empty())break;
				cout << 1 << " " << w.size() << " " << N;
				for (auto j : w)cout << " " << j;
				cout << endl;
				cin >> H;
				if (H == max(L, R))index |= (1 << i);
			}
			else {
				for (int j = index; j < N; j += 1 << (i + 1)) {
					w.push_back(j);
				}
				if (w.empty())break;
				cout << 1 << " " << w.size() << " " << N;
				for (auto j : w)cout << " " << j;
				cout << endl;
				cin >> H;
				if (H != max(L, R))index |= (1 << i);
			}
		}
		vector<int>w;
		for (int i = 1; i <= N; i++)if (i != index)w.push_back(i);
		cout << 1 << " " << N - 1 << " " << index;
		for (auto i : w)cout << " " << i;
		cout << endl;
		cin >> M;
		cout << -1 << " " << M << endl;
	}
	return 0;
}