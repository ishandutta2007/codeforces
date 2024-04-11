#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef pair < ll, ll > pll;

const int N = 2e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int OFF = (1 << 18);

inline int mul(int A, int B){
	return (ll)A * B % MOD;
}

inline int poot(int A, int B){
	int ret = 1, bs = A;
	for(; B ; B >>= 1){
		if(B & 1) ret = mul(ret, bs);
		bs = mul(bs, bs);
	}
	return ret;
}

int sm[N], sve = 1, n, q;
map < int , int > kol[N], ja[N];

void ubaci(int x, int pot, int i){
//	printf("UBACUJEM %d ^ %d na %d\n", x, pot, i);
	if(sm[x] == n){
		sve = mul(sve, poot(poot(x, kol[x].begin() -> X), MOD - 2));
	}
	if(ja[i][x] == 0){
		sm[x]++;
		kol[x][pot]++;
	}
	else{
		int st = ja[i][x];
		kol[x][st]--;
		if(!kol[x][st])
			kol[x].erase(st);
		kol[x][st + pot]++;
	}
	//printf("sm[ %d ] = %d\n", x, sm[x]);
	ja[i][x] += pot;
	if(sm[x] == n){
		sve = mul(sve, poot(x, kol[x].begin() -> X));	
	}	
}

void dodaj(int xx, int i){
	for(int x = 2;x * x <= xx;x++){
		if(xx % x) continue;
		int pot = 0;
		while(!(xx % x)){
			pot++, xx /= x;
		}
		ubaci(x, pot, i);
	}
	if(xx != 1)
		ubaci(xx, 1, i);
}

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 1;i <= n;i++){
		int x; scanf("%d", &x);
		dodaj(x, i);
	}
	for(;q--;){
		int x, i; scanf("%d%d", &i, &x);
		dodaj(x, i); printf("%d\n", sve);
	}
	return 0;
}