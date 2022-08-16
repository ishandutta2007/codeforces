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

int a[8][8];

void add(int i,int j, int w) {
	w = min(w, a[i][j]);
	a[i][j] = a[j][i] = w;
}

bool liesOn(int lo, int hi, int v) {
	if (lo > hi) swap(lo, hi);
	return lo <= v && v <= hi;
}
int dist(int x0, int y0, int x1, int y1) {
	return abs(x0-x1) + abs(y0-y1);
}
int main(){
	
	int n, x1, y1, x2, y2;
	cin>>n>>x1>>y1>>x2>>y2;
	
	
	for (int i=0; i < 6; i++)
	for (int j=0; j < 6; j++)
	a[i][j] = i==j ? 0 : (int)1e6;
	
	int x[] = {0,0,n,n};
	int y[] = {0,n,n,0};
	
	
	for (int i=0; i < 4; i++) {
		int j = (i+1)%4;
		add(i, j, n);
		
		int mask = 0;
		if (liesOn(x[i], x[j], x2) && liesOn(y[i], y[j], y2)) {
			add(i, 4, dist(x[i], y[i], x2, y2));
			add(j, 4, dist(x[j], y[j], x2, y2));
			mask |= 1;
		}
		if (liesOn(x[i], x[j], x1) && liesOn(y[i], y[j], y1)) {
			add(i, 5, dist(x[i], y[i], x1, y1));
			add(j, 5, dist(x[j], y[j], x1, y1));
			mask |= 2;
		}
		if (mask==3) {
			add(4,5, dist(x1,y1,x2,y2));
		}
		
		
	}
	
	
	
	for (int k=0; k < 6; k++)
	for (int i=0; i < 6; i++)
	for (int j=0; j < 6; j++)
	a[i][j] = min( a[i][j] , a[i][k] + a[k][j] );
	
	
	
	cout << a[4][5] << endl;
	
	
	return 0;
}