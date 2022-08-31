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


int a[32], b[32], v, n;

int main(){
	cin>>n>>v;
	for (int i=0; i < n; i++) cin>>a[i];
	for (int i=0; i < n; i++) cin>>b[i];
	
	double lo = 0, hi = 1e9;
	for (int its=0; its < 100; its++) {
		double x = (lo+hi)/2;
		bool ok = 1;
		double tv = 0;
		for (int i=0; i < n; i++) 
		{
			tv += a[i]*x;
			if (a[i]*x > b[i]) {
				ok = 0;
			}
		}
		if (ok && tv <= v) {
			lo = x;
		} else {
			hi = x;
		}
	}
	double x = (lo+hi)/2;
	double tv = 0;
	for (int i=0; i < n; i++) 
			tv += a[i]*x;
	cout.precision(20);
	cout<< tv << endl;
	return 0;
}