#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef vector < int > vi;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int LOG = 20;
const int OFF = (1 << 18);
const int MOD = 998244353;

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

int n, k, v[M];

void solve(){
	scanf("%d%d", &n, &k);
	for(int i = 0;i < n;i++)
		scanf("%d", v + i);
	int sol = 1;
	for(int j = 1;j <= k;j++){
		sol = mul(sol, j);
		if(v[n - j] == -1) v[n - j] = 0;
		if(v[n - j]){
			printf("0\n");
			return;
		}
	}
	for(int i = 0;i < n - k;i++){
		if(v[i] == -1) sol = mul(sol, i + k + 1);
		else if(!v[i]) sol = mul(sol, k + 1);	
	}
	printf("%d\n", sol);
}

int main(){
	int T; scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}