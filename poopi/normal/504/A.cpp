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

int n;
int deg[100010];
int sum[100010];

vector <P> e;
queue <int> q;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> deg[i] >> sum[i];
		if(deg[i] == 1)
			q.push(i);
	}

	while(!q.empty()){
		int tmp = q.front();
		q.pop();

		if(deg[tmp] < 1)
			continue;
		deg[tmp]--;

		int idx = sum[tmp];
		e.push_back(P(tmp, idx));
		sum[idx] ^= tmp;
		deg[idx]--;
		if(deg[idx] == 1)
			q.push(idx);
	}

	cout << e.size() << endl;
	for(int i = 0; i < e.size(); i++)
		cout << e[i].first << ' ' << e[i].second << endl;
	return 0;
}