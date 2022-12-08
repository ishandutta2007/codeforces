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

int64 cnt, res;

int main(){
	string str;
	cin >> str;
	for(int i = 0; i + 4 < str.length(); i++){
		if(str.substr(i, 5) == "heavy")
			cnt++;
		if(str.substr(i, 5) == "metal")
			res += cnt;
	}
	cout << res << endl;
    return 0;
}