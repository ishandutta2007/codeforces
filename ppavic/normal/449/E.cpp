#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;

const int N = 1e6 + 500;
const int MOD = 1e9 + 7;

inline int add(int A, int B){
	if(A + B >= MOD)
		return A + B - MOD;
	return A + B;
}

inline int sub(int A, int B){
	if(A - B < 0)
		return A - B + MOD;
	return A - B;
}

inline int mul(int A, int B){
	return (ll)A * B % MOD;
}

int phi[N], S[N], S2[N], Sgcd[N];
int F[N], D[N], K[N];

void precompute(){
	for(int i = 1;i < N;i++){
		S[i] = add(S[i - 1], i);
		S2[i] = add(S2[i - 1], mul(i, i));
		phi[i] = i - 1;
	}
	phi[0] = 0; phi[1] = 1;
	for(int i = 2;i < N;i++)
		for(int j = 2 * i;j < N;j += i)
			phi[j] -= phi[i];
	for(int i = 1;i < N;i++)
		for(int j = i;j < N;j += i)
			Sgcd[j] = add(Sgcd[j], mul(i, phi[j / i]));
	for(int n = 1;n < N;n++){
		F[n] = sub(mul(mul(n, n), n), mul(2 * n, S[n]));
		F[n] = add(F[n], sub(mul(2, S2[n]), mul(2 * n, n)));
		F[n] = add(F[n], mul(2, Sgcd[n]));
	}
	int sm = 0;
	for(int i = 1;i < N;i++){
		sm = add(sm, F[i]);
		D[i] = add(D[i - 1], sm);
	}
	for(int i = 1;i < N;i++){
		K[i] = add(D[i], D[i - 1]);
		K[i] = add(K[i], K[i - 1]);
	}
}

int main(){
	precompute();
	int T; scanf("%d", &T);
	for(;T--;){
		int n, m; scanf("%d%d", &n, &m);
		if(n > m) swap(n, m);
		printf("%d\n", add(mul(m - n, D[n]), K[n]));
	}
	return 0;
}