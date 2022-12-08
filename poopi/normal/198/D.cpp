									/* in the name of Allah */
#include <iostream>
using namespace std;

int mat[60][60][60][60];

void init(){
	mat[1][0][0][0] = 1;
	mat[2][0][0][0] = 1;
	mat[2][0][1][0] = 2;
	mat[2][0][1][1] = 3;
	mat[2][0][0][1] = 4;
	mat[2][1][0][1] = 5;
	mat[2][1][1][1] = 6;
	mat[2][1][1][0] = 7;
	mat[2][1][0][0] = 8;
}

void odd(int n){
	int p = 0;
	for(int k = 0; k < n; k++){
		if(k % 2)
			for(int j = n - 1; j >= 0; j--)
				mat[n][0][j][k] = ++p;
		else for(int j = 0; j < n; j++)
				mat[n][0][j][k] = ++p;
	}
	for(int i = 0; i < n - 1; i++)
		for(int j = 0; j < n - 1; j++)
			for(int k = 0; k < n - 1; k++)
				mat[n][k + 1][n - 1 - i][n - 1 - j] = mat[n - 1][i][j][k] + p;
	p += (n - 1) * (n - 1) * (n - 1);
	for(int k = n - 1; k > 0; k--){
		if(k % 2)
			for(int i = n - 1; i > 0; i--)
				mat[n][i][0][k] = ++p;
		else for(int i = 1; i < n; i++)
				mat[n][i][0][k] = ++p;
	}
	for(int i = 1; i < n; i++){
		if(i % 2)
			for(int j = 0; j < n; j++)
				mat[n][i][j][0] = ++p;
		else for(int j = n - 1; j >= 0; j--)
				mat[n][i][j][0] = ++p; 
	}
}

void even(int n){
	int p = 0;
	for(int k = 0; k < n; k++){
		if(k % 2)
			for(int j = n - 1; j >= 0; j--)
				mat[n][0][j][k] = ++p;
		else for(int j = 0; j < n; j++)
				mat[n][0][j][k] = ++p;
	}
	for(int i = 0; i < n - 1; i++)
		for(int j = 0; j < n - 1; j++)
			for(int k = 0; k < n - 1; k++)
				mat[n][j + 1][i][n - 1 - k] = mat[n - 1][i][j][k] + p;
	p += (n - 1) * (n - 1) * (n - 1);
	for(int k = n - 1; k > 0; k--){
		if(k % 2)
			for(int i = 1; i < n; i++)
				mat[n][i][n - 1][k] = ++p;
		else for(int i = n - 1; i > 0; i--)
				mat[n][i][n - 1][k] = ++p;
	}
	for(int j = n - 1; j >= 0; j--){
		if(j % 2)
			for(int i = n - 1; i > 0; i--)
				mat[n][i][j][0] = ++p; 
		else for(int i = 1; i < n; i++)
				mat[n][i][j][0] = ++p;
	}
}

int main(){
	init();
	for(int i = 3; i <= 50; i++){
		if(i % 2)
			odd(i);
		else even(i);
	}
	int n;
	cin >> n;
	for(int k = 0; k < n; k++){
		for(int j = 0; j < n; j++){
			for(int i = 0; i < n; i++)
				cout << mat[n][i][j][k] << ' ';
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}