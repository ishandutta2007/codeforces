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

int n;
int rad[1010][3];
int xa, xb, ya, yb;

bool can(int x, int y, int idx){
	int dx = x - rad[idx][0];
	int dy = y - rad[idx][1];
	return (dx * dx) + (dy * dy) <= rad[idx][2] * rad[idx][2];
}

int main(){
	cin >> xa >> ya >> xb >> yb;
	if(xa > xb)
		swap(xa, xb);
	if(ya > yb)
		swap(ya, yb);
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < 3; j++)
			cin >> rad[i][j];
	int cnt = 0;
	for(int i = ya; i <= yb; i++){
		bool f1 = false, f2 = false;
		for(int j = 0; j < n; j++){
			if(can(xa, i, j)) f1 = true;
			if(can(xb, i, j)) f2 = true;
		}
		if(!f1) cnt++;
		if(!f2) cnt++;
	}
	for(int i = xa + 1; i < xb; i++){
		bool f1 = false, f2 = false;
		for(int j = 0; j < n; j++){
			if(can(i, ya, j)) f1 = true;
			if(can(i, yb, j)) f2 = true;
		}
		if(!f1) cnt++;
		if(!f2) cnt++;
	}
	cout << cnt << endl;
	return 0;
}