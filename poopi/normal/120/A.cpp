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
#define cin fin
#define cout fout

int main(){
	string str;
	int a;
	cin >> str >> a;
	if((str[0] == 'f' && a == 1) || (str[0] == 'b' && a == 2))
		cout << 'L' << endl;
	else cout << 'R' << endl;
    return 0;
}