#include <bits/stdc++.h>
#define inf (1LL << 60)
#define int long long
using namespace std;

vector<vector<int>> fro(3001), to(3001);
int vi[3001] = {0};
int32_t main(){
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		x--, y--;
		to[x].push_back(y);
		fro[y].push_back(x);
	}
	
	for(int i = 0; i < n; i++){
		sort(to[i].begin(), to[i].end());
		sort(fro[i].begin(), fro[i].end());
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i != j){
				int n = set_intersection(to[i].begin(), to[i].end(), fro[j].begin(), fro[j].end(), vi + 0) - vi;
				ans += (n * (n - 1)) / 2;
			}
		}
	}
	cout << ans << endl;
	return 0;
}