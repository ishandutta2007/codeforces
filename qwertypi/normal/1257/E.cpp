#include <bits/stdc++.h>

using namespace std;

int A[200002];
int data[3][200002];

int getData(int l, int r, int kind){
	return data[kind - 1][r + 1] - data[kind - 1][l];
}

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	for(int i = 0; i < a; i++){
		int v;
		cin >> v;
		A[--v] = 0;
	}
	for(int i = 0; i < b; i++){
		int v;
		cin >> v;
		A[--v] = 1;
	}
	for(int i = 0; i < c; i++){
		int v;
		cin >> v;
		A[--v] = 2;
	}
	int n = a + b + c;
	for(int i = 0; i < 3; i++){
		data[i][0] = 0;
		for(int j = 0; j < n; j++){
			data[i][j + 1] = data[i][j] + (A[j] == i);
		}
	}
	int ans = (1 << 30);
	int curBest = 0;
	for(int j = -1; j < n; j++){
		int out = c - getData(j + 1, n - 1, 3);
		int in = n - j - 1 - getData(j + 1, n - 1, 3);
		if(getData(0, curBest, 2) + getData(curBest + 1, j, 1) > getData(0, j, 2)){
			curBest = j;
		}
		int res = getData(0, curBest, 2) + getData(curBest + 1, j, 1) + in + out;
		ans = min(ans, res);
	}
	cout << ans << endl;
}