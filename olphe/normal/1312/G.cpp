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
constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr long double EPS = 1e-12;

void Search(vector<vector<pair<char, int>>>&edge, vector<int>&used, vector<int>&ans, vector<int>&l, vector<int>&r, vector<int>&num,vector<int>&idans, int &id, int depth = 0, int node = 0) {
	if (used[node]) {
		num[node] = id++;
		ans[node] = min(ans[node], id);
	}
	ans[node] = min(ans[node], depth);
	for (auto i : edge[node]) {
		ans[i.second] = min(ans[i.second], ans[node] + 1);
		Search(edge, used, ans, l, r, num, idans,id, depth + 1, i.second);
		l[node] = min(l[node], l[i.second]);
		r[node] = max(r[node], r[i.second]);
	}
	if (used[node]) {
		r[node] = max(r[node], num[node]);
		l[node] = min(l[node], num[node]);
	}
}

void Search(vector<vector<pair<char, int>>>&edge, vector<int>&used, vector<int>&ans, vector<int>&l, vector<int>&r, vector<int>&num, vector<int>&idans,set<pair<pair<int,int>,int>>&st, int &id, int depth = 0, int node = 0) {
	if (used[node]) {
		//ans[node] = min(ans[node], idans[num[node]]);
		auto it = prev(st.lower_bound({ {l[node],-r[node]},ans[node] }));
		ans[node] = min(ans[node], it->second + num[node] - (it->first.first) + 1);
	}
	//for (int i = l[node]; i <= r[node]; i++) {
	//	idans[i] = min(idans[i], ans[node] + i - l[node] + 1);
	//}
	auto it = prev(st.lower_bound({ {l[node],-r[node]},ans[node] }));
	if (it->second - it->first.first > ans[node] - l[node]&&l[node]<=r[node]) {
	//	cout << l[node] << " " << r[node] << " " << ans[node] << endl;
		st.insert({ {l[node],-r[node]},ans[node] });
	}
	reverse(edge[node].begin(), edge[node].end());
	for(auto i:edge[node]){
		ans[i.second] = min(ans[i.second], ans[node] + 1);
		Search(edge, used, ans, l, r, num, idans, st, id, depth + 1, i.second);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	vector<int>p(N + 1);
	vector<char>c(N + 1);
	vector<vector<pair<char, int>>>edge(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> p[i] >> c[i];
		edge[p[i]].emplace_back(c[i], i);
	}
	for (int i = 0; i <= N; i++) {
		sort(edge[i].begin(), edge[i].end());
	}
	int K;
	cin >> K;
	int id = 0;
	vector<int>w(K);
	vector<int>used(N + 1);
	vector<int>ans(N + 1, MOD);
	vector<int>l(N + 1, MOD);
	vector<int>r(N + 1, -1);
	vector<int>num(N + 1);
	for (auto &i : w) {
		cin >> i;
		used[i]++;
	}
	set<pair<pair<int, int>, int>>st;
	st.insert({ {-1,-MOD }, MOD });
	vector<int>idans(N + 1, MOD);
	Search(edge, used, ans, l, r, num, idans, id);
	Search(edge, used, ans, l, r, num, idans, st, id);
	for (auto i : w) {
		cout << min(ans[i], idans[num[i]]) << " ";
	}
	cout << endl;
}