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

int n, k, cnt;
string str;

int main(){
	cin >> n >> k >> str;
	string res = "YES";
	for(int i = 0; i < n; i++){
		if(str[i] == '.')
			cnt = 0;
		else cnt++;
		if(cnt >= k)
			res = "NO";
	}
	cout << res << endl;
	return 0;
}