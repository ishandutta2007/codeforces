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
#define Mod 1000000007LL

int64 modP(int64 x, int64 y, int64 z){
	int64 ret = 1;
	while(y){
		if(y & 1)
			ret = (ret * x) % z;
		x = (x * x) % z;
		y >>= 1;
	}
	return ret;
}

int main(){
	int64 n;
	cin >> n;
	if(n == 0){
		cout << 1 << endl;
		return 0;
	}
	int64 t1 = modP(2, n - 1, Mod);
	int64 t2 = modP(2, n, Mod) + 1;
	int64 res = (t1 * t2) % Mod;
	cout << res << endl;
	return 0;
}