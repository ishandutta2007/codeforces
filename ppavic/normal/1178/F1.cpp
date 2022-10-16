#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < ll > vl;
typedef pair < pii, int > ppi;
typedef pair < int, pii > pip;
typedef long double ld;

const int N = 505;
const int M = 1e6 + 500;
const int LOG = 20;
const int OFF = (1 << LOG);
const int MOD = 998244353;
const ld PI = 3.1415926535;
const ld EPS = 1e-9;

int nw[N][N], ol[N][N], L[N], R[N], c[N], inv[N], n, m;

int get(int x,int y){
	if(x > y) return 1;
	return ol[x][y];
}

int main(){
	memset(L, -1, sizeof(L));
	memset(R, -1, sizeof(R));
	scanf("%d%d", &n, &m);
	for(int i = 0;i < n;i++)
		scanf("%d", c + i), inv[c[i]] = i;
	for(int i = 0;i < n;i++)
		for(int j = i;j < n;j++)
			ol[i][j] = 1;
	for(int k = n;k >= 1;k--){	

		memset(L, 0, sizeof(L));
		memset(R, 0, sizeof(R));

		int pos = inv[k], got = 0;

		L[pos] = 1, R[pos] = 1;
		for(int i = pos - 1;i >= 0;i--){
			for(int j = i;j >= 0;j--){
				L[j] += ((ll)get(j, i) * get(i + 1, pos - 1)) % MOD;
				L[j] %= MOD;
			}
			L[i] += get(i, pos - 1);
			L[i] %= MOD;
			if(c[i] < k) got = 1;
			if(got) L[i] = 0;
		}
		got = 0;
		for(int i = pos + 1;i < n;i++){
			for(int j = i;j < n;j++){
				R[j] += ((ll)get(i, j) * get(pos + 1, i - 1)) % MOD;
				R[j] %= MOD;
			}
			R[i] += get(pos + 1, i);
			R[i] %= MOD;
			if(c[i] < k) got = 1;
			if(got) R[i] = 0;
		}

		for(int i = 0;i <= pos;i++)
			for(int j = pos;j < n;j++)
				ol[i][j] = (ll)L[i] * R[j] % MOD;

		
	}
	printf("%d\n", ol[0][n - 1]);
	return 0;
}