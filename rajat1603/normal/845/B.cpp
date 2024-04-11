#include "bits/stdc++.h"
using namespace std;
string str;
int ans;
int cst[6][10];
int main(){
	cin >> str;
	ans = 6;
	for(int i = 0 ; i < 6 ; ++i){
		for(int j = 0 ; j < 10 ; ++j){
			cst[i][j] = 1;
		}
		cst[i][str[i] - '0'] = 0;
	}
	for(int i = 0 ; i < 10 ; ++i){
		for(int j = 0 ; j < 10 ; ++j){
			for(int k = 0 ; k < 10 ; ++k){
				for(int l = 0 ; l < 10 ; ++l){
					for(int m = 0 ; m < 10 ; ++m){
						for(int n = 0 ; n < 10 ; ++n){
							if(i + j + k == l + m + n){
								ans = min(ans , cst[0][i] + cst[1][j] + cst[2][k] + cst[3][l] + cst[4][m] + cst[5][n]);
							}
						}
					}
				}
			}
		}
	}
	printf("%d\n" , ans);
}