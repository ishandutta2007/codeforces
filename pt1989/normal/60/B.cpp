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
const int mxn = 12;

char a[mxn][mxn][mxn];
bool v[mxn][mxn][mxn];
int k, n, m;


int solve(int x, int y, int z) {
	if (x < 0 || y < 0 || z < 0) return 0;
	if (x >= k || y >= n || z >= m) return 0;
	if (a[x][y][z] == '#') return 0;
	if (v[x][y][z]) return 0;
	v[x][y][z] = 1;
	int ret = 1;
	for (int dx=-1; dx <= 1; dx++)
	for (int dy=-1; dy <= 1; dy++)
	for (int dz=-1; dz <= 1; dz++)
	if (dx*dx + dy*dy + dz*dz == 1)
		ret += solve(x+dx, y+dy, z+dz);
	return ret;
}

int main(int argc, char** argv) {
	s(k); s(n); s(m);
	for (int i=0; i < k; i++)
	for (int x=0; x < n; x++)
		scanf("%s", a[i][x]);
	int tx, ty;
	s(tx); s(ty);
	
	cout << solve(0,tx-1,ty-1) << endl;
	
	return 0;
}