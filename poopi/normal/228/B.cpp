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

int r, c, x, y;
int a[60][60];
int b[60][60];

int main(){
	string str;
	cin >> r >> c;
	for(int i = 0; i < r; i++){
		cin >> str;
		for(int j = 0; j < c; j++)
			a[i][j] = str[j] - '0';
	}
	cin >> x >> y;
	for(int i = 0; i < x; i++){
		cin >> str;
		for(int j = 0; j < y; j++)
			b[i][j] = str[j] - '0';
	}
	int rx, ry, mx = -1;
	for(int sx = -r + 1; sx < x; sx++){
		for(int sy = -c + 1; sy < y; sy++){
			int tmp = 0;
			for(int i = 0; i < r; i++)
				for(int j = 0; j < c; j++)
					if(i + sx >= 0 && i + sx < x && j + sy >= 0 && j + sy < y)
						tmp += a[i][j] * b[i + sx][j + sy];
			if(tmp > mx){
				mx = tmp;
				rx = sx;
				ry = sy;
			}
		}
	}
	cout << rx << ' ' << ry << endl;
    return 0;
}