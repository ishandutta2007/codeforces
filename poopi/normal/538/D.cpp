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

int n, B;
char mat[60][60];
char res[110][110];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> mat[i][j];

	B = n - 1;
	for(int i = 0; i < 2 * n - 1; i++)
		for(int j = 0; j < 2 * n - 1; j++)
			res[i][j] = 'x';
	res[B][B] = 'o';

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(mat[i][j] != 'o')
				continue;
			for(int r = 0; r < n; r++){
				for(int c = 0; c < n; c++){
					if(mat[r][c] != '.')
						continue;
					res[B + r - i][B + c - j] = '.';
				}
			}
		}
	}
	
	string ans = "YES";
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(mat[i][j] != 'x')
				continue;
			bool ok = false;
			for(int r = 0; r < n; r++){
				for(int c = 0; c < n; c++){
					if(mat[r][c] != 'o')
						continue;
					if(res[B + i - r][B + j - c] == 'x')
						ok = true;
				}
			}
			if(!ok)
				ans = "NO";
		}
	}
	cout << ans << endl;
	if(ans == "YES"){
		for(int i = 0; i < 2 * n - 1; i++){
			for(int j = 0; j < 2 * n - 1; j++)
				cout << res[i][j];
			cout << endl;
		}
	}
	return 0;
}