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
int cnt[1000010];

int main(){
	cin >> n;
	int t, c;
	for(int i = 0; i < n; i++){
		cin >> t >> c;
		cnt[t] += c;
	}
	int qsz = 0, mx = 0, last = 0;
	for(int i = 1; i <= 1000000; i++){
		if(qsz > 0){
			qsz--;
			last = i;
		}
		qsz += cnt[i];
		mx = max(mx, qsz);
	}
	if(qsz > 0)
		last = qsz + 1000000;
	cout << last << ' ' << mx << endl;
	return 0;
}