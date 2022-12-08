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

int n, r, c;

int main(){
	cin >> n >> r >> c;
	if((r == n / 2 || r == n / 2 + 1) && (c == n / 2 || c == n / 2 + 1))
		cout << "NO" << endl;
	else cout << "YES" << endl;
	return 0;
}