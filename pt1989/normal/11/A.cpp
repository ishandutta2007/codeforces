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



int main()
{
	ll a[2048];
	int n, d;
	s( n ); s( d );
	for(int i=0; i < n; i++)
	{
		cin>>a[i];
	}
	ll ans = 0;
	for(int i=1; i < n; i++)
	{
		if( a[i] <= a[i-1] )
		{
			ll diff = a[i-1] - a[i] + 1;
			ll moves = diff / d;
			if( diff%d != 0 )
				moves++;
			//cout<< a[i] << " " << a[i-1] << " = " << moves << endl;
			a[i] += moves*d;
			ans += moves;
		}
	}
	cout<< ans << endl;
	
	
	return 0;
}