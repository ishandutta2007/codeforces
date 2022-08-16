//DS includes
#include<bitset>
#include<complex>
#include<deque>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>



//Other Includes
#include<algorithm>
#include<cassert>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<iostream>
#include<sstream>




#define oo 				0xBADC0DE
#define s(n)			scanf("%d",&n)
#define sl(n) 			scanf("%lld",&n)
#define sf(n) 			scanf("%lf",&n)
#define fill(a,v) 		memset(a, v, sizeof a)
#define ull 			unsigned long long
#define ll 				long long
#define bitcount 		__builtin_popcount
#define all(x) 			x.begin(), x.end()
#define pb( z ) 		push_back( z )
#define gcd				__gcd
using namespace std;

const ll mod = (int)1e9 + 7;
const int mxn = 102;
int x[mxn], y[mxn], n;
int sum[mxn];
/*
int cbf(int n, int k) {
	if (k==0) return 1;
	if ( k > n ) return 0;
	return cbf(n-1,k-1) + cbf(n-1,k);
}*/


ll modInv(ll N) {
	ll r = 1;
	ll pw = mod-2;
	
	while ( pw > 0 ) {
		if (pw&1) {
			r = (r*(ll)N) % mod;
		}
		N = (N*(ll)N) % mod;
		pw >>= 1;
	}
	return r;
}
ll F[mxn*mxn];
ll Fi[mxn*mxn];
ll C(int N, int K) {
	if ( K > N ) return 0;
	ll R = F[N];
	R *= Fi[K];
	R %= mod;
	R *= Fi[N-K];
	R %= mod;
	return R;
}

ll dp[mxn][mxn*12];
ll solve(int p, int extra) {
	
	if (p==n) {
		return extra==0;
	}
	ll &R = dp[p][extra];
	if ( R != -1 ) {
		return R;
	}
	int current= x[p] + extra;
	
	
	
	ll &ret = R;
	ret = 0;
	
	for (int place=0; place <= current && place <= y[p]; place++) {
		ret += C(current, place)*(ll)solve(p+1, current-place);
		ret %= mod;
	}
	
	
	int N = sum[n-1] - (p ? sum[p-1] : 0);
	int K = x[p];
	
	ret *= C(N,K);
	ret %= mod;
	
	return ret;
}

int main(){
	
	F[0] = Fi[0] = 1;
	
	for (int i=1; i < mxn*mxn; i++) {
		F[i] = (F[i-1]*(ll)i)%mod;
		Fi[i] = modInv(F[i]);
		if ( i < 10 ) {
			//cout << F[i] << " " << Fi[i] << " = " <<(( F[i]*(ll)Fi[i]) % mod) << endl;
		}
	}
	fill(dp, -1);
	
	s(n);
	for (int i=0; i < n; i++) s(x[i]);
	for (int i=0; i < n; i++) s(y[i]);
	
	sum[0] = x[0];
	for (int i=1; i < n; i++) sum[i] = sum[i-1] + x[i];
	
	cout << solve(0,0) << endl;
	return 0;
}