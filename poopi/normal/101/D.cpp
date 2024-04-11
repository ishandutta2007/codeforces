										/* in the name of Allah */
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int, int>
#pragma comment(linker, "/STACK:50000000")

struct adj{
	int v, len;
	int t, ch;
	adj(int _v, int _l, int _t = 0, int _ch = 1){
		v = _v, len = _l;
		t = _t, ch = _ch;
	}
	bool operator < (const adj &a) const{
		return (int64)t * a.ch < (int64)a.t * ch;
	}
};

int n;
vector <adj> ls[100010];
int64 res[100010];

P dfs1(int idx, int par){
	int sum = 0, cnt = 1;
	for(int i = 0; i < ls[idx].size(); i++){
		int j = ls[idx][i].v;
		if(j == par) continue;
		P tmp = dfs1(j, idx);
		sum += tmp.first + 2 * ls[idx][i].len;
		cnt += tmp.second;
		ls[idx][i].t = tmp.first + 2 * ls[idx][i].len;
		ls[idx][i].ch = tmp.second;
	}
	sort(ls[idx].begin(), ls[idx].end());
	int64 ad = 0;
	res[idx] = 0;
	for(int i = 0; i < ls[idx].size(); i++){
		int j = ls[idx][i].v;
		if(j == par) continue;
		res[idx] += (ad + (int64)ls[idx][i].len) * ls[idx][i].ch + res[j];
		ad += ls[idx][i].t;
	}
	return P(sum, cnt);
}

int main(){
	int a, b, c;
	while(cin >> n){
		for(int i = 0; i < n - 1; i++){
			cin >> a >> b >> c;
			a--, b--;
			ls[a].push_back(adj(b, c));
			ls[b].push_back(adj(a, c));
		}
		dfs1(0, -1);
		cout.precision(7);
		cout.setf(ios::showpoint | ios::fixed);
		cout << (double)res[0] / (n - 1) << endl;
	}
	return 0;
}