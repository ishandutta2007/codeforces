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



#define oo 					(int)13e7
#define s(n)					scanf("%d",&n)
#define sl(n) 					scanf("%lld",&n)
#define sf(n) 					scanf("%lf",&n)
#define fill(a,v) 				memset(a, v, sizeof a)
#define ull 					unsigned long long
#define ll 						long long
#define bitcount 			__builtin_popcount
#define all(x) 				x.begin(), x.end()
#define pb( z ) 				push_back( z )
#define gcd					__gcd
using namespace std;


int x[ (int)1e5+7 ];
int main()
{
	int n, vs, vb;
	s(n); s(vb); s(vs);
	
	
	
	for(int i=0; i < n; i++)
	{
		s( x[i] );
	}
	int xu, yu;
	s( xu ); s( yu );
	double best = 1e40;
	double best2 = 1e40;
	int p = 0;
	for(int i=1; i < n; i++)
	{
		int &xi = x[i];
		double cur = xi/(0.+vb) + hypot( xi-xu, yu )/vs;
		double d2 = hypot( xi-xu, yu );
		
		if( ( fabs( cur - best ) < 1e-9 && d2 < best2 ) || ( cur < best ) )
		{
			best = cur;
			best2 = d2;
			p = i;
		}
	}
	
	printf("%d\n", p+1 );
	//cout<< best << endl;
	
	
	
	
	return 0;
}