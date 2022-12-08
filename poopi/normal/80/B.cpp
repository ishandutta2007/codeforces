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
//#define cin fin
//#define cout fout

string str;

int main(){
	cin >> str;
	int a = ((str[0] - '0') * 10 + str[1] - '0') % 12;
	int b = (str[3] - '0') * 10 + str[4] - '0';
	cout << setprecision(1) << fixed << showpoint << (a * 60 + b) / 2. << ' ' << b * 6 << endl;
    return 0;
}