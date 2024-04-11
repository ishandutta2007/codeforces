#include <bits/stdc++.h>

using namespace std;

int n;
char op[1000][1000];
int x[3], y[3];

void Print(int a1, int b1, int a2, int b2, 
		int aa1, int bb1, int aa2, int bb2,
		int aaa1, int bbb1, int aaa2, int bbb2){
	for(int i = a1; i < a2; i++)
		for(int j = b1; j < b2; j++)
			op[i][j] = 'A';
	for(int i = aa1; i < aa2; i++)
		for(int j = bb1; j < bb2; j++)
			op[i][j] = 'B';
	for(int i = aaa1; i < aaa2; i++)
		for(int j = bbb1; j < bbb2; j++)
			op[i][j] = 'C';
	cout << n << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cout << op[i][j];
		cout << endl;
	}
	exit(0);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];
	int S = x[0] * y[0] + x[1] * y[1] + x[2] * y[2];
	n = sqrt(S);
	if(n * n != S){
		cout << -1 << endl;
		return 0;
	}
	if(max(max(x[0], y[0]), max(x[1], y[1])) > n or max(x[2], y[2]) > n){
		cout << -1 << endl;
		return 0;
	}
	for(int mask = 0; mask < 8; mask++){
		for(int i = 0; i < 3; i++)
			if((mask >> i) & 1)
				swap(x[i], y[i]);
	if(x[0] == n and x[1] == n and x[2] == n)
		Print(0, 0, y[0], n,
				y[0], 0, y[0] + y[1], n,
				y[0] + y[1], 0, n, n);
	if(y[0] == n and y[1] == n and y[2] == n)
		Print(0, 0, n, x[0],
				0, x[0], n, x[0] + x[1],
				0, x[0] + x[1], n, n);

	if(x[0] == n and x[1] + x[2] == n and y[1] == y[2] and y[0] + y[1] == n)
		Print(0, 0, y[0], n,
				y[0], 0, n, x[1],
				y[0], x[1], n, n);
	if(x[1] == n and x[0] + x[2] == n and y[0] == y[2] and y[0] + y[1] == n)
		Print(y[1], 0, n, x[0],
				0, 0, y[1], n,
				y[1], x[0], n, n);
	if(x[2] == n and x[0] + x[1] == n and y[0] == y[1] and y[1] + y[2] == n)
		Print(y[2], 0, n, x[0],
				y[2], x[0], n, n,
				0, 0, y[2], n);

	if(y[0] == n and y[1] + y[2] == n and x[1] == x[2] and x[0] + x[1] == n)
		Print(0, 0, n, x[0],
				0, x[0], y[1], n,
				y[1], x[0], n, n);
	if(y[1] == n and y[0] + y[2] == n and x[0] == x[2] and x[0] + x[1] == n)
		Print(0, x[1], y[0], n,
				0, 0, n, x[1],
				y[0], x[1], n, n);
	if(y[2] == n and y[0] + y[1] == n and x[0] == x[1] and x[0] + x[2] == n)
		Print(0, x[2], y[0], n,
				y[0], x[2], n, n,
				0, 0, n, x[2]);
		for(int i = 0; i < 3; i++)
			if((mask >> i) & 1)
				swap(x[i], y[i]);
	}
	cout << -1 << endl;
	return 0;
}