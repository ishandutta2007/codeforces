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

int64 bef[2010], aft[2010];

int main(){
	string str;
	cin >> str;
	for(int i = 0; i < str.length(); i++){
		int p = i, q = i;
		while(p >= 0 && q < str.length() && str[p] == str[q])
			bef[q++]++, aft[p--]++;
		p = i, q = i + 1;
		while(p >= 0 && q < str.length() && str[p] == str[q])
			bef[q++]++, aft[p--]++;
	}
	int64 res = 0;
	for(int i = 1; i < str.length(); i++){
		res += bef[i - 1] * aft[i];
		bef[i] += bef[i - 1];
	}
	cout << res << endl;
	return 0;
}