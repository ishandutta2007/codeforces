//DS includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<bitset>
#include<complex>

//Other Includes
#include<sstream>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>

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

const int mxn = 303;
char z[mxn][mxn];
int a[mxn][mxn];
void print(int x, int y) {
	printf("%d %d\n", x+1, y+1);
}
int main(){
	int n, m, k;
	cin>>n>>m>>k;
	for(int i=0; i < n; i++) {
		scanf("%s", z[i]);
	}
	for(int i=0; i < n; i++)
	for(int j=0; j < m; j++)
	a[i][j] = z[i][j] == '*';
	
	bool done = false;
	int lim = min(n,m)/2;
	for(int r=1; r <= lim; r++) {
		for (int x=r; x+r < n; x++) 
		for (int y=r; y+r < m; y++)
		{
			char c = a[x][y] & a[x+r][y] & a[x-r][y] & a[x][y+r] & a[x][y-r];
			if (c) {
				if (--k == 0) {
					done = true;
					print(x,y);
					print(x-r,y);
					print(x+r,y);
					print(x,y-r);
					print(x,y+r);
					x = y = r = (int)1e9;
					break;
				}
			}
		}
	}
	
	if (!done)
		cout << -1 << endl;
	
	
	return 0;
}