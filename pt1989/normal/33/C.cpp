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

const int mxn = (int)1e5 + 7;
int a[mxn];
int dp[mxn][3];

int main(){
	int n;
	s(n);
	
	const int INF = (int)2e9;
	
	for(int i=0; i < n; i++) s(a[i]);
	
	for (int st=2; st >= 0; st--)
		dp[n][st] = 0;
	
	for (int p=n-1; p >= 0; --p) {
		for(int st=2; st >= 0; st--) {
			int &d = dp[p][st];
			d = -INF;
			if (st < 2) {
				d = max( d, dp[p][st+1] );
			}
			
			int cur = st == 1 ? a[p] : -a[p];
			
			d = max( d, cur + dp[p+1][st] );
			
		}
	}
	
	printf("%d\n", dp[0][0] );
	
	return 0;
}