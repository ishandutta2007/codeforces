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
	double a, b, c, d;
	cin >> a >> b >> c >> d;
	double alph = (d - c) / d * (b - a) / b;
	double p = a / b / (1 - alph);
	cout << setprecision(10) << fixed << showpoint << p << endl;
    return 0;
}