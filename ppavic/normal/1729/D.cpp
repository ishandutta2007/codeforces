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

int n, A[N], B[N];
multiset < int > S;

void solve(){
    S.clear();
    scanf("%d", &n);
    for(int i = 0;i < n;i++) scanf("%d", A + i);
    for(int i = 0;i < n;i++) scanf("%d", B + i);
    for(int i = 0;i < n;i++)
        S.insert(B[i] - A[i]);
    int sol = 0;
    for(;(int)S.size() > 0;){
        int mks = *S.rbegin();
        S.erase(S.lower_bound(mks));   
        if(S.lower_bound(-mks) != S.end()){
            sol++; S.erase(S.lower_bound(-mks));
        }
    }
    printf("%d\n", sol);
}

int main(){
    int T; scanf("%d", &T);
    for(;T--;) solve();
	return 0;
}