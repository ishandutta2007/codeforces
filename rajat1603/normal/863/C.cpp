#include "bits/stdc++.h"
using namespace std;
const int N = 3;
long long k;
int a , b;
int alice[N][N];
int bob[N][N];
long long ans;
struct mat{
	long long x[N][N][N][N];
	long long y[N][N][N][N];
	bool possible[N][N][N][N];
	mat(){
		memset(x , 0 , sizeof(x));
		memset(y , 0 , sizeof(y));
		memset(possible , 0 , sizeof(possible));
	}
};
int get(int x , int y){
	if(x == y){
		return 0;
	}
	if(x == ((y + 1) % 3)){
		return 1;
	}
	return 2;
}
mat base;
mat mult(mat a , mat b){
	mat res;
	for(int i = 0 ; i < 3 ; ++i){
		for(int j = 0 ; j < 3 ; ++j){
			for(int k = 0 ; k < 3 ; ++k){
				for(int l = 0 ; l < 3 ; ++l){
					if(!a.possible[i][j][k][l]){
						continue;
					}
					for(int x = 0 ; x < 3 ; ++x){
						for(int y = 0 ; y < 3 ; ++y){
							if(!b.possible[k][l][x][y]){
								continue;
							}
							res.x[i][j][x][y] += a.x[i][j][k][l] + b.x[k][l][x][y];
							res.y[i][j][x][y] += a.y[i][j][k][l] + b.y[k][l][x][y];
							res.possible[i][j][x][y] = 1;
						}
					}
				}
			}
		}
	}
	return res;
}
void power(){
	mat res;
	res = base;
	--k;
	while(k){
		if(k & 1){
			res = mult(res , base);
		}
		base = mult(base , base);
		k >>= 1;
	}
	base = res;
}
int main(){
	cin >> k >> a >> b;
	--a;
	--b;
	for(int i = 0 ; i < 3 ; ++i){
		for(int j = 0 ; j < 3 ; ++j){
			cin >> alice[i][j];
		}
	}
	for(int j = 0 ; j < 3 ; ++j){
		for(int k = 0 ; k < 3 ; ++k){
			cin >> bob[j][k];
		}
	}
	for(int i = 0 ; i < 3 ; ++i){
		for(int j = 0 ; j < 3 ; ++j){
			int k = alice[i][j] - 1;
			int l = bob[i][j] - 1;
			if(get(i , j) == 1){
				++base.x[i][j][k][l];
			}
			if(get(i , j) == 2){
				++base.y[i][j][k][l];
			}
			base.possible[i][j][k][l] = 1;
		}
	}
	power();
	long long res1 = 0;
	long long res2 = 0;
	for(int i = 0 ; i < 3 ; ++i){
		for(int j = 0 ; j < 3 ; ++j){
			if(base.possible[a][b][i][j]){
				res1 += base.x[a][b][i][j];
				res2 += base.y[a][b][i][j];
			}
		}
	}
	printf("%lld %lld\n" , res1 , res2);
}