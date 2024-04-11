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
#define Mod 1000000009LL

int64 n, m, k, w;

int64 modP(int64 x, int64 y){
	int64 res = 1;
	while(y){
		if(y & 1)
			res = (res * x) % Mod;
		x = (x * x) % Mod;
		y >>= 1;
	}
	return res;
}

int main(){
	cin >> n >> m >> k;
	w = n - m;
	int64 init = min(w * (k - 1), m);
	m -= init;
	
	int64 mul = modP(2, m / k + 1) - 2;
	int64 res = ((mul + Mod) * k) % Mod;
	cout << (res + m % k + init) % Mod << endl;
	return 0;
}