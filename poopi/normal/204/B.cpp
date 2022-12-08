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
int u[200010];
int d[200010];
map<int64, int> mp;

int getId(int64 val){
	if(mp.find(val) == mp.end())
		mp[val] = m++;
	return mp[val];
}

int main(){
	std::ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; i++){
		int64 a, b;
		cin >> a >> b;
		a = getId(a);
		b = getId(b);
		u[a]++;
		if(a != b)
			d[b]++;
	}

	int ans = n + 1;
	int tar = (n + 1) / 2;
	for(int i = 0; i < m; i++)
		if(u[i] + d[i] >= tar)
			ans = min(ans, max(0, tar - u[i]));

	cout << (ans == n + 1 ? -1 : ans) << endl;
	return 0;
}