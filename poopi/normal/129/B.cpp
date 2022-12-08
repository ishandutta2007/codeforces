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

int n, m;
int deg[110];
int mark[110];
vector <int> adj[110];
queue <int> q;

int main(){
	cin >> n >> m;
	int a, b;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
		deg[a]++, deg[b]++;
	}
	int res = 0;
	for(int i = 0; i < n; i++){
		if(deg[i] == 1){
			q.push(i);
			mark[i] = 1;
			res = 1;
		}
	}
	while(!q.empty()){
		int t = q.front();
		q.pop();
		if(deg[t] == 0) continue;
		res = max(res, mark[t]);
		for(int i = 0; i < adj[t].size(); i++){
			int j = adj[t][i];
			deg[j]--;
			if(deg[j] == 1){
				mark[j] = mark[t] + 1;
				q.push(j);
			}
		}
	}
	cout << res << endl;
    return 0;
}