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

#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define PLL pair<int64, int64>

int n, m;
int tm[100010];

int main(){
	cin >> n >> m;
	int a, b;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		tm[i] = a * b;
	}
	int p = 0, tot = tm[0];
	for(int i = 0; i < m; i++){
		cin >> a;
		while(tot < a)
			tot += tm[++p];
		cout << p + 1 << endl;
	}
	return 0;
}