#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define PB push_back

LL Mod, l, r, k;
vector<LL> s;

struct Matrice{
	LL a[2][2];
	Matrice(){
		a[0][0] = a[1][1] = 1;
		a[0][1] = a[1][0] = 0;
		return;
	}
	LL *operator[](int i){
		return a[i];
	}
};

Matrice operator*(Matrice &A, Matrice &B){
	Matrice ret;
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++){
			ret[i][j] = 0;
			for(int k = 0; k < 2; k++)
				ret[i][j] = (ret[i][j] + ((A[i][k] * B[k][j]) % Mod)) % Mod;
		}
	return ret;
}

Matrice Pow(Matrice &A, LL b){
	Matrice ret;
	Matrice an = A;
	for(int i = 0; i < 48; i++, an = an * an)
		if((b >> i) & 1LL)
			ret = ret * an;
	return ret;
}

LL fib(LL id){
	Matrice A;
	A[1][1] = 0;
	A[0][1] = A[1][0] = 1;
	Matrice B = Pow(A, id);
	return B[0][1];
}

bool check(LL x){
	return r / x - (l - 1LL) / x >= k;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> Mod >> l >> r >> k;
	for(LL i = 1; i * i <= l - 1; i++){
		s.PB(i);
		s.PB((l - 1) / i);
	}
	for(LL i = 1; i * i <= r; i++){
		s.PB(i);
		s.PB(r / i);
	}
	LL ans = 0;
	for(auto x : s)
		for(int j = -1; j <= 1; j++)
			if(x + j > 0 and r / (x + j) - (l - 1) / (x + j) >= k)
				ans = max(x + j, ans);
	cout << fib(ans) << endl;
	return 0;
}