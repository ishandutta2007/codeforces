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

int val[3][4] = {{0, 1, 2, 3}, {0, 2, 3, 1}, {0, 3, 1, 2}};

int64 getValue(int64 row, int col){
	if(row == 0){
		return val[col][1];
	}
	int64 k = 1;
	int64 tmp = row, sum = 0;
	while(tmp >= k){
		tmp -= k;
		k *= 4;
	}

	int64 nrow = (row - tmp - k / 4) + tmp / 4;
	int64 ans = getValue(nrow, col);
	return ans * 4 + val[col][tmp % 4];
}

int64 getValue(int64 idx){
	idx--;
	return getValue(idx / 3, idx % 3);
}

int main(){
	std::ios::sync_with_stdio(false);
	int T;
	for(cin >> T; T--; ){
		int64 n;
		cin >> n;
		cout << getValue(n++) << endl;
	}
	return 0;
}