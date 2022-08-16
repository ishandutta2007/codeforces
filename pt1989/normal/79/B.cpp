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

int n,m,k,t;

int wx[1024], wy[1024];

string fruits[] = {"Carrots", "Kiwis", "Grapes"};
int main(int argc, char** argv) {
	s(n); s(m); s(k); s(t);
	FOR(i, k) { s(wx[i]); s(wy[i]); }
	
	FOR(xx, t) {
		int xi, yi;
		s(xi); s(yi);
		bool waste = 0;
		int less = (xi-1)*m + yi;
		FOR(i, k) {
			if (wx[i] == xi && wy[i] == yi) {
				waste = 1; break;
			}
			if (wx[i] < xi || (wx[i] == xi && wy[i] < yi)) {
				less--;
			}
		}
		
		if (waste) {
			puts("Waste");
			continue;
		}
		less = (less - 1 + 300000)%3;
		puts(fruits[ less%3 ].c_str());
		
		
	}
	
	return 0;
}