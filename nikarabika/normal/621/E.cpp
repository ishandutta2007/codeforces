//sobskdrbhvk
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

const LL Mod = 1000LL * 1000 * 1000 + 7;
int k, x;
LL n, b;

struct Matrice{
	int n, m;
	LL a[100][100];
	Matrice(int x = 100, int y = 100, LL val = 0)
	:n(x), m(y){
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				a[i][j] = (i == j) * val;
	}
	LL *operator[](int i){
		return a[i];
	}
};

Matrice operator*(Matrice &A, Matrice &B){
	Matrice ret(A.n, B.m);
	for(int i = 0; i < A.n; i++)
		for(int k = 0; k < A.m; k++)
			for(int j = 0; j < B.m; j++)
				ret[i][j] = (ret[i][j] + ((A[i][k] * B[k][j]) % Mod)) % Mod;
	return ret;
}

Matrice Pow(Matrice &A, LL b){
	Matrice ret(A.n, A.n, 1), an = A;
	for(int i = 0; i < 60; i++, an = an * an)
		if((b >> i) & 1LL)
			ret = ret * an;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> b >> k >> x;
	Matrice A(x, 1), B(x, x);
	for(int i = 0; i < n; i++){
		int fi;
		cin >> fi;
		fi %= x;
		A[fi][0]++;
	}
	for(int i = 0; i < x; i++)
		for(int j = 0; j < x; j++)
			B[(i * 10 + j) % x][i] = A[j][0];
	Matrice C = Pow(B, b - 1);
	Matrice D = C * A;
	cout << D[k][0] << endl;
	return 0;
}