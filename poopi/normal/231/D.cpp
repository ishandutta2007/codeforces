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

int c[5], p[5];
int v[10];

int main(){
	cin >> p[2] >> p[0] >> p[1];
	cin >> c[2] >> c[0] >> c[1];
	for(int i = 0; i < 6; i++)
		cin >> v[i];
	int res = 0;
	for(int i = 0; i < 3; i++){
		if(p[i] > c[i]) res += v[2 * i + 1];
		if(p[i] < 0) res += v[2 * i];
	}
	cout << res << endl;
	return 0;
}