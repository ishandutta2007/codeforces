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

ifstream fin("input.txt");
ofstream fout("output.txt");

#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define Pss pair<string, string>
#define PLL pair<int64, int64>
#define Inf 1000000
#define Mod 1000000007LL
//#define cin fin
//#define cout fout

int k;
string str;

int main(){
	cin >> k >> str;
	int cnt = 0;
	for(int i = k; i < str.length(); i += k)
		if(str[i - 1] == str[i - 2] && str[i - 2] == str[i - 3])
			cnt++;
	cout << cnt << endl;
}