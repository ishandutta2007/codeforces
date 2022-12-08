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

#define Inf 1000000001
int k, a, b;
int r, c, x, y;

int main(){
	cin >> r >> c >> x >> y >> k;
	x--, y--;
	int64 cnt = 0;
	for(int i = 0; i < k; i++){
		cin >> a >> b;
		int cr = (a == 0 ? Inf : (a < 0 ? -x : r - x - 1) / a);
		int cc = (b == 0 ? Inf : (b < 0 ? -y : c - y - 1) / b);
		int dif = min(cr, cc);
		x += dif * a;
		y += dif * b;
		cnt += dif;
	}
	cout << cnt << endl;
    return 0;
}