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

int n, k, t;

int main(){
	cin >> n >> k >> t;
	int v = (n * k * t) / 100;
	for(int i = 0; i < n; i++){
		cout << min(v, k) << ' ';
		v -= min(v, k);
	}
	cout << endl;
    return 0;
}