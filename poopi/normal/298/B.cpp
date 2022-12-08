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

char ch[4] = {'E', 'S', 'W', 'N'};
int dir[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

int getId(char c){
	for(int i = 0; i < 4; i++)
		if(ch[i] == c)
			return i;
}

int main(){
	int t, sx, sy, ex, ey;
	cin >> t >> sx >> sy >> ex >> ey;
	string str;
	cin >> str;
	int dx = ex - sx;
	int dy = ey - sy;
	int pnt = 0;
	while(pnt < str.length() && (dx != 0 || dy != 0)){
		int id = getId(str[pnt]);
		if(dir[id][0] * dx + dir[id][1] * dy > 0){
			dx -= dir[id][0];
			dy -= dir[id][1];
		}
		pnt++;
	}
	if(dx != 0 || dy != 0)
		cout << -1 << endl;
	else cout << pnt << endl;
    return 0;
}