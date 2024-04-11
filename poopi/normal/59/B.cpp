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

int n, tot, mn = 1000;

int main(){
	cin >> n;
	int a;
	for(int i = 0; i < n; i++){
		cin >> a;
		tot += a;
		if(a % 2)
			mn = min(mn, a);
	}
	if(tot % 2 == 0 && mn == 1000)
		cout << 0 << endl;
	else{
		if(tot % 2 == 0)
			tot -= mn;
		cout << tot << endl;
	}
	return 0;
}