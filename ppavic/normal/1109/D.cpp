#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < ll > vl;

const int N = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int LOG = 20;
const int MOD = 1e9 + 7;
const int BASE = 31337;

inline int add(const int &A, const int &B){
	if(A + B >= MOD) return A + B - MOD;
	return A + B;
}

inline int mul(const int &A, const int &B){
	return (ll)A * B % MOD;
}

inline int pot(const int &A, int B){
	int res = 1, cur = A;
	for(;B;B >>=1){
		if(B & 1) res = mul(res, cur);
		cur = mul(cur, cur);
	}
	return res;
}

int fak[N], inv[N], n, m;

inline int choose(int n,int k){
	return mul(fak[n], mul(inv[k], inv[n - k]));
}

void precompute(){
	fak[0] = 1, inv[0] = 1;
	for(int i = 1;i < N;i++){
		fak[i] = mul(i, fak[i - 1]);
		inv[i] = pot(fak[i], MOD - 2);
	}
}

int main(){
	precompute();
	scanf("%d%d", &n, &m);
	int sol = 0;
	for(int k = 1;k <= n - 1 && k <= m;k++){
		int br_st = mul(mul(choose(n - 1, k), pot(n, n - k - 1)), fak[k + 1]);
		int br_boj = mul(choose(m - 1, k - 1), pot(m, n - 1 - k));
		sol = add(sol, mul(br_st, br_boj));
		//printf("+= %d * %d\n", broj_stabala, broj_bojanja);
	}
	sol = mul(sol, pot(n, MOD - 2));
	sol = mul(sol, pot(n - 1, MOD - 2));
	printf("%d\n", sol);
	return 0;
}