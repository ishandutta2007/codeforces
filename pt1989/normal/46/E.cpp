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

const int mxn = 1507;
int a[mxn][mxn];
ll dp[mxn][mxn];
bool vis[mxn][mxn];
int n, m;


ll solve(int row, int cprev) {
	if (row==n)
		return 0;
	if (cprev < 0 || cprev > m)
		return -(ll)1e18;
	ll &ret = dp[row][cprev];
	bool &vx = vis[row][cprev];
	if (vx)
		return ret;
	vx = 1;
	if (row&1) {
		ret = solve(row, cprev-1);
		if (cprev) {
			ret = max( ret, solve( row+1, cprev+1 ) + a[row][cprev] );
			//cout << row << " " <<  cprev << " to " << row+1 << " " << cprev+1 << endl;
		}
	} else {
		ret = solve( row, cprev+1 );
		if (cprev) {
			ret = max( ret, solve(row+1, cprev-1) + a[row][cprev] );
			//cout << row << " " <<  cprev << " to " << row+1 << " " << cprev-1 << endl;
		}
	}
	//cout << row << " " << cprev << " = " << ret << endl;
	return ret;
}

int main(){
	s(n); s(m);
	for (int i=0; i < n; i++) {
		for (int j=1; j <= m; j++) {
			s(a[i][j]);
		}
		//sort( a[i]+1, a[i]+m+1 );
		//reverse( a[i]+1, a[i]+m+1 );
		
		for (int j=1; j <= m; j++) a[i][j] += a[i][j-1];
		//for (int j=1; j <= m; j++)cout<< a[i][j] <<  " "; cout<<endl;
	}
	
	fill( dp, -1 );
	cout << solve(0,0) << endl;
	return 0;
}