#include <iostream>
typedef long long ll;
template <class T>
T powmod(T a, ll b, ll m){
	T res = 1;
	while(b){
		if(b % 2){
			res *= a;
			res %= m;
		}
		a = (a * a) % m;
		b /= 2;
	}
	return res;
}
 
using namespace std;
int A[1000][1000];
int R[1000], C[1000];
int main(){
	int r, c;
	cin >> r >> c;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			A[i][j] = -1;
		}
	}
	for(int i = 0; i < r; i++){
		cin >> R[i];
		for(int j = 0; j < R[i]; j++){
			A[i][j] = 1;
		}
		A[i][R[i]] = 0;
	}
	for(int i = 0; i < c; i++){
		cin >> C[i];
		for(int j = 0; j < C[i]; j++){
			if(A[j][i] == 0){
				cout << 0;
				return 0;
			}
			A[j][i] = 1;
		}
		if(A[C[i]][i] == 1){
			cout << 0;
			return 0;
		}
		A[C[i]][i] = 0;
	}
	int cnt = 0;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cnt += (A[i][j] == -1);
		}
	}
	cout << powmod<long long>(2, cnt, 1000000007);
}