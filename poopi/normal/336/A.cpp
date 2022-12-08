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

int x, y;

int main(){
	cin >> x >> y;
	int len = abs(x) + abs(y);
	P p1 = P((x < 0 ? -len : len), 0);
	P p2 = P(0, (y < 0 ? -len : len));
	if(p1 > p2)
		swap(p1, p2);
	cout << p1.first << ' ' << p1.second << ' ' << p2.first << ' ' << p2.second << endl;
	return 0;
}