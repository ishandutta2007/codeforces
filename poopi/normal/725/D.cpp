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
priority_queue <PLL> oth;
priority_queue <int64> q;

int main(){
	int cnt = 0;
	int64 a, b, rem;
	cin >> n >> rem >> a;
	for(int i = 1; i < n; i++){
		cin >> a >> b;
		if(a > rem){
			q.push(a - b - 1);
			cnt++;
		}
		else oth.push(PLL(a, b));
	}

	int res = cnt;
	while(!q.empty()){
		int64 cost = -q.top();
		q.pop();
		if(cost > rem)
			break;
		rem -= cost;
		cnt--;

		while(!oth.empty() && oth.top().first > rem){
			cnt++;
			PLL tmp = oth.top();
			oth.pop();
			q.push(tmp.first - tmp.second - 1);
		}

		res = min(res, cnt);
	}

	cout << res + 1 << endl;
	return 0;
}