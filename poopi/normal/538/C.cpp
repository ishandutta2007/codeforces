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
#define Inf 1000000000
#define Mod 1000000007LL

int n, q;
int d, h;

int main(){
	cin >> n >> q;
	cin >> d >> h;
	int res = h + d - 1;
	for(int i = 1; i < q; i++){
		int nd, nh;
		cin >> nd >> nh;
		if(abs(nh - h) > nd - d)
			res = Inf;
		else{
			int dif = nd - d - abs(nh - h);
			res = max(res, max(nh, h) + dif / 2);
		}
		d = nd, h = nh;
	}
	res = max(res, n - d + h);

	if(res == Inf)
		cout << "IMPOSSIBLE" << endl;
	else cout << res << endl;
	return 0;
}