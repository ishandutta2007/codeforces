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

int a[1024], n;

int main(){
	s(n);
	int sum = 0;
	for (int i=0; i < n; i++) { s(a[i]); sum += a[i]; }
	sort( a, a+n );
	
	int maxHeight = 0;
	int number = 0;
	
	for (int i=0; i < n; ) {
		int j = i;
		int curHeight = 0;
		while ( j < n && a[j] == a[i] ) {
			j++;
			curHeight ++;
			
		}
		i = j;
		number++;
		maxHeight = max(maxHeight, curHeight);
	}
	printf("%d %d\n", maxHeight, number);
	
	return 0;
}