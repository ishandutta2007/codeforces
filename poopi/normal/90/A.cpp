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

int n, k;
string str;
bool mark[2010][110];
int cnt[2010][30];

int main(){
	int r, g, b;
	cin >> r >> g >> b;
	int tr = (r == 0 ? 0 : (r - 1) / 2 * 3 + 30);
	int tg = (g == 0 ? 0 : (g - 1) / 2 * 3 + 31);
	int tb = (b == 0 ? 0 : (b - 1) / 2 * 3 + 32);
	cout << max(tr, max(tb, tg)) << endl;
    return 0;
}