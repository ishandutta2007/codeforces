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

int r, c;
int64 x, y;

int main(){
	cin >> r >> c;
	for(int i = 0; i < r; i++)
		x += (r - i) / 2;
	for(int i = 0; i < c; i++)
		y += (c - i) / 2;
	cout << x * y << endl;
	return 0;
}