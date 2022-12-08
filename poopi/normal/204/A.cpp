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

vector <int> v;

bool isOk(int64 num){
	v.clear();
	while(num){
		v.push_back(num % 10);
		num /= 10;
	}
	return v[0] == v.back();
}

int main(){
	std::ios::sync_with_stdio(false);
	int64 l, r;
	cin >> l >> r;
	int64 cnt = 0;
	while(l <= r && l % 10 != 0)
		cnt += isOk(l++) ? 1 : 0;
	while(r > l && r % 10 != 9)
		cnt += isOk(r--) ? 1 : 0;
	cout << cnt + (r - l + 1) / 10 << endl;
	return 0;
}