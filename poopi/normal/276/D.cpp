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

int64 l, r;

int main(){
	cin >> l >> r;
	int p = 61;
	while(p >= 0 && !((l ^ r) & (1LL << p)))
		p--;
	cout << (1LL << (p + 1)) - 1 << endl;
	return 0;
}