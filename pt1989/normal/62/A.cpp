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

int gl, gr, bl, br;

int dp[102][102][4][4];
bool ok(int g, int b, int p1, int p2) {
	if (g < 0 || b < 0) return 0;
	if (g==0 && b==0) return 1;
	int &ret = dp[g][b][p1][p2];
	if (~ret) return ret;
	ret = 0;
	if (p1 == 0 && p2==0);
	else ret |= ok(g, b-1, p2, 0); 
	if (p2==1);
	else ret |= ok(g-1, b, p2, 1);
	return ret;
}

int main(int argc, char** argv) {
	fill(dp, -1);
	cin>>gl>>gr>>bl>>br;
	bool ans = ok(gl, br,2,2) || ok(gr, bl,2,2);
	puts( ans ? "YES" : "NO" );
	return 0;
}