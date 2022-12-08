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
#define Max 200010

int n, m;
int res[Max];
bool pos[Max][2];
bool mark[Max];
int deg[Max];
vector <int> cl[Max];
vector <int> lit[Max];
queue <int> q;

void dfs(int idx){
	mark[idx] = true;
	for(int i = 0; i < cl[idx].size(); i++){
		int lt = cl[idx][i];
		if(res[abs(lt)] == -1){
			res[abs(lt)] = (lt > 0 ? 1 : 0);
			lt = abs(lt);
			for(int j = 0; j < lit[lt].size(); j++){
				int cc = lit[lt][j];
				if(!mark[cc])
					dfs(cc);
			}
			break;
		}
	}
}

int main(){
	memset(res, -1, sizeof res);
	cin >> n >> m;
	int k, a;
	for(int i = 0; i < n; i++){
		cin >> k;
		for(int j = 0; j < k; j++){
			cin >> a;
			cl[i].push_back(a);
			lit[abs(a)].push_back(i);
			if(a > 0)
				pos[a][0] = true;
			else pos[-a][1] = true;
		}
	}

	for(int i = 1; i <= m; i++){
		if(!pos[i][0] || !pos[i][1]){
			q.push(i);
			res[i] = -2;
		}
	}
	while(!q.empty()){
		int t = q.front();
		q.pop();
		res[t] = (pos[t][0] ? 1 : 0);
		for(int i = 0; i < lit[t].size(); i++){
			int cc = lit[t][i];
			if(mark[cc])
				continue;
			mark[cc] = true;
			for(int j = 0; j < cl[cc].size(); j++){
				int lt = cl[cc][j];
				if(res[abs(lt)] == -1){
					if(lt > 0)
						pos[lt][0] = false;
					else pos[-lt][1] = false;
					q.push(abs(lt));
					res[abs(lt)] = -2;
				}
			}
		}
	}

	for(int i = 0; i < n; i++){
		if(!mark[i] && cl[i].size() == 1){
			q.push(i);
			mark[i] = true;
		}
		deg[i] = cl[i].size();
	}
	bool can = true;
	while(!q.empty()){
		int t = q.front();
		q.pop();
		int lt = 0;
		for(int i = 0; i < cl[t].size(); i++)
			if(res[abs(cl[t][i])] == -1)
				lt = cl[t][i];
		if(lt == 0){
			can = false;
			break;
		}
		res[abs(lt)] = (lt > 0 ? 1 : 0);

		lt = abs(lt);
		for(int i = 0; i < lit[lt].size(); i++){
			int cc = lit[lt][i];
			if(!mark[cc]){
				deg[cc]--;
				if(deg[cc] == 1){
					q.push(cc);
					mark[cc] = true;
				}
			}
		}
	}

	if(!can){
		cout << "NO" << endl;
		return 0;
	}

	for(int i = 0; i < n; i++)
		if(!mark[i])
			dfs(i);
	for(int i = 1; i <= m; i++)
		if(res[i] == -1)
			res[i] = 0;

	cout << "YES" << endl;
	for(int i = 1; i <= m; i++)
		cout << res[i];
	cout << endl;
	return 0;
}