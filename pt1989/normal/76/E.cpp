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
const int mxn = 100007;
int x[mxn], y[mxn], n;
ll solve(int *a) {
	ll sum = 0, sumsq = 0;
	ll ans = 0;
	for (int i=0; i < n; i++) {
		
		ll curSq = a[i]*a[i];
		ll cum = curSq * i;
		cum += sumsq;
		cum -= 2*sum*a[i];
		
		ans += cum;
		
		sum += a[i];
		sumsq += curSq;
	}
	return ans;
}
int main(int argc, char** argv) {
	s(n);
	for (int i=0; i < n; i++) {
		s(x[i]); s(y[i]);
	}
	sort(x, x+n); sort(y, y+n);
	
	cout << solve(x) + solve(y) << endl;
	
	return 0;
}