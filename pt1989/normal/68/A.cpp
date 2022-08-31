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
int p[8],a,b;
int main(int argc, char** argv) {
	for( int i=0 ;i  <4; i++) cin>>p[i];
	cin>>a>>b;
	int ans = 0;
	for (int x=a; x <= b; x++) {
		int perms = 0;
		sort(p, p+4);
		do {
			int v = (( ( x % p[0] ) % p[1] ) % p[2]) % p[3];
			if (v==x) {
				perms++;
			}
		} while (next_permutation(p, p+4));
		if (perms >= 7) ans++;
	}
	cout << ans << endl;
	
	return 0;
}