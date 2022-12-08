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
bool mat[2010][2010];

void setMat(int a, int b){
	mat[a][b] = mat[b][a] = true;
}

int setG(int s, int t, int k){
	if(k == 1){
		setMat(s, t);
		return 1;
	}
	setMat(s, n);
	setMat(s, n + 1);
	setMat(n + 2, n);
	setMat(n + 2, n + 1);
	n += 3;
	int len = setG(n - 1, t, k / 2);
	if(k & 1){
		int bef = s;
		for(int i = 0; i <= len; i++){
			setMat(bef, n + i);
			bef = n + i;
		}
		setMat(n + len, t);
		n += len + 1;
	}
	return len + 2;
}

int main(){
	int k;
	cin >> k;
	n = 2;
	setG(0, 1, k);
	cout << n << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cout << (mat[i][j] ? 'Y' : 'N');
		cout << endl;
	}
	return 0;
}