										/* in the name of Allah */

#include <algorithm>
#include <iostream>
#include <memory.h>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <list>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int, double>

int n, cnt;
map <int, int> mp;

int main(){
	cin >> n;
	int tmp;
	for(int i = 0; i < n; i++){
		cin >> tmp;
		if(tmp == 0) continue;
		if(mp.find(tmp) == mp.end())
			mp[tmp] = 0;
		mp[tmp]++;
		if(mp[tmp] == 2)
			cnt++;
		if(mp[tmp] > 2)
			cnt = -1000000;
	}
	cout << (cnt < 0 ? -1 : cnt) << endl;
	return 0;
}