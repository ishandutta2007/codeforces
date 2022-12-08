							/* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>
using namespace std;

int n, m, a, b, c;
char mat[110][110];

void fun(int x, int y, char c1, char c2, char c3, char c4){
	mat[x][y] = c1;
	mat[x][y + 1] = c2;
	mat[x + 1][y] = c3;
	mat[x + 1][y + 1] = c4;
}

int main(){
	cin >> n >> m >> a >> b >> c;
	if((n * m) % 2 == 1){
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	if(n % 2 == 1){
		if(a < m / 2){
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
		a -= m / 2;
		for(int i = 0; i < m / 2; i++)
			mat[n - 1][2 * i] = mat[n - 1][2 * i + 1] = (char)('n' + i % 2);
	}
	if(m % 2 == 1){
		if(b < n / 2){
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
		b -= n / 2;
		for(int i = 0; i < n / 2; i++)
			mat[2 * i][m - 1] = mat[2 * i + 1][m - 1] = (char)('x' + i % 2);
	}
	int row = n - n % 2;
	int col = m - m % 2;
	if(row * col / 4 > a / 2 + b / 2 + c){
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	for(int i = 0; i < row / 2; i++){
		for(int j = 0; j < col / 2; j++){
			char t = (char)('a' + (i % 2) * 2 + j % 2);
			if(c > 0){
				c--;
				fun(2 * i, 2 * j, t, t, t, t);
			}
			else if(b >= 2){
				b -= 2;
				fun(2 * i, 2 * j, t, t + 5, t, t + 5);
			}
			else if(a >= 2){
				a -= 2;
				fun(2 * i, 2 * j, t, t, t + 5, t + 5);
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			cout << mat[i][j];
		cout << endl;
	}
	return 0;
}