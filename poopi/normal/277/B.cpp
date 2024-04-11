										/* in the name of Allah */
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int, int>
#define M1 900000

int n, m;
int x[300], y[300];

int main(){
	cin >> n >> m;
	if(m == 3 && n >= 5){
		cout << -1 << endl;
		return 0;
	}
	double alph = acos(-1.) / m;
	for(int i = 0; i < m; i++){
		x[m + i] = M1 * cos(alph * i);
		x[i] = x[m + i];
		y[m + i] = M1 * sin(alph * i) - 10000000;
		y[i] = -y[m + i];
	}
	for(int i = 0; i < n; i++)
		cout << x[i] << ' ' << y[i] << endl;
	return 0;
}