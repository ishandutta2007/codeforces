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

int64 n;
char c;

int main(){
	cin >> n >> c;
	n--;
	int64 res = n + (n & 2 ? -2 : 0) + (n / 4) * 12;
	n %= 2;

	if(n == 1) res += 6;
	if(c > 'c') res += 'f' - c + 1;
	else res += c - 'a' + 4;

	cout << res << endl;
	return 0;
}