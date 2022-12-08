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

int cnt;
string s1, s2;

bool can(int len){
	if(s1.substr(0, len) != s2.substr(0, len))
		return false;
	for(int i = 0; i < len; i++){
		for(int j = i; j < s1.length(); j += len)
			if(s1[j] != s1[i]) return false;
		for(int j = i; j < s2.length(); j += len)
			if(s2[j] != s2[i]) return false;
	}
	return true;
}

int main(){
	cin >> s1 >> s2;
	for(int i = 1; i <= s1.length() && i <= s2.length(); i++){
		if(s1.length() % i || s2.length() % i) continue;
		if(can(i)) cnt++;
	}
	cout << cnt << endl;
	return 0;
}