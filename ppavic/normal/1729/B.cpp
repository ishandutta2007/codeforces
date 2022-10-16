#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <iostream>
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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int Ts; cin >> Ts;
    for(;Ts--;){
        string s; stack < char > T;
        int len; cin >> len;
        for(;len--;){
            char _c; cin >> _c; T.push(_c);
        }
        for(;!T.empty();){
            char c = T.top(); T.pop();
            if(c == '0'){
                int a1 = T.top(); T.pop();
                int a2 = T.top(); T.pop();
                s.PB('a' + (a1 - '0') + 10 * (a2 - '0') - 1);
            }
            else{
                s.PB('a' + (c - '0') - 1);
            }
        }
        reverse(s.begin(), s.end());
        cout << s << '\n';
    }
	return 0;
}