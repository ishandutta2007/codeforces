//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()
#define base basE

LL n, sx, sy, dx, dy, t;

struct matrix{
	LL a[6][6];
	LL *operator[](int i){return a[i];}
} base, mat;

matrix operator*(matrix &A, matrix &B){
	matrix ret;
	for(int i = 0; i < 6; i++)
		for(int j = 0; j < 6; j++)
			ret[i][j] = 0;
	for(int i = 0; i < 6; i++)
		for(int j = 0; j < 6; j++)
			for(int k = 0; k < 6; k++)
				ret[i][j] += A[i][k] * B[k][j];
	for(int i = 0; i < 6; i++)
		for(int j = 0; j < 6; j++)
			ret[i][j] %= n;
	return ret;
}

matrix Pow(matrix &A, LL y){
	matrix an = A, ret;
	for(int i = 0; i < 6; i++)
		for(int j = 0; j < 6; j++)
			ret[i][j] = i == j;
	while(y){
		if(y&1) ret = ret * an;
		an = an * an;
		y >>= 1;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> sx >> sy
		>> dx >> dy >> t;
	sx--, sy--;
	base[0][0] = sx, base[1][0] = sy;
	base[2][0] = dx, base[3][0] = dy;
	base[4][0] = 0, base[5][0] = 1;
	int tam[6][6] = {
		{2, 1, 1, 0, 1, 2},
		{1, 2, 0, 1, 1, 2},
		{1, 1, 1, 0, 1, 2},
		{1, 1, 0, 1, 1, 2},
		{0, 0, 0, 0, 1, 1},
		{0, 0, 0, 0, 0, 1}
	};
	for(int i = 0; i < 6; i++)
		for(int j = 0; j < 6; j++)
			mat[i][j] = tam[i][j];
	mat = Pow(mat, t);
	base = mat * base;
	base[0][0] = (base[0][0]%n + n) % n;
	base[1][0] = (base[1][0]%n + n) % n;
	cout << base[0][0] + 1 << ' ' << base[1][0] + 1 << '\n';
	return 0;
}