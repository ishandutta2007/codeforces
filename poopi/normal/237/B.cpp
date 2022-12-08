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

int n, cnt, sz[60];
int mat[60][60];
int ref[3000][2];
int out[3000][4];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> sz[i];
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < sz[i]; j++){
			cin >> mat[i][j];
			ref[mat[i][j]][0] = i;
			ref[mat[i][j]][1] = j;
		}
	}
	int p = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < sz[i]; j++, p++){
			if(mat[i][j] == p)
				continue;
			out[cnt][0] = i;
			out[cnt][1] = j;
			out[cnt][2] = ref[p][0];
			out[cnt++][3] = ref[p][1];
			int v = mat[i][j];
			swap(mat[i][j], mat[ref[p][0]][ref[p][1]]);
			ref[v][0] = ref[p][0];
			ref[v][1] = ref[p][1];
			ref[p][0] = i;
			ref[p][1] = j;
		}
	}
	cout << cnt << endl;
	for(int i = 0; i < cnt; i++){
		for(int j = 0; j < 4; j++)
			cout << out[i][j] + 1 << ' ';
		cout << endl;
	}
    return 0;
}