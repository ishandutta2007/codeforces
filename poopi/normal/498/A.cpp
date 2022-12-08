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

int main(){
	int64 a, b, c;
	int64 x1, y1, x2, y2;
	int n, cnt = 0;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a >> b >> c;
		int64 t1 = a * x1 + b * y1 + c;
		int64 t2 = a * x2 + b * y2 + c;
		if((t1 < 0 && t2 > 0) || (t1 > 0 && t2 < 0))
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}