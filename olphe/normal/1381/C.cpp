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
constexpr double EPS = 1e-12;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while (K--) {
		cin >> N;
		cin >> L >> R;
		vector<int>v(N);
		vector<int>used(N + 2);
		vector<vector<int>>place(N + 2);
		int amari = 0;
		for (auto &i : v) {
			cin >> i;
			used[i]++;
		}
		for (int i = 0; i < N; i++) {
			place[v[i]].push_back(i);
		}
		priority_queue<pair<int, int>>PQ;
		for (int i = 1; i <= N + 1; i++) {
			if (place[i].empty())continue;
			PQ.push({ place[i].size(),i });
		//	cout << i << " " << place[i].size() << endl;
		}
		for (int i = 1; i <= N + 1; i++)if (!used[i])amari = i;
		if (L > R) {
			cout << "NO\n";
			continue;
		}
		vector<int>ans(N);
		int length = (N - L);
		while (L) {
			L--, R--;
			auto box = PQ.top();
	//		cout << "box " << box.second << endl;
			PQ.pop();
			ans[place[box.second].back()] = box.second;
			place[box.second].pop_back();
			box.first--;
			if(box.first)PQ.push(box);
		}
		int add = 0;
		if (!PQ.empty()) {
			length = min(length / 2, length - PQ.top().first);
			add = PQ.top().first;
		}
		vector<int>idx;
		vector<int>num;
		while(!PQ.empty()){
			auto box = PQ.top();
		//	cout << "box " << box.first << " " << box.second << endl;
			PQ.pop();
			int st = min({ length, box.first,(int)R });
			for (int i = 0; i < st; i++) {
				idx.push_back(place[box.second].back());
				num.push_back(box.second);
				place[box.second].pop_back();
				R--;
			}
			for (int i = st; i < box.first; i++) {
				idx.push_back(place[box.second].back());
				num.push_back(amari);
				place[box.second].pop_back();
			}
		}
		if (R) {
			cout << "NO\n";
			continue;
		}
		R = idx.size();
		for (int i = 0; i < R; i++) {
			ans[idx[(i+add)%R]] = num[(i) % R];
		}
		for (auto &i : ans) {
			if (i == 0)i = amari;
		}
		cout << "YES\n";
		for (auto i : ans)cout << i << " ";
		cout << endl;
	}
}