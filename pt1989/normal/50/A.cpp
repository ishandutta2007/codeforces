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

int solve(int x, int y) {
	return (x/2)*y + (y/2);
}

int main(){
	int n, m;
	cin>>n>>m;
	
	int ans = 0;
	if (n%2 == 0) {
		ans = (n/2)*m;
	} else if (m%2 == 0) {
		ans = (m/2)*n;
	} else {
		ans = max( solve(n,m), solve(m,n) );
	}
	cout << ans << endl;
	return 0;
}