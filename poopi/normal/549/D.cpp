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
int ini[110][110];
int cnt[110][110];

int main(){
	cin >> r >> c;
	char ch;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cin >> ch;
			ini[i][j] = (ch == 'B' ? -1 : 1);
		}
	}
	int res = 0;
	for(int i = r - 1; i >= 0; i--){
		for(int j = c - 1; j >= 0; j--){
			if(ini[i][j] != cnt[i][j]){
				res++;
				int d = ini[i][j] - cnt[i][j];
				for(int a = 0; a <= i; a++)
					for(int b = 0; b <= j; b++)
						cnt[a][b] += d;
			}
		}
	}
	cout << res << endl;
	return 0;
}