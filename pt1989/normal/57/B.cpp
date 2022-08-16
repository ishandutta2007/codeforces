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
int n, m, k;
const int mxn = (int)1e5 + 7;
int lo[mxn], hi[mxn], x[mxn];
int main(){
	
	s(n); s(m); s(k);
	for (int i=0; i < m; i++) {
		s(lo[i]); s(hi[i]); s(x[i]);
	}
	ll ans = 0;
	for (int i=0; i < k; i++) {
		int p; s(p);
		
		for (int i=0; i < m; i++)
		if (lo[i] <= p && p <= hi[i]) {
			int offset = p - lo[i];
			ans += offset + x[i];
		}
		
	}
	cout << ans << endl;
	return 0;
}