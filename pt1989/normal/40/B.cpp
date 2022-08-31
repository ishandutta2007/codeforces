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

int go(int n, int m, int x) {
	if (n <= 0 || m <= 0) 
		return 0;
	if (x==0) {
		int ret = 0;
		
		for (int i=1; i <= n; i++)
		for (int j=1; j <= m; j++)
		if ( i==1 || i==n || j==1 || j==m ) {
			if ( i%2 == j%2 ) {
				ret++;
			}
		}
		//cout << n << " " << m << endl;
		return ret;
	}
	
	return go(n-2, m-2, x-1);
}

int main(){
	int n, m, x;
	cin>>n>>m>>x;
	
	cout << go(n,m,x-1) << endl;
	
	return 0;
}