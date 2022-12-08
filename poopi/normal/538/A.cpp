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

string s;
string n = "CODEFORCES";

int main(){
	cin >> s;
	string res = "NO";
	for(int i = 0; i < s.length(); i++){
		for(int j = i; j <= s.length(); j++){
			string tmp = s.substr(0, i) + s.substr(j);
			if(tmp == n)
				res = "YES";
		}
	}
	cout << res << endl;
	return 0;
}