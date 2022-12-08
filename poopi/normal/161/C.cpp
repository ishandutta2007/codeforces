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

int p[40];

int calc(int l1, int r1, int l2, int r2, int dep){
	if(dep == 0)
		return 0;
	if((l1 <= l2 && r2 <= r1) || (l2 <= l1 && r1 <= r2))
		return min(r1 - l1 + 1, r2 - l2 + 1);
	bool h1 = (l1 <= p[dep] && p[dep] <= r1);
	bool h2 = (l2 <= p[dep] && p[dep] <= r2);
	int ret = max(0, min(r1, r2) - max(l1, l2) + 1);
	if(!h1 && !h2){
		if(l1 > p[dep])
			l1 -= p[dep], r1 -= p[dep];
		if(l2 > p[dep])
			l2 -= p[dep], r2 -= p[dep];
		ret = max(ret, calc(l1, r1, l2, r2, dep - 1));
	}
	else if(h1 && h2){
		if(l1 > l2){
			swap(l1, l2);
			swap(r1, r2);
		}
		ret = max(ret, calc(l1, p[dep] - 1, 1, r2 - p[dep], dep - 1));
	}
	else{
		if(!h1){
			swap(l1, l2);
			swap(r1, r2);
		}
		if(l2 > p[dep])
			l2 -= p[dep], r2 -= p[dep];
		ret = max(ret, calc(l1, p[dep] - 1, l2, r2, dep - 1));
		ret = max(ret, calc(1, r1 - p[dep], l2, r2, dep - 1));
	}
	return ret;
}

int main(){
	p[1] = 1;
	for(int i = 2; i <= 30; i++)
		p[i] = 2 * p[i - 1];
	int l1, r1, l2, r2;
	while(cin >> l1 >> r1 >> l2 >> r2){
		cout << calc(l1, r1, l2, r2, 30) << endl;
	}
	return 0;
}