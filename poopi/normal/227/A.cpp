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
#define PLL pair<int64, int64>
//#define cin fin
//#define cout fout

int64 x[3], y[3];

int main(){
	for(int i = 0; i < 3; i++)
		cin >> x[i] >> y[i];
	int64 dx1 = x[1] - x[0];
	int64 dy1 = y[1] - y[0];
	int64 dx2 = x[2] - x[1];
	int64 dy2 = y[2] - y[1];
	int64 t = dx1 * dy2 - dx2 * dy1;
	if(t > 0)
		cout << "LEFT" << endl;
	if(t == 0)
		cout << "TOWARDS" << endl;
	if(t < 0)
		cout << "RIGHT" << endl;
    return 0;
}