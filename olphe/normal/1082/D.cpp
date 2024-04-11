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

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 998244353;

//long long int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N + 1);
	vector<int>leaf;
	vector<int>other;
	int add = 0;
	for (int i = 1; i <= N; i++) {
		cin >> v[i];
		if (v[i] == 1) {
			leaf.push_back(i);
		}
		else {
			other.push_back(i);
			add += v[i] - 2;
		}
	}
	add += 2;
	if (add < leaf.size()) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES ";
	if (leaf.size() < 2) cout << other.size() + leaf.size() -1<< endl;
	else cout << other.size() + 1 << endl;
	cout << N - 1 << endl;
	vector<pair<int, int>>edge;
	for (int i = 1; i < other.size(); i++)edge.push_back({ other[i - 1],other[i] });
	for (int i = 0; i < other.size(); i++) {
		v[other[i]] -= 2;
	}
	if (!leaf.empty()) {
		edge.push_back({ other[0],leaf.back() });
		leaf.pop_back();
	}
	if (!leaf.empty()) {
		edge.push_back({ other.back(),leaf.back() });
		leaf.pop_back();
	}
	while (!leaf.empty()) {
		while (!v[other.back()])other.pop_back();
		v[other.back()]--;
		edge.push_back({ other.back(),leaf.back() });
		leaf.pop_back();
	}
	for (auto i : edge)cout << i.first << " " << i.second << endl;
}