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

bool mark[200000010];

int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		mark[i * i] = true;
	int cnt = 0;
	for(int i = 1; i <= n; i++)
		for(int j = i; j <= n; j++)
			if(mark[i * i + j * j])
				cnt++;
	cout << cnt << endl;
    return 0;
}