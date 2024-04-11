//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int LOG = 18;
const int OFF = (1 << LOG);
const int MOD = 1e9 + 7;

uint dp[65][3];
ll m;

inline uint add(uint A, uint B){
	if(A + B >= MOD)
		return A + B - MOD;
	return A + B;
}

inline uint mul(uint A, uint B){
	return A * B % MOD;
}

int ch[4][4];

void solve(){
	memset(dp, 0, sizeof(dp));
	scanf("%lld", &m);
	dp[0][0] = 1;
	for(int i = 0;i < 60;i++){
		int trz = !!(m & (1LL << i));
		for(int ost = 0;ost < 3;ost++){
			if(dp[i][ost] == 0)
				continue;
			if(i > 1){
				for(int j = (trz + ost) % 2;j <= 3;j += 2){
					dp[i + 1][(ost + j) / 2] = add(dp[i + 1][(ost + j) / 2], mul(dp[i][ost], ch[3][j]));
				}
			}
			if(i == 1){
				for(int j = (trz + ost) % 2;j <= 2;j += 2){
					dp[i + 1][(ost + j) / 2] = add(dp[i + 1][(ost + j) / 2], mul(dp[i][ost], ch[2][j]));
				}
			}
			if(i == 0){
				for(int j = (trz + ost) % 2;j <= 1;j += 2){
					dp[i + 1][(ost + j) / 2] = add(dp[i + 1][(ost + j) / 2], mul(dp[i][ost], ch[1][j]));
				}
			}
		}
	}
	printf("%d\n", dp[60][0]);
}

int main(){
	ch[1][0] = 1, ch[1][1] = 1;
	ch[3][0] = 1, ch[3][3] = 1, ch[3][1] = 3, ch[3][2] = 3;
	ch[2][0] = 1, ch[2][2] = 1, ch[2][1] = 2;
	int T; scanf("%d", &T);
	for(;T--;) solve();
	
	return 0;
}