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
#define Mod 1000000009LL

int n;
int x[100010], y[100010];
int deg[100010];
int rel[100010];
int64 pw[100010];
bool mark[100010];
map <P, int> mp;
priority_queue <int> q[2];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
		mp[P(x[i], y[i])] = i;
		q[0].push(i);
		q[1].push(-i);
		pw[i] = i ? (pw[i - 1] * n) % Mod : 1;
	}
	memset(rel, -1, sizeof rel);

	for(int i = 0; i < n; i++)
		for(int j = -1; j <= 1; j++)
			if(mp.count(P(x[i] + j, y[i] - 1)))
				deg[i]++;

	int64 res = 0;
	for(int it = 0; it < n; it++){
		int cur = it % 2;
		int sg = cur ? -1 : 1;
		int idx;
		while(true){
			idx = sg * q[cur].top();
			q[cur].pop();
			if(mark[idx])
				continue; 
			bool can = true;
			for(int j = -1; j <= 1; j++){
				P adj = P(x[idx] + j, y[idx] + 1);
				if(mp.count(adj)){
					int t = mp[adj];
					if(deg[t] == 1 && !mark[t]){
						can = false;
						rel[t] = idx;
						break;
					}
				}
			}
			if(can){
				res = (res + pw[n - 1 - it] * idx) % Mod;
				mark[idx] = true;
				if(rel[idx] != -1){
					q[0].push(rel[idx]);
					q[1].push(-rel[idx]);
				}
				for(int j = -1; j <= 1; j++){
					P adj = P(x[idx] + j, y[idx] + 1);
					if(mp.count(adj))
						deg[mp[adj]]--;
				}
				break;
			}
		}
	}
	cout << res << endl;
	return 0;
}