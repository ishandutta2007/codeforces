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

int n;
char s[N];
vector < pii > pos;

void solve(){
    scanf("%s", s); n = strlen(s); 
    pos.clear();
    if(s[0] > s[n - 1])
        for(int i = 0;i < n;i++)
            s[i] = 'a' + (26 - (s[i] - 'a'));
    for(int i = 0;i < n;i++){
        if(s[i] >= s[0] && s[i] <= s[n - 1])
            pos.PB({s[i] - 'a', i});
    }
    sort(pos.begin(), pos.end());
    printf("%d %d\n", s[n - 1] - s[0], (int)pos.size());
    for(pii &tmp : pos) printf("%d ", tmp.Y + 1);
    printf("\n");
}   

int main(){
    int T; scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}