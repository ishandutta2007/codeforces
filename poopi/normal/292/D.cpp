										/* in the name of Allah */

#include <algorithm>
#include <iostream>
#include <memory.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>

using namespace std;

#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define Pss pair<string, string>
#define PLL pair<int64, int64>
#define Inf 1000000
#define Mod 1000000007LL

int n, m;
int e[2][10010][2];
int par[2][510][10010];
int pp[510];
vector <int> ch[510];
vector <int> res, sd[510];

int main(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		for(int j = 0; j < 2; j++){
			cin >> e[0][i][j];
			e[0][i][j]--;
			e[1][m - i + 1][j] = e[0][i][j];
		}
	}
	for(int st = 0; st < 2; st++){
		for(int i = 0; i < n; i++){
			if(!ch[i].empty())
				ch[i].clear();
			ch[i].push_back(i);
			par[st][i][0] = i;
		}
		for(int i = 1; i <= m; i++){
			for(int j = 0; j < n; j++)
				par[st][j][i] = par[st][j][i - 1];
			int u = e[st][i][0], v = e[st][i][1];
			int pu = par[st][u][i], pv = par[st][v][i];
			if(pu != pv){
				if(ch[pu].size() < ch[pv].size())
					swap(u, v);
				for(int j = 0; j < ch[pv].size(); j++){
					par[st][ch[pv][j]][i] = pu;
					ch[pu].push_back(ch[pv][j]);
				}
				ch[pv].clear();
			}
		}
	}
	int Q, l, r;
	cin >> Q;
	for(int q = 0; q < Q; q++){
		cin >> l >> r;
		res.clear();
		for(int i = 0; i < n; i++){
			if(!sd[i].empty())
				sd[i].clear();
			sd[i].push_back(i);
			pp[i] = i;
		}
		for(int i = 0; i < n; i++){
			int ta[2] = {i, i};
			int a[2] = {par[0][i][l - 1], par[1][i][m - r]};
			for(int k = 0; k < 2; k++){
				int u = a[k], v = ta[k];
				int pu = pp[u], pv = pp[v];
				if(pu != pv){
					if(sd[pu].size() < sd[pv].size())
						swap(u, v);
					for(int j = 0; j < sd[pv].size(); j++){
						pp[sd[pv][j]] = pu;
						sd[pu].push_back(sd[pv][j]);
					}
					sd[pv].clear();
				}
			}
		}
		int cnt = 0;
		for(int i = 0; i < n; i++)
			if(pp[i] == i)
				cnt++;
		cout << cnt << endl;
	}
	return 0;
}