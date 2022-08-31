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
const int mxn = 10007;
int a[mxn];
int n;
double k;
double x[mxn];

bool solve(double z) {
	double pos = 0, neg = 0;
	for (int i=0; i < n; i++)
		if (a[i] > z) {
			pos += a[i] - z;
		} else {
			neg += z - a[i];
		}
	
	return pos*(1-k) >= neg;
}
int main(int argc, char** argv) {
	s(n); cin>>k;
	k = k/100.;
	for (int i=0; i < n; i++) s(a[i]);
	sort(a, a+n); reverse(a, a+n);
	double lo = 0, hi = a[0] + 1e-9;
	for (int its=0; its < 70; its++) {
		double mid = (lo+hi)/2;
		if (solve(mid)) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	printf("%.12lf\n", (lo+hi)/2);
	return 0;
}