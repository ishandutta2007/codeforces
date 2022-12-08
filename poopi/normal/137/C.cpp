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
bool mark[100010];
int bz[100010][2];
priority_queue <P> q;
vector <P> v;

int main(){
	cin >> n;
	int a, b;
	for(int i = 0; i < n; i++){
		cin >> bz[i][0] >> bz[i][1];
		v.push_back(P(bz[i][0], i));
		v.push_back(P(bz[i][1], -i - 1));
	}
	int cnt = 0;
	sort(v.begin(), v.end());
	for(int i = 0; i < v.size(); i++){
		if(v[i].second >= 0)
			q.push(P(-bz[v[i].second][0], v[i].second));
		else{
			int idx = -v[i].second - 1;
			mark[idx] = true;
			while(!q.empty() && mark[q.top().second])
				q.pop();
			if(!q.empty() && -q.top().first < bz[idx][0])
				cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}