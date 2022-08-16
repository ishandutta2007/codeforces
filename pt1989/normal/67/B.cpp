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
int n, k;
int a[mxn];

int main(int argc, char** argv) {
	s(n); s(k);
	priority_queue< int, vector<int>, greater<int> > q;
	for (int i=1; i <= n; i++) {
		s(a[i]);
		if (a[i] == 0) {
			q.push( i );
		}
	}
	int printed = 0;
	while (q.size() > 0) {
		int z = q.top(); q.pop();
		printf("%d", z);
		if (++printed == n) {
			puts("");
		} else {
			printf(" ");
		}
		
		int hi = z-k;
		for (int i=1; i <= hi; i++) {
			if (--a[i] == 0) {
				q.push( i );
			}
		}
		
	}
	
	
	return 0;
}