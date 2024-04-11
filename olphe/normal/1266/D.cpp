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
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	map<pair<int, int>, long long  int>mp;
	for (int i = 0; i < M; i++) {
		cin >> L >> R >> K;
		L--, R--;
		mp[make_pair(L, R)] += K;
	}
	for (auto &i : mp) {
		auto box = i.first;
		swap(box.first, box.second);
		auto it = mp.find(box);
		if (it == mp.end())continue;
		long long int minus = min(it->second, i.second);
		it->second -= minus;
		i.second -= minus;
	}
	vector<map<int, long long int>>in_edge(N);
	vector<map<int, long long int>>out_edge(N);
	for (auto i : mp) {
		if (i.second) {
		//	cout << i.first.first << " " << i.first.second << endl;
			in_edge[i.first.second][i.first.first] = i.second;
			out_edge[i.first.first][i.first.second] = i.second;
		}
	}
	for (int i = 0; i < N; i++) {
		while (!in_edge[i].empty() && !out_edge[i].empty()) {
			auto init = in_edge[i].begin();
			auto outit = out_edge[i].begin();
			int nxs = init->first;
			int nxt = outit->first;
			long long int minus = min(init->second, outit->second);
			init->second -= minus;
			outit->second -= minus;
			in_edge[nxt][i] -= minus;
			out_edge[nxs][i] -= minus;
			if (!init->second) {
				out_edge[nxs].erase(i);
				in_edge[i].erase(init);
			}
			if (!outit->second) {
				in_edge[nxt].erase(i);
				out_edge[i].erase(outit);
			}
			out_edge[nxs][nxt] += minus;
			in_edge[nxt][nxs] += minus;
			auto it = out_edge[nxt].find(nxs);
			if (it == out_edge[nxt].end())continue;
			minus = min(out_edge[nxs][nxt], it->second);
			out_edge[nxs][nxt] -= minus;
			in_edge[nxt][nxs] -= minus;
			it->second -= minus;
			in_edge[nxs][nxt] -= minus;
			if (!it->second) {
				out_edge[nxt].erase(it);
				in_edge[nxs].erase(nxt);
			}
			if (!out_edge[nxs][nxt]) {
				out_edge[nxs].erase(nxt);
				in_edge[nxt].erase(nxs);
			}
		}
	}
	vector<int>a;
	vector<int>b;
	vector<long long int>c;
	for (int i = 0; i < N; i++) {
		for (auto j : out_edge[i]) {
			a.push_back(i);
			b.push_back(j.first);
			c.push_back(j.second);
		}
	}
	cout << a.size() << endl;
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] + 1 << " " << b[i] + 1 << " " << c[i] << "\n";
	}
}