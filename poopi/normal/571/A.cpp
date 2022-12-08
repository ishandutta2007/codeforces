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
#define Max 300001

int k, a[3];
int64 f2[Max], f3[Max];

int main(){
	f2[0] = f3[0] = 1;
	for(int64 i = 1; i < Max; i++){
		f2[i] = f2[i - 1] + i + 1;
		f3[i] = f3[i - 1] + (i + 2) * (i + 1) / 2;
	}

	cin >> a[0] >> a[1] >> a[2] >> k;
	int sum = a[0] + a[1] + a[2];
	int64 tot = f3[k];
	for(int i = 0; i < 3; i++){
		for(int j = 0; j <= k; j++){
			int rem = k - j;
			int diff = (a[i] + j) - (sum - a[i]);
			if(diff >= 0)
				tot -= f2[min(diff, rem)];
		}
	}
	cout << tot << endl;
	return 0;
}