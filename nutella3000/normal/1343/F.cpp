#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 1e15 + 7;
const int max_n = 201;
int n;
set<int> p[max_n];
int res[max_n];
set<int> ress;

bool used[max_n];


void scan() {
	cin >> n;
	for(int i = 0;i < n;i++) {
		p[i].clear();
		used[i] = false;
	}
	for(int i = 1;i < n;i++) {
		int k;
		cin >> k;
		for(int j = 0;j < k;j++) {
			int v;
			cin >> v;
			p[i].emplace(v);
			//cout << v << " ";
		}
		//cout << '\n';
	}
}


bool check(int sz, int id) {
	int id1 = sz - 1;
	while(id1 >= 0 && p[id].find(res[id1]) != p[id].end()) {
		id1--;
	}
	id1++;

	return sz - id1 == p[id].size() - 1;
}


bool solve1() {
	int id = 2;
	while(id < n) {
		int last = id;

		for(int i = 0;i < n;i++) {
			if (used[i]) continue;
			if (check(id, i)) {
				for(int j : p[i]) {
					if (ress.find(j) == ress.end()) {
						res[id] = j;
						ress.emplace(j);
					}
				}

				used[i] = true;
				//cout << i + 1 << " " << '\n';
				id++;
			}
			if (last != id) break;
		}

		if (last == id) return false;
	}

	return true;
}

void solve() {
	scan();

	//cout << n << '\n';

	for(int start = 1;start < n;start++) {
		if (p[start].size() != 2) continue;

		int num1 = *p[start].begin();
		int num2 = *(++p[start].begin());

		//cout << num1 << " " << num2 << '\n';

		ress.clear();
		for(int i = 0;i < n;i++) used[i] = false;


		res[0] = num1;
		res[1] = num2;
		used[start] = true;
		ress.emplace(num1); ress.emplace(num2);


		if (solve1()) break;

		ress.clear();
		for(int i = 0;i < n;i++) used[i] = false;

		res[1] = num1;
		res[0] = num2;
		used[start] = true;
		ress.emplace(num1); ress.emplace(num2);

		if (solve1()) break;
	}

	for(int i = 0;i < n;i++) cout << res[i] << " ";
	cout << '\n';
}





signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
 
    cin.tie(0);
    cout.tie(0);
   	ios_base::sync_with_stdio(0);


   	int t;
   	cin >> t;
   	while(t--) {
   		solve();
   	}


}