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

int64 c[35][35];

int main(){
	c[0][0] = 1;
	for(int i = 1; i < 35; i++){
		c[0][i] = c[i][i] = 1;
		for(int j = 1; j < i; j++)
			c[j][i] = c[j - 1][i - 1] + c[j][i - 1];
	}
	int n, m, t;
	cin >> n >> m >> t;
	int64 res = 0;
	for(int i = 4; i < t; i++){
		if(i > n || t - i > m || t - i < 1)
			continue;
		res += c[i][n] * c[t - i][m];
	}
	cout << res << endl;
    return 0;
}