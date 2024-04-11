										/* in the name of Allah */
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <memory.h>

using namespace std;

int n;
char mat[4][100];

int main(){
	while(cin >> n){
		for(int i = 0; i + 1< n; i += 2){
			mat[0][i] = mat[0][i + 1] = ((i / 2) % 2 ? 'a' : 'b');
			mat[1][i] = mat[1][i + 1] = ((i / 2) % 2 ? 'b' : 'a');
		}
		if(n % 2){
			mat[0][n - 1] = mat[1][n - 1] = 'c';
		}
		mat[2][0] = mat[3][0] = 'd';
		for(int i = 1; i + 1 < n; i += 2){
			mat[2][i] = mat[2][i + 1] = ((i / 2) % 2 ? 'x' : 'y');
			mat[3][i] = mat[3][i + 1] = ((i / 2) % 2 ? 'y' : 'x');
		}
		if(n % 2 == 0){
			mat[2][n - 1] = mat[3][n - 1] = 'e';
		}
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < n; j++)
				cout << mat[i][j];
			cout << endl;
		}
	}
	return 0;
}