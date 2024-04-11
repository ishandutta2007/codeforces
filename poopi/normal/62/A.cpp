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

int main(){
	int a, b, x, y;
	cin >> a >> b >> x >> y;
	if((a - 1 <= y && y <= 2 * (a + 1)) || (b - 1 <= x && x <= 2 * (b + 1)))
		cout << "YES" << endl;
	else cout << "NO" << endl;
    return 0;
}