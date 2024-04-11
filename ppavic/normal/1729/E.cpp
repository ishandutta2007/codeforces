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

const int N = 1e5 + 500;
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

int main(){
    ll x, y;
    for(int i = 0;i < 25;i++){
        printf("? 1 %d\n", i + 2); fflush(stdout);
        scanf("%lld", &x);
        printf("? %d 1\n", i + 2); fflush(stdout);
        scanf("%lld", &y);
        if(x == -1 || y == -1){
            printf("! %lld\n", (ll)(i + 1));
            fflush(stdout);
            return 0;
        }
        if(x != y){
            printf("! %lld\n", x + y);
            fflush(stdout);
            return 0;
        }
    }
    printf("! %lld\n", x + y);
    fflush(stdout);
	return 0;
}