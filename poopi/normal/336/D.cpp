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

int64 fact[200010];

int64 modP(int64 x, int64 y){
	int64 ret = 1;
	while(y){
		if(y & 1)
			ret = (ret * x) % Mod;
		x = (x * x) % Mod;
		y >>= 1;
	}
	return ret;
}

int64 bt(int n, int m, int d){
	if(n + m == 1){
		if((n == 1 && d == 0) || (m == 1 && d == 1))
			return 1;
		return 0;
	}
	if(d == 0){
		int64 res = 0;
		if(m > 0){
			int64 t1 = modP(fact[n], Mod - 2);
			int64 t2 = modP(fact[m - 1], Mod - 2);
			int64 tmp = (t1 * t2) % Mod;
			res = (tmp * fact[n + m - 1]) % Mod;
		}
		if(n > 0)
			res = (res + bt(n - 1, m, 1)) % Mod;
		return res;
	}
	if(n > 0)
		return bt(n - 1, m, 0);
	return 0;
}

int main(){
	fact[0] = 1;
	for(int i = 1; i <= 200000; i++)
		fact[i] = (fact[i - 1] * i) % Mod;
	int n, m, d;
	cin >> n >> m >> d;
	int64 res = bt(n, m, d);
	cout << res << endl;
	return 0;
}