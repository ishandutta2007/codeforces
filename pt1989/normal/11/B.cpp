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

void bf()
{
	int moves[256];
	for(int i=0; i < 256; i++) moves[i] = (int)2e9;
	for(int n=1; n <= 10; n++)
	for(int i=0; i < (1<<n); i++)
	{
		int cval = 0;
		for(int j=0; j < n; j++)
		if( i & 1<<j )
			cval += j+1;
		else
			cval -= j+1;
		if( cval >= 0 )
			moves[ cval ] = min( n, moves[cval] );
	}
	for(int i=1; i <= 30; i++)
	cout<< moves[i] << " "; cout << endl;
}
ll t( ll x )
{
	return ( x*(x+1LL) )/ 2;
}
int main()
{
	int n;
	cin>>n;
	n = abs( n );
	if( n== 0 )
	{
		cout<< 0 << endl;
		exit( 0 );
	}
	for(int k=1; ; k++)
	if( t(k) <= n && n < t(k+1) )
	{
		int sol = 0;
		if( n==t(k) )
			sol = k;
		else 
		{
			int diff = n-t(k);
			if( k&1 )
			{
				if( diff&1 )
					sol = k+2;
				else
					sol = k+1;
			}
			else
			{
				if( diff&1 )
					sol = k+1;
				else
					sol = k+3;
			}
		}
		
		cout<< sol << endl;
		
		exit( 0 );
	}
	return 0;
}