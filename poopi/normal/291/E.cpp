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
#define PLL pair<int64, int64>

int n;
int par[100010];
int64 B1 = 37, B2 = 43;
int64 PB1, PB2;
string str[100010], t;
vector <int> adj[100010];
vector <int> bef;
PLL val;

int64 dfs(int idx, PLL hsh){
	int64 cnt = 0;
	for(int i = 0; i < str[idx].length(); i++){
		bef.push_back(str[idx][i] - 'a' + 1);
		hsh.first = hsh.first * B1 + bef.back();
		hsh.second = hsh.second * B2 + bef.back();
		if(bef.size() > t.length()){
			hsh.first -= PB1 * bef[(int)bef.size() - t.length() - 1];
			hsh.second -= PB2 * bef[(int)bef.size() - t.length() - 1];
		}
		if(bef.size() >= t.length() && hsh == val)
			cnt++;
	}
	for(int i = 0; i < adj[idx].size(); i++)
		cnt += dfs(adj[idx][i], hsh);
	for(int i = 0; i < str[idx].length(); i++)
		bef.pop_back();
	return cnt;
}

int main(){
	cin >> n;
	for(int i = 1; i < n; i++){
		cin >> par[i] >> str[i];
		adj[--par[i]].push_back(i);
	}
	cin >> t;
	val = PLL(0, 0);
	PB1 = PB2 = 1;
	for(int i = 0; i < t.length(); i++){
		val.first = val.first * B1 + (t[i] - 'a' + 1);
		val.second = val.second * B2 + (t[i] - 'a' + 1);
		PB1 *= B1;
		PB2 *= B2;
	}
	cout << dfs(0, PLL(0, 0)) << endl;
	return 0;
}