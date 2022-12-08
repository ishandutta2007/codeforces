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
	int vp, vd, d, s;
	double len;
	cin >> vp >> vd >> d >> s >> len;
	if(vd <= vp){
		cout << 0 << endl;
		return 0;
	}
	int cnt = 0;
	double x = vp * (d + (double)vp * d / (vd - vp));
	while(x + 1e-9 < len){
		cnt++;
		double tm = 2 * x / vd + s;
		x += vp * (tm + vp * tm / (vd - vp));
	}
	cout << cnt << endl;
    return 0;
}