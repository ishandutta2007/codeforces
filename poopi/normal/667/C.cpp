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

string str;
set <string> s;
bool dp[10010][5];

void mem(int idx, int bef){
	if(dp[idx][bef]) return;
	dp[idx][bef] = true;

	for(int i = 2; i < 4; i++){
		if(idx > 4 + i && str.substr(idx - i, i) != str.substr(idx, bef)){
			s.insert(str.substr(idx - i, i));
			mem(idx - i, i);
		}
	}
}

int main(){
	cin >> str;
	int n = str.size();

	if(n > 6){
		s.insert(str.substr(n - 2));
		mem(n - 2, 2);
	}

	if(n > 7){
		s.insert(str.substr(n - 3));
		mem(n - 3, 3);
	}

	cout << s.size() << endl;
	for(set <string>::iterator it = s.begin(); it != s.end(); it++)
		cout << (*it) << endl;
	return 0;
}