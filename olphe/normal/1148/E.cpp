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
const long long int MOD = 1000003;
//const int MOD = 998244353;
//const long long int MOD = 998244353;

//long long int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<pair<int,int>>v(N);
	vector<int>w(N);
	long long int vsum = 0;
	for (int i = 0; i < N; i++) {
		cin >> v[i].first;
		vsum += v[i].first;
		v[i].second = i+1;
	}
	long long int wsum = 0;
	for (int i = 0; i < N; i++) {
		cin >> w[i];
		wsum += w[i];
	}
	sort(v.begin(), v.end());
	sort(w.begin(), w.end());
	vector<pair<int,pair<int, int>>>u;
	priority_queue<pair<int, pair<int, int>>>d;
	for (int i = 0; i < N; i++) {
		if (v[i].first < w[i]) {
			u.push_back({ v[i].first,{w[i] - v[i].first,v[i].second} });
		}
		else if (v[i].first > w[i]) {
			d.push({ v[i].first,{v[i].first - w[i],v[i].second } });
		}
	}
	if (vsum != wsum) {
		cout << "NO\n";
		return 0;
	}
	sort(u.begin(), u.end());
	vector<pair<pair<int, int>, int>>ans;
	while (!u.empty()) {
		if (u.back().first >= d.top().first) {
			cout << "NO\n";
			return 0;
		}
		auto box = d.top();
		d.pop();
		int num = min(u.back().second.first, box.second.first);
		num = min(num, (box.first - u.back().first) / 2);
		ans.push_back({ {u.back().second.second,box.second.second},num });
		u.back().first += num;
		u.back().second.first -= num;
		if (!u.back().second.first)u.pop_back();
		box.first -= num;
		box.second.first -= num;
		if (box.second.first)d.push(box);
	}
	cout << "YES\n";
	cout << ans.size() << "\n";
	for (auto i : ans) {
		cout << i.first.first << " " << i.first.second << " " << i.second << "\n";
	}
}