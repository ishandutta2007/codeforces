//      hello world


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

#define oo 			0xBADC0DE
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

#define FOR(i,n) for (int i=0; i < (n); i++)

using namespace std;
const int mxn = 1024;
int a[mxn];
int n;
int dp[mxn][mxn];
int solve(int p, int prev) {
	if (p > n) {
		return a[prev];
	}
	int p0 = prev, p1 = p, p2 = p+1;
	if (p2 > n) {
		return max( a[p0], a[p1] );
	}
	int &ret = dp[p][prev];
	if (~ret)
		return ret;
		
	ret = 			max( a[p0], a[p1] ) + solve(p+2, p2);
	ret = min(ret, 	max( a[p1], a[p2] ) + solve(p+2, p0) );
	ret = min(ret, 	max( a[p0], a[p2] ) + solve(p+2, p1) );
	
	return ret;
}

void recon(int p, int prev) {
	if (p > n) {
		cout << prev << endl;
		return;
	}
	int p0 = prev, p1 = p, p2 = p+1;
	if (p2 > n) {
		cout <<p0 << " " << p1 << endl;
		return;
	}
	int real = solve(p, prev);
	
	int ret = 		max( a[p0], a[p1] ) + solve(p+2, p2);   
	if (ret==real) { cout << p0 << " " << p1 << endl; return recon(p+2, p2); }
	ret = min(ret, 	max( a[p1], a[p2] ) + solve(p+2, p0) ); 
	if (ret==real) { cout << p1 << " " << p2 << endl; return recon(p+2, p0); }
	ret = min(ret, 	max( a[p0], a[p2] ) + solve(p+2, p1) ); 
	if (ret==real) { cout << p0 << " " << p2 << endl; return recon(p+2, p1); }
}

int main(int argc, char** argv) {
	
	s(n);
	for (int i=1; i <= n; i++) {
		s( a[i] );
	}
	
	if (n == 1) {
		cout << a[1] << endl;
		cout << 1 << endl;
	} else {
		fill( dp, -1 );
		cout << solve(2, 1) << endl;
		recon(2, 1);
	}
	
	
	return 0;
}