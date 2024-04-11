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

int n, b, mn;

int main(){
	cin >> n >> b >> mn;
	int res = b, a;
	for(int i = 1; i < n; i++){
		cin >> a;
		res = max(res, b / mn * a + b % mn);
		mn = min(mn, a);
	}
	cout << res << endl;
	return 0;
}