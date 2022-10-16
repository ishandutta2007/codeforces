#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <ext/pb_ds/assoc_container.hpp>

#define X first
#define Y second
#define PB push_back

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair < int, int > pii;
typedef pair < int, ll > pil;
typedef pair < ll, int > pli;
typedef pair < ll, ll > pll;
typedef pair < pii, int > ppi;
typedef pair < int, pii > pip;
typedef long double ld;
typedef vector < int > vi;
typedef vector < ll > vl;

const int N = 2050;
const int M = 1e6 + 500;
const int ALP = 30;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353; // 1e9 + 7

inline int add(int A, int B) { if(A + B >= MOD) return A + B - MOD; return A + B; }
inline int sub(int A, int B) { if(A - B < 0) return A - B + MOD; return A - B; }
inline int mul(int A, int B) { return (ll)A * B % MOD; }

inline int pot(int A, int B){
	int ret = 1, bs = A;
	for(; B ; B >>= 1){
		if(B & 1) ret = mul(ret, bs);
		bs = mul(bs, bs);
	}
	return ret;
}

int dp[N][N], n;
char s[N];

int f(int l, int r){
	if(dp[l][r] != -1) return dp[l][r];
	if(l == r - 1){
		return s[l] == s[r] ? 2 : 1;
	}
	int L = 0, R = 0;
	{ // uzimam lijevo
		int op1 = 1, op2 = 1;
		op1 = f(l + 2, r);
		if(op1 == 2 && s[l] < s[l + 1]) op1 = 1;
		if(op1 == 2 && s[l] > s[l + 1]) op1 = 0;
		op2 = f(l + 1, r - 1);
		if(op2 == 2 && s[l] < s[r]) op2 = 1;
		if(op2 == 2 && s[l] > s[r]) op2 = 0;
		if(op1 == 1 && op2 == 1) L = 1;
		else if(op1 == 0 || op2 == 0) L = 0;
		else L = 2;
	}
	{
		int op1 = 1, op2 = 1;
		op1 = f(l, r - 2);
		if(op1 == 2 && s[r] < s[r - 1]) op1 = 1;
		if(op1 == 2 && s[r] > s[r - 1]) op1 = 0;
		op2 = f(l + 1, r - 1);
		if(op2 == 2 && s[l] > s[r]) op2 = 1;
		if(op2 == 2 && s[l] < s[r]) op2 = 0;
		if(op1 == 1 && op2 == 1) R = 1;
		else if(op1 == 0 || op2 == 0) R = 0;
		else R = 2;
	}
	if(L == 1 || R == 1) return dp[l][r] = 1;
	if(L == 0 && R == 0) return dp[l][r] = 0;
	return dp[l][r] = 2;
}

void solve(){
	scanf("%s", s);
	n = strlen(s);
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			dp[i][j] = -1;
	int ans = f(0, n - 1);
	if(ans == 1) printf("Alice\n");
	if(ans == 0) printf("Bob\n");
	if(ans == 2) printf("Draw\n");
}

int main(){
	int T; scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}