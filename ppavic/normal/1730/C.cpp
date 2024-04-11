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

const int N = 2e5 + 500;
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

char s[N];
int n, izb[N];;
vector < int > vis;
vector < int > grad;

void solve(){
	scanf("%s", s);
	n = strlen(s);
	for(int i = 0;i < n;i++){
		s[i] -= '0'; izb[i] = 0;
	}
	for(int zn = 0;zn < 10;zn++){
		int zad = -1;
		for(int i = n - 1;i >= 0;i--){
			if(izb[i]) continue;
			if(s[i] == zn){
				zad = i; break;
			}
		}
		for(int i = 0;i < zad;i++){
			if(izb[i]) continue;
			if(s[i] > zn){
				izb[i] = 1;
				vis.PB(min(s[i] + 1, 9));
			}
		}
	}
	sort(vis.begin(), vis.end());
	int j = 0;
	for(int i = 0;i < n;i++){
		if(izb[i]) continue;
		while(j < (int)vis.size() && vis[j] <= s[i]){
			printf("%d", vis[j++]);
		}
		printf("%d", s[i]);
	}
	while(j < (int)vis.size()){
		printf("%d", vis[j++]);
	}
	printf("\n");
	vis.clear();
}

int main(){
	int T; scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}