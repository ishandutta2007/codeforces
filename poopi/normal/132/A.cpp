										/* in the name of Allah */
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int, int>

int rev(int x){
	int ret = 0;
	for(int i = 0; i < 8; i++){
		ret = ret * 2 + x % 2;
		x /= 2;
	}
	return ret;
}

int main(){
	string str;
	getline(cin, str);
	int bef = 0;
	for(int i = 0; i < str.length(); i++){
		int t1 = (i == 0 ? 0 : rev((int)str[i - 1]));
		int t2 = rev((int)str[i]);
		cout << (t1 - t2 + 256) % 256 << endl;
	}
	return 0;
}