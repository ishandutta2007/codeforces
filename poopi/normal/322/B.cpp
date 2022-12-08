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

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	int t1 = a / 3 + b / 3 + c / 3 + min(a % 3, min(b % 3, c % 3));
	a -= 2, b -= 2, c -= 2;
	int t2 = a / 3 + b / 3 + c / 3 + min(a % 3, min(b % 3, c % 3)) + 2;
	cout << max(t1, t2) << endl;
    return 0;
}