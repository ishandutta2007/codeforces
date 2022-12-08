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

int res = 10000;
int n, m, k;
int one[1100000];
int mat[110][110];
int mask[110];
int row[110];

int main(){
	cin >> n >> m >> k;
	if(n > m){
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> mat[j][i];
		swap(n, m);
	}
	else{
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> mat[i][j];
	}
	if(m <= 20){
		one[0] = 0;
		for(int i = 1; i < (1 << m); i++)
			one[i] = one[(i - 1) & i] + 1;
		for(int i = 0; i < n; i++){
			mask[i] = 0;
			for(int j = 0; j < m; j++)
				mask[i] += (mat[i][j] << j);
		}
		for(int v = 0; v < (1 << m); v++){
			int sum = 0;
			for(int i = 0; i < n; i++){
				int tmp = mask[i] ^ v;
				sum += min(one[tmp], m - one[tmp]);
			}
			res = min(res, sum);
		}
	}
	else{
		row[0] = 0;
		for(int i = 1; i < n; i++){
			int same = 0;
			for(int j = 0; j < m; j++)
				if(mat[0][j] == mat[i][j])
					same++;
			if(same > 10)
				row[i] = 0;
			else row[i] = 1;
		}
		res = 0;
		for(int j = 0; j < m; j++){
			int same = 0;
			for(int i = 0; i < n; i++)
				if(mat[i][j] == row[i])
					same++;
			res += min(same, n - same);
		}
	}
	cout << (res > k ? -1 : res) << endl;
	return 0;
}