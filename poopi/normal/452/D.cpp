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

int k, n[3], t[3];
priority_queue <int> q[3];

int main(){
	cin >> k;
	for(int i = 0; i < 3; i++){
		cin >> n[i];
		for(int j = 0; j < n[i]; j++)
			q[i].push(0);
	}
	for(int i = 0; i < 3; i++)
		cin >> t[i];
	int res = 0;
	for(int i = 0; i < k; i++){
		int t2 = -q[2].top();
		q[2].pop();
		int t1 = max(t2 - t[1], -q[1].top());
		q[1].pop();
		int t0 = max(t1 - t[0], -q[0].top());
		q[0].pop();

		q[0].push(-(t0 + t[0]));
		q[1].push(-(t0 + t[0] + t[1]));
		q[2].push(-(t0 + t[0] + t[1] + t[2]));
		res = t0 + t[0] + t[1] + t[2];
	}
	cout << res << endl;
	return 0;
}