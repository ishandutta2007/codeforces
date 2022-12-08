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

int n, m;
int mat[1100][1100];
int arr[1000100];
int64 mask[1010][30];

bool can(int val){
	int sz = (m + 63) / 64;
	for(int i = 0; i < n; i++){
		for(int p = 0, j = 0; j < m; j += 64, p++){
			mask[i][p] = 0;
			for(int k = 0; k < 64; k++)
				if(mat[i][j + k] >= val)
					mask[i][p] += (1LL << k);
		}
		for(int j = 0; j < i; j++){
			int cnt = 0;
			for(int p = 0; p < sz; p++){
				int64 vv = (mask[i][p] & mask[j][p]);
				if(vv){
					if((vv & (vv - 1)))
						return true;
					else{
						cnt++;
						if(cnt > 1)
							return true;
					}
				}
			}
		}
	}
	return false;
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &mat[i][j]);
			//cin >> mat[i][j];
			arr[i * m + j] = mat[i][j];
		}
	}
	sort(arr, arr + n * m);
	int l = 0, r = n * m - 1;
	while(l < r){
		int mid = (l + r + 1) / 2;
		if(can(arr[mid]))
			l = mid;
		else r = mid - 1;
	}
	cout << arr[r] << endl;
	return 0;
}