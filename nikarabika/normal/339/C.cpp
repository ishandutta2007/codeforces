#include <bits/stdc++.h>

using namespace std;

#define PB push_back

const int maxn = 1e3 + 10;
vector<int> par[11][maxn];
vector<int> w;

int main(){
	ios_base::sync_with_stdio(false);
	char x;
	for(int i = 1; i <= 10; i++){
		cin >> x;
		if(x == '1')
			w.PB(i);
	}
	int m;
	cin >> m;
	for(int i = 0; i < w.size(); i++)
		par[w[i]][1].PB(w[i]);
	for(int s = 2; s <= m; s++){
		for(int d = 0; d <= 10; d++){
			for(int i = 0; i < w.size(); i++) if(w[i] > d){
				int a = abs(d - w[i]), b = s - 1;
				if(par[a][b].size() >= 2 or (par[a][b].size() == 1 and par[a][b][0] != w[i]))
					par[d][s].PB(w[i]);
			}
		}
	}
	vector<int> ans;
	ans.PB(1e6);
	for(int i = 1; i <= 10; i++) if(par[i][m].size()){
		cout << "YES" << endl;
		int y = i, z = m;
		while(z != 0)
			for(int j = 0; j < par[y][z].size(); j++)
				if(par[y][z][j] != ans.back())
					ans.PB(par[y][z][j]), y = abs(y - par[y][z--][j]);
		for(int i = ans.size() - 1; i > 0; i--)
			cout << ans[i] << ' ';
		cout << endl;
		return 0;
	}
	cout << "NO" << endl;
	return 0;
}