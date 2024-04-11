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

int n;
int x[3010], y[3010];
int mat[3100][3100];
int arr[9001000];
int64 mask[3010][55];

bool can(int val){
	int sz = (n + 63) / 64;
	for(int i = 0; i < n; i++){
		for(int p = 0, j = 0; j < n; j += 64, p++){
			mask[i][p] = 0;
			for(int k = 0; k < 64; k++)
				if(mat[i][j + k] >= val)
					mask[i][p] += (1LL << k);
		}
		for(int j = 0; j < i; j++){
			if(mat[i][j] < val) 
				continue;
			for(int p = 0; p < sz; p++){
				if(mask[i][p] & mask[j][p])
					return true;
			}
		}
	}
	return false;
}

int main(){
	cin >> n;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		//scanf("%d%d", &x[i], &y[i]);
		cin >> x[i] >> y[i];
		for(int j = 0; j < i; j++){
			int dx = x[i] - x[j];
			int dy = y[i] - y[j];
			int tmp = dx * dx + dy * dy;
			arr[cnt++] = mat[j][i] = mat[i][j] = tmp;
		}
	}
	sort(arr, arr + cnt);
	int l = 0, r = cnt - 1;
	while(l < r){
		int mid = (l + r + 1) / 2;
		if(can(arr[mid]))
			l = mid;
		else r = mid - 1;
	}
	cout << setprecision(9) << fixed << showpoint << sqrt((double)arr[r]) / 2 << endl;
	return 0;
}