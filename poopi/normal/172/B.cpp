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

int a, b, m, r;
int mark[100010];

int main(){
	cin >> a >> b >> m >> r;
	int cnt = 1;
	while(!mark[r]){
		mark[r] = cnt++;
		r = (a * r + b) % m;
	}
	cout << cnt - mark[r] << endl;
    return 0;
}