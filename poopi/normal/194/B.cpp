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

int n, x, cnt;
int arr[1000];

int main(){
	int t;
	int64 n;
	for(cin >> t; t--; ){
		cin >> n;
		if((n + 1) % 4 == 0)
			cout << n + 1 << endl;
		else if((n + 1) % 2 == 0)
			cout << 2 * n + 1 << endl;
		else cout << 4 * n + 1 << endl;
	}
    return 0;
}