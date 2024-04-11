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
#define Pss pair<string, string>
#define PLL pair<int64, int64>
#define Inf 1000000
#define Mod 1000000007LL

int r, c;
char ch[4];
char mat[60][60];

bool isOk(){
	sort(ch, ch + 4);
	string str = "acef";
	for(int i = 0; i < 4; i++)
		if(str[i] != ch[i])
			return false;
	return true;
}

int main(){
	cin >> r >> c;
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			cin >> mat[i][j];
	int cnt = 0;
	for(int i = 0; i + 1 < r; i++){
		for(int j = 0; j + 1 < c; j++){
			ch[0] = mat[i][j];
			ch[1] = mat[i][j + 1];
			ch[2] = mat[i + 1][j];
			ch[3] = mat[i + 1][j + 1];
			if(isOk())
				cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}