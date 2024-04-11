							/* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define Max 1000000000000037LL
#define int64 long long

int n, m;
int64 pw[1000010];
int64 hs[1000010];
vector <int> adj[1000010];

int64 calc(){
	int64 res = 0;
	for(int i = 0; i < n; i++){
		hs[i] = 0;
		for(int j = 0; j < adj[i].size(); j++){
			hs[i] += pw[adj[i][j]];
			if(hs[i] >= Max)
				hs[i] -= Max;
		}
	}
	sort(hs, hs + n);
	int64 cnt = 0;
	for(int i = 0; i < n; i++){
		cnt++;
		if(i == n - 1 || hs[i] != hs[i + 1]){
			res += cnt * (cnt - 1) / 2;
			cnt = 0;
		}
	}
	return res;
}

int main(){
	cin >> n >> m;
	pw[0] = 1;
	for(int i = 1; i < n; i++){
		pw[i] = pw[i - 1] + pw[i - 1];
		if(pw[i] >= Max)
			pw[i] -= Max;
	}
	int a, b;
	for(int i = 0; i < m; i++){
		scanf("%d%d", &a, &b);
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int64 res = calc();
	for(int i = 0; i < n; i++)
		adj[i].push_back(i);
	res += calc();
	cout << res << endl;
	return 0;
}