#include <cstdio>

using namespace std;

typedef long long ll;

const int N = 2e5 + 500;
const int MOD = 1e9 + 7;


inline int add(int A, int B){
	if(A + B >= MOD)
		return A + B - MOD;
	return A + B;
}

inline int mul(int A, int B){
	return (ll)A * B % MOD;
}

inline int sub(int A, int B){
	if(A - B < 0)
		return A - B + MOD;
	return A - B;
}


inline int pot(int A, int B){
	int ret = 1, bs = A;
	for(; B ; B >>= 1){
		if(B & 1) ret = mul(ret, bs);
		bs = mul(bs, bs);
	}
	return ret;
}

int fak[N], inv[N];

void precompute(){
	fak[0] = 1;
	for(int i = 1;i < N;i++)
		fak[i] = mul(fak[i - 1], i);
	inv[N - 1] = pot(fak[N - 1], MOD - 2);
	for(int i = N - 2;i >= 0;i--)
		inv[i] = mul(inv[i + 1], i + 1);
}

int n, k;


int main(){
	precompute();
	scanf("%d%d", &n, &k);
	int ret = 0;
	for(int i = 0;i <= n && i <= k;i++){
		ret = add(ret, mul(fak[n], mul(inv[i], inv[n - i])));
	}
	printf("%d\n", ret);
	return 0;
}