#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int maxn = 1e5 + 85 - 69;
const LL Mod = 1000LL * 1000 * 1000 + 7;
int d[maxn];
LL x;
int n;

struct Matrice{
	int n, m;
	LL a[101][101];
	Matrice(int x = 101, int y = 101, LL val = 0)
	:n(x), m(y){
		for(int i = 0; i < 101; i++)
			for(int j = 0; j < 101; j++)
				a[i][j] = (i == j) * val;
	}
	LL *operator[](int i){
		return a[i];
	}
};

Matrice operator*(Matrice &A, Matrice &B){
	Matrice ret(A.n, B.m);
	for(int i = 0; i < A.n; i++)
		for(int j = 0; j < B.m; j++)
			for(int k = 0; k < A.m; k++)
				ret[i][j] = (ret[i][j] + ((A[i][k] * B[k][j]) % Mod)) % Mod;
	return ret;
}

Matrice Pow(Matrice &A, LL b){
	Matrice an = A;
	Matrice ret(A.n, A.m, 1);
	for(int i = 0; i < 31; i++, an = an * an)
		if((b >> i) & 1LL)
			ret = ret * an;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> x;
	for(int i = 0; i < n; i++)
		cin >> d[i];
	sort(d, d + n);
	Matrice A(101, 101);
	for(int i = 0; i < 99; i++)
		A[i][i + 1] = 1;
	for(int i = 0; i < n; i++)
		A[99][100 - d[i]]++;
	A[100][0] = A[100][100] = 1;
	Matrice B(101, 1);
	B[0][0] = 1;
	for(int i = 0; i < 100; i++)
		for(int j = 0; j < n and i + d[j] < 100; j++)
			B[i + d[j]][0] = (B[i + d[j]][0] + B[i][0]) % Mod;
	B[100][0] = 0;
	Matrice C = Pow(A, x + 1);
	Matrice D = C * B;
	cout << D[100][0] << endl;
	return 0;
}