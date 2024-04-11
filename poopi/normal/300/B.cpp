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

ifstream fin("input.txt");
ofstream fout("output.txt");

#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define Pss pair<string, string>
#define PLL pair<int64, int64>
//#define cin fin
//#define cout fout

int n, m, k;
bool mark[50];
vector <int> adj[50];
vector <int> v[50];

void dfs(int idx, int st){
	mark[idx] = true;
	v[st].push_back(idx + 1);
	for(int i = 0; i < adj[idx].size(); i++)
		if(!mark[adj[idx][i]])
			dfs(adj[idx][i], st);
}

int main(){
	cin >> n >> m;
	int a, b;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i = 0; i < n; i++)
		if(!mark[i])
			dfs(i, k++);
	int cnt = 0, mx = 0;
	for(int i = 0; i < k; i++){
		if(v[i].size() > 1)
			cnt++;
		mx = max(mx, (int)v[i].size());
	}
	if(mx > 3 || cnt > n / 3){
		cout << -1 << endl;
		return 0;
	}
	for(int i = 0; i < k; i++){
		if(v[i].size() == 2){
			for(int j = 0; j < k; j++){
				if(v[j].size() == 1){
					v[i].push_back(v[j][0]);
					v[j].clear();
					break;
				}
			}
		}
	}
	vector <int> res;
	for(int i = 0; i < k; i++){
		if(v[i].size() == 3){
			cout << v[i][0] << ' ' << v[i][1] << ' ' << v[i][2] << endl;
			v[i].clear();
		}
		else if(!v[i].empty())
			res.push_back(v[i][0]);
	}
	for(int i = 0; i < res.size(); i++){
		cout << res[i];
		if(i % 3 == 2)
			cout << endl;
		else cout << ' ';
	}
    return 0;
}