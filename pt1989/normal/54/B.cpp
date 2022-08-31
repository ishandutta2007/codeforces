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

char a[32][32];

char z[32][32];

string rep(char a[32][32], int h, int w, int rots=3) {
	char b[32][32];
	string ret;
	for (int i=0; i < h; i++) {
		for (int j=0; j < w; j++)
			ret += a[i][j];
		ret += ".";
	}
	
	for (int i=0; i < h; i++)
	for (int j=0; j < w; j++)
			b[j][h-i-1] = a[i][j];
	if (--rots < 0) return ret;
	return min(ret, rep(b, w, h, rots));
	
}


int main(){
	int n, m;
	cin>>n>>m;
	for( int i=0; i < n; i++)
	cin>>a[i];
	
	int ans = 0;
	int best = n*m;
	int sx = n;
	for (int x=1; x <= n; x++)
	if (n%x == 0)
	for (int y=1; y <= m; y++)
	if (m%y == 0) {
		
		set<string> uniq;
		bool good = 1;
		for (int xo=0; xo < n; xo += x)
		for (int yo=0; yo < m; yo += y) {
			for (int xi=0; xi < x; xi++)
			for (int yi=0; yi < y; yi++)
				z[xi][yi] = a[xi+xo][yi+yo];
			string cur = rep(z, x, y);
			if (uniq.count(cur)) {
				good = 0;
				xo = yo = n;
				break;
			}
			
			uniq.insert( cur );
		}
		if (good) {
			ans++;
			int area = x*y;
			if (area < best || (area==best && x < sx)) {
				best = area;
				sx = x;
			}
		}
	}
	printf("%d\n", ans);
	printf("%d %d\n", sx, best/sx);
	
	return 0;
}