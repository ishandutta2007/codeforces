#include <bits/stdc++.h>
#define long long long
#define pii pair<int, int>
 
using namespace std;
const int inf = 1e9 + 7;
const int max_n = 2e6;
 
int n, sz;
vector<pii> gr[max_n];
long res[max_n];
 
void scan() {
	int m;
	cin >> n >> m;
	sz = n;
 
	for(int i = 1;i <= m;i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v1--; v2--;
 
		int num = i;
 
		int prev1 = v1, prev2 = v2;
 
		while(num >= 10) {
			int cost = num % 10;
			int to = sz++;
 
			gr[to].emplace_back(prev1, cost);
			prev1 = to;
 
			to = sz++;
 
			gr[to].emplace_back(prev2, cost);
			prev2 = to;
 
			num /= 10;
		}
 
		gr[v2].emplace_back(prev1, num);
		gr[v1].emplace_back(prev2, num);
	}	
}
 
 
void solve() {
	scan();
 
	for(int i = 0;i < sz;i++) res[i] = inf;
 
	res[0] = 0;
 
	deque<vector<int>> bfs;
	vector<int> temp11;
	temp11.emplace_back(0);
	bfs.emplace_back(temp11);
 
	while(!bfs.empty()) {
		vector<int> vert = bfs.front();
		bfs.pop_front();
 
		vector<pii> temp;
		for(int v : vert) {
			for(pii to : gr[v]) {
				if (res[to.first] < inf) continue;
				temp.emplace_back(to.second, to.first);
			}
		}
		sort(temp.begin(), temp.end());
 
		vector<vector<int> > new_v;
		int last = -1;
		int v = vert[0];
 
		int last_vertex = -1;

		set<int> used;
		for(pii to : temp) {
			if (used.find(to.second) != used.end()) continue;
			last_vertex = to.second;
 			used.emplace(to.second);


			res[to.second] = ((long) res[v] * 10 + to.first) % inf;
			if (last != to.first) {
				last = to.first;
				new_v.emplace_back(vector<int>(0));
			}
			new_v[new_v.size() - 1].emplace_back(to.second);
		}
		for(vector<int> i : new_v) bfs.emplace_back(i);
	}
 
	for(int i = 1;i < n;i++) cout << res[i] << '\n';
}
 
 
 
 
int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
    solve();
}