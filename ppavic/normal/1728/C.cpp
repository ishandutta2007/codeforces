#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
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

int log10(int x){
	int ret = 0;
	while(x){
		x /= 10; ret++;
	}
	return ret;
}

priority_queue < int > A, B;

void solve(){
	int n; scanf("%d", &n);
	for(int i = 0;i < n;i++){
		int x; scanf("%d", &x);
		A.push(x);
	}
	for(int i = 0;i < n;i++){
		int x; scanf("%d", &x);
		B.push(x);
	}
	int ans = 0;
	while(!A.empty()){
		if(A.top() == B.top()){
			A.pop(); B.pop();
		}
		else if(A.top() > B.top()){
			int x = log10(A.top());
			A.pop(); A.push(x);
			ans++;
		}
		else{
			int x = log10(B.top());
			B.pop(); B.push(x);	
			ans++;
		}
	}
	printf("%d\n", ans);
}

int main(){
	int T; scanf("%d", &T);
	for(;T--;) solve();
	return 0;
}