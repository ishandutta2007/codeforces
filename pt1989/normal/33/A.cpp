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

int V[1024];

int main(){
	int n, m, k;
	cin>>n>>m>>k;
	const int INF = (int)2e9;
	for (int i=1; i <= m; i++)
		V[i] = INF;
	
	while (n--) {
		int r, c;
		s(r); s(c);
		V[r] = min(V[r], c);
	}
	int sol = 0;
	for (int i=1; i <= m; i++) {
		if (V[i] != INF) {
			sol += V[i];
		}
		
	}
	
	sol = min(sol, k);
	
	cout << sol << endl;
	
	return 0;
}