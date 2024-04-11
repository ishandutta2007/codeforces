#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
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

const int N = 505;
const int M = 1e6 + 500;
const int ALP = 30;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

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

string s, t;
int n, m, dp[N][N], bas[N][N];

void solve(){
	cin >> s >> t;
	n = (int)s.size(), m = (int)t.size();
	vector < int > v;
	for(int i = 0;i + m <= n;i++){
		if(s.substr(i, m) == t) 
			v.PB(i);
	}
	if((int)v.size() == 0){
		cout << "0 1\n";
		return;
	}
	for(int i = 0;i < n;i++) dp[i][0] = 0;
	for(int len = 1;len <= n;len++){
		for(int i = 0;i < (int)v.size();i++){
			int j = i - 1; dp[i][len] = 0; bas[i][len] = 0;
			while(j >= 0 && v[i] - v[j] < m){
				dp[i][len] = add(dp[i][len], bas[j][len]); j--;
			}
			if(j < 0){
				dp[i][len] = add(dp[i][len], (len == 1));
				bas[i][len] = (len == 1);
			}
			else{
				dp[i][len] = add(dp[i][len], dp[j][len - 1]);
				bas[i][len] = dp[j][len - 1];
			}
			if(!dp[i][len]) continue;
		}
	}
	int naj = 0;
	while(!dp[(int)v.size() - 1][naj]) naj++;
	cout << naj << ' ' << dp[(int)v.size() - 1][naj] << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T; cin >> T;
	for(;T--;) solve();
	return 0;
}