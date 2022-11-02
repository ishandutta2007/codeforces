#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 1e9 + 7;
const int max_n = 1e6 + 3;

vector<int> gr[max_n];
vector<int> id[max_n];
int num = 0;
int res[max_n];


void solve() {
	int n;
	cin >> n;
	for(int i = 0;i < n;i++) res[i] = -1;
	for(int i = 0;i < n - 1;i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v1--; v2--;
		gr[v1].emplace_back(v2);
		gr[v2].emplace_back(v1);
		id[v1].emplace_back(i);
		id[v2].emplace_back(i);
	}

	for(int i = 0;i < n;i++) {
		//cout << i << " " << gr[i].size() << '\n';
		if (gr[i].size() == 1 && res[id[i][0]] == -1) {
			res[id[i][0]] = num++;
		}
		if (num == 3) break;
	}
	//cout << num << '\n' << '\n' << '\n';


	for(int i = 0;i < n;i++) {
		for(int j : id[i]) if (res[j] == -1) res[j] = num++;	
	}
	
	for(int i = 0;i < n - 1;i++) cout << res[i] << '\n';
}


signed main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);



    solve();
}