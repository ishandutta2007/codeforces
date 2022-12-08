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
int arr[100010];
vector <int> adj[100010];
vector <int> res;

int main(){
	cin >> n >> m;
	int a, b;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		if(arr[i] == 0)
			res.push_back(i);
	}
	for(int i = 0; i < res.size(); i++)
		for(int j = 0; j < adj[res[i]].size(); j++)
			if(--arr[adj[res[i]][j]] == 0)
				res.push_back(adj[res[i]][j]);
	cout << res.size() << endl;
	for(int i = 0; i < res.size(); i++)
		cout << res[i] + 1 << ' ';
	cout << endl;
	return 0;
}