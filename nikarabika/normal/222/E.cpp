#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int maxn = 55;
const LL Mod = 1e9 + 7;
LL n, m, k;

int func(char c){
	if(c >= 'a')
		return c - 'a';
	return c - 'A' + 26;
}

struct Matrice{
	int n, m;
	LL a[maxn][maxn];
	Matrice(int x = maxn, int y = maxn, LL val = 0)
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
	cin >> n >> m >> k;
	Matrice A(m, m);
	for(int i = 0; i < m; i++)
		for(int j = 0; j < m; j++)
			A[i][j] = 1;
	for(int i = 0; i < k; i++){
		string s;
		cin >> s;
		A[func(s[1])][func(s[0])] = 0;
	}
	Matrice B = Pow(A, n - 1);
	Matrice C(m, 1);
	for(int i = 0; i < m; i++)
		C[i][0] = 1;
	Matrice D = B * C;
	LL sum = 0;
	for(int i = 0; i < m; i++)
		sum = (sum + D[i][0]) % Mod;
	cout << sum << endl;
	return 0;
}