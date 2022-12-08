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
#define Pss pair<string, string>
#define PLL pair<int64, int64>
#define Inf 1000000
#define Mod 1000000007LL
//#define cin fin
//#define cout fout

int n;
int mat[110][110];
bool mark[110][110];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> mat[i][j];
	for(int i = 0; i < n; i++){
		mark[i][i] = true;
		mark[i][n - 1 - i] = true;
		mark[i][(n - 1) / 2] = true;
		mark[(n - 1) / 2][i] = true;
	}
	int cnt = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(mark[i][j])
				cnt += mat[i][j];
	cout << cnt << endl;
    return 0;
}