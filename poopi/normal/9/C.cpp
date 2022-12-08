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

int n;

int main(){
	cin >> n;
	int cnt = 0;
	for(int i = 1; i < (1 << 10); i++){
		int tmp = 0;
		for(int j = 0; j < 10; j++)
			tmp = tmp * 10 + ((i >> (9 - j)) & 1);
		if(tmp <= n)
			cnt++;
	}
	cout << cnt << endl;
}